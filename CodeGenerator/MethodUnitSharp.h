#ifndef METHODUNITSHARP_H
#define METHODUNITSHARP_H
#include "MethodUnit.h"
class MethodUnitSharp : public MethodUnit
{
public:
    MethodUnitSharp( const std::string& name, const std::string& returnType, Flags flags ) :
        MethodUnit( name, returnType, flags ) { }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result;
        if( m_flags & STATIC )
            result += "static ";

        result += m_returnType + " " + m_name + "()" + " {\n";

        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }

        result += generateShift( level + 1 ) + "}\n";

        return result;
    }
};
#endif // METHODUNITSHARP_H
