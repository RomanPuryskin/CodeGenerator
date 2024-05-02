#ifndef CLASSUNITCPP_H
#define CLASSUNITCPP_H
#include "unit.h"

class ClassUnitCpp : public Unit
{
public:

    enum AccessModifier
    {
        PUBLIC,  // = 0
        PROTECTED, // = 1
        PRIVATE // = 2
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit ClassUnitCpp( const std::string& name): m_name( name )
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags );

    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};


#endif // CLASSUNITCPP_H
