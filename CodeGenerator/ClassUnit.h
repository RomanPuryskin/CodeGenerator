#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "Unit.h"
class ClassUnit : public Unit {
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit ClassUnit( const std::string& name ) : m_name( name )
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags )
    {
        if( flags < ACCESS_MODIFIERS.size() )
        {
            m_fields[ flags ].push_back( unit );
        }
    }

protected:
    std::string m_name;
    std::vector<  std::vector< std::shared_ptr<Unit> >  > m_fields;

};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };
#endif // CLASSUNIT_H
