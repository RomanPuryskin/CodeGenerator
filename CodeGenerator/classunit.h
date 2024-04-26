#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"


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

    static const std::vector< std::string > ACCESS_MODIFIERS;
    /* вектор строк (изменять мы его
     не собираемся, поэтому const, static - для всех объектов этого класса он будет одним,
     из за static выносим инициализацию за пределы класса)
     содержит содержимое enum только строки (все модификаторы доступа класса)*/

    explicit ClassUnit( const std::string& name):
    m_name( name ) {m_fields.resize( ACCESS_MODIFIERS.size() );}
    /* explicit - защита от неявного преобразования типов
    передаем ссылку на строку с именем name
    вектору m_fields, которые содержит другие векторы присваиваем размер вектора
    содержащего модификаторы доступа класса */


    /*std::shared_ptr - умный указатель (сам подчищает за собой память), несколько указателей
        могут оказывать на один объект*/

    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    /*передаем указатель на тип Unit
    и берем у него значение (с помощью &)*/

    std::string compile( unsigned int level = 0 ) const;
    /* в этом методе генерируется строка семантики(структуры) класса. Пишется название класса
    фигурные скобки и расставляются модификаторы доступа с двоеточием*/

private:
    std::string m_name; // название нашего класса
    using Fields = std::vector< std::shared_ptr< Unit > >; // вектор умных указателей на объекты
    //  типа Unit ( тут будут содержаться методы в каждом модификаторе доступа )
    std::vector< Fields > m_fields;
};


#endif // CLASSUNIT_H
