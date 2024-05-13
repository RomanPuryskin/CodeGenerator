#ifndef METHODUNITCPP_H
#define METHODUNITCPP_H
#include "MethodUnit.h"

class MethodUnitCpp : public MethodUnit {
public:
    MethodUnitCpp( const std::string& name, const std::string& returnType, Flags flags ) :
        MethodUnit( name, returnType, flags ) { }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level );
        if( m_flags & STATIC )
            result += "static ";
        else if( m_flags & VIRTUAL )
            result += "virtual ";

        result += m_returnType + " ";
        result += m_name + "()";

        if( m_flags & CONST )
            result += " const";

        result += " {\n";

        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }

        result += generateShift( level ) + "}\n";

        return result;
    }
};
#endif // METHODUNITCPP_H
