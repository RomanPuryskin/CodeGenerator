#ifndef METHODUNITJAVA_H
#define METHODUNITJAVA_H
#include "MethodUnit.h"
class MethodUnitJava : public MethodUnit
{
public:
    MethodUnitJava( const std::string& name, const std::string& returnType, Flags flags ) :
        MethodUnit( name, returnType, flags ) { }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result;
        if( m_flags & STATIC )
            result += "static ";
        else if( m_flags & FINAL )
            result += "final ";
        else if (m_flags & ABSTRACT)
            result += "abstract ";

        result += m_returnType + " " + m_name + "()" + " {\n";

        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }

        result += generateShift( level + 1 ) + "}\n";

        return result;
    }
};

#endif // METHODUNITJAVA_H
