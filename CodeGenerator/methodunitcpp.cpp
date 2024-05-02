#include "methodunitcpp.h"

std::string MethodUnitCpp::compile( unsigned int level ) const
{
    {
        std::string result = generateShift( level );
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_flags & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b/* b = std::shared_ptr<PrintOperatorUnitCpp>*/->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
}

