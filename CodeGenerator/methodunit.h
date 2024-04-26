#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"

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
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ):
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags = 0 )
    {
        m_body.push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_name; // имя функции
    std::string m_returnType; // тип который функция возвращает
    Flags m_flags; // здесь флаг используется для задания доп параметров для функции (из enum)
    std::vector< std::shared_ptr< Unit > > m_body; // для хранения тела функции
};

#endif // METHODUNIT_H
