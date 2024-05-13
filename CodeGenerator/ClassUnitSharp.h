#ifndef CLASSUNITSHARP_H
#define CLASSUNITSHARP_H
#include "ClassUnit.h"

class ClassUnitSharp : public ClassUnit {
public:
    ClassUnitSharp( const std::string& name ) : ClassUnit( name )
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags )
    {
        if( flags < ACCESS_MODIFIERS.size() )
            m_fields[ flags ].push_back( unit );
    }

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
    const std::vector< std::string > ACCESS_MODIFIERS = { "public", "protected", "private","private protected","file","internal",
    "protected internal" };

};
#endif // CLASSUNITSHARP_H
