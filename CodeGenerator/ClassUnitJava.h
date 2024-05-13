#ifndef CLASSUNITJAVA_H
#define CLASSUNITJAVA_H
#include "ClassUnit.h"

class ClassUnitJava : public ClassUnit
{
public:
    ClassUnitJava( const std::string& name ) : ClassUnit( name )
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags )
    {
        if( flags < ACCESS_MODIFIERS.size() && flags < 3)
            m_fields[ flags ].push_back( unit );
        else
            throw std::runtime_error( "Wrong class modifier in ClassUnitJava" );
    }

public:
    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";

        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[i].empty() )
                continue;

            std::string temp = ACCESS_MODIFIERS[i];

            for( const auto& f : m_fields[i] )
            {
                result += generateShift( level + 1 ) + temp + " ";
                result += f->compile( level );
                result += "\n";
            }

        }
        result += generateShift( level ) + "};\n";

        return result;

    }
private:
    const std::vector< std::string > ACCESS_MODIFIERS = { "public", "protected", "private" };
};

#endif // CLASSUNITJAVA_H
