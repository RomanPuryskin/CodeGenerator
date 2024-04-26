#ifndef UNIT_H
#define UNIT_H
#include <memory>

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

#endif // UNIT_H
