#ifndef EXPLANATION_H
#define EXPLANATION_H

#include <memory>
#include <iostream>
#include <vector>

// абстрактный класс
class Unit {
public:
    using Flags = unsigned int; /*определили псевдоним для типа unsigned int (теперь можно создавать
    переменные * Flags variable = 0)
    флаги будем использовать для передачи модификаторов доступа или типа методов (флаги -
    просто порядковые номера)*/

    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags )
    {
        throw std::runtime_error( "Not supported" );
    }
    //функция генерирует часть кода , который соответствует содержимому
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    // функция которая генерирует строку из пробелов и возвращает ее,
    //количество пробелов зависит от вложенности текста (level)
    // будем использовать ее каждый раз когда печатаем строку кода
    virtual std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

//этот класс будет ответственным за создание семантики класса (название класса , модификаторы доступа)
class ClassUnit : public Unit
{
public:
    // перечисления ( каждому элементы сопоставляется свой порядковый номер )
    enum AccessModifier
    {
        PUBLIC,  // = 0
        PROTECTED, // = 1
        PRIVATE // = 2
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;// вектор строк (изменять мы его
    // не собираемся, поэтому const, static - для всех объектов этого класса он будет одним,
    // из за static выносим инициализацию за пределы класса)
    // содержит содержимое enum только строки (все модификаторы доступа класса)

    explicit/*защита от неявного преобразования типов*/ ClassUnit( const std::string& name
    /*передаем ссылку на строку с именем name*/ ):
    m_name( name ) {m_fields.resize( ACCESS_MODIFIERS.size() );}/* вектору m_fields, которые
    содержит другие векторы присваиваем размер вектора содержащего модификаторы доступа класса*/

    //std::shared_ptr - умный указатель (сам подчищает за собой память), несколько указателей
    // могут оказывать на один объект

    void add( const std::shared_ptr< Unit >& unit /* передаем указатель на тип Unit
    и берем у него значение (с помощью &) */, Flags flags )
    {
        /* в соотсветствующй модификатор доступа(флаг) , то есть в вектор с таким же порядковым
         номером (которые хранятся в m_fields) добавляем новый указатель на unit(то есть
        соотв модификатор добавляем метод( который передаем )*/
        if( flags < ACCESS_MODIFIERS.size() )
        {
            m_fields[ flags ].push_back( unit );
        }
    }

    /* в этом методе генерируется строка семантики(структуры) класса. Пишется название класса
    фигурные скобки и расставляются модификаторы доступа с двоеточием*/
    std::string compile( unsigned int level = 0 ) const
    {
        /* генерируется самая верхняя строка с именем класса и открвающейся скобочкой*/
        std::string result = generateShift( level ) + "class " + m_name + " {\n";

        for( size_t/*для корректного сравнивания
            с рамзером вектора*/ i = 0; i < ACCESS_MODIFIERS.size(); ++i )
        {
            /*если какой то модификатор мы не используем, то не отображаем ничего,
            связанное с ним*/
            if( m_fields[ i ].empty()  )
                continue;

            // для каждого типа модификатора поставим двоеточие
            result += ACCESS_MODIFIERS[ i ] + ":\n";

            /*проходимся по i вектору*/
            for( const auto& f : m_fields[ i ] )
            {
                //вызываем метод compile у класса MethodUnit (для отображения метода в каждом
                // модификаторе
                result += f/*std::shared_ptr<MethodUnit>*/->compile( level + 1 );
                //
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
private:
    std::string m_name; // название нашего класса
    using Fields = std::vector< std::shared_ptr< Unit > >; // вектор умных указателей на объекты
    //  типа Unit ( тут будут содержаться методы в каждом модификаторе доступа )
    std::vector< Fields > m_fields;
};

// инициализация вектора, которую вынесли
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };


// класс для создания методов (функций)
class MethodUnit : public Unit {
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags
                                                                           flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 )
    {
        m_body.push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level );
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_flags & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            // вызываем метод compile у класса PrintOperatorUnit для отображения тела функции
            result += b/* b = std::shared_ptr<MethodUnit>*/->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
private:
    std::string m_name; // имя функции
    std::string m_returnType; // тип который функция возвращает
    Flags m_flags; // здесь флаг используется для задания доп параметров для функции (из enum)
    std::vector< std::shared_ptr< Unit > > m_body; // для хранения тела функции
};

// этот класс отвечает за печать тела метода
class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};


std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
                                                              MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
                                               MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}

#endif // EXPLANATION_H
