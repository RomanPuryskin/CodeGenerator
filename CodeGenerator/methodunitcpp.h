#ifndef METHODUNITCPP_H
#define METHODUNITCPP_H
#include "unit.h"

// класс для создания методов (функций)
class MethodUnitCpp : public Unit {
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnitCpp( const std::string& name, const std::string& returnType, Flags flags ):
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags = 0 )
    {
        m_body.push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // METHODUNITCPP_H
