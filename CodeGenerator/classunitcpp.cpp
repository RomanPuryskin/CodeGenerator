#include "classunitcpp.h"

void ClassUnitCpp::add( const std::shared_ptr< Unit >& unit, Flags flags )
{
    if( flags < ACCESS_MODIFIERS.size() )
    {
        m_fields[ flags ].push_back( unit );
    }
}
std::string ClassUnitCpp::compile( unsigned int level) const
{
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";

        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
        {
            if( m_fields[ i ].empty()  )
                continue;

            result += ACCESS_MODIFIERS[ i ] + ":\n";

            for( const auto& f : m_fields[ i ] )
            {
                result += f/*std::shared_ptr<MethodUnitCpp>*/->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
}

const std::vector< std::string > ClassUnitCpp::ACCESS_MODIFIERS = { "public","protected", "private" };



