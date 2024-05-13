#ifndef CLASSUNITCPP_H
#define CLASSUNITCPP_H
#include "ClassUnit.h"

class ClassUnitCpp : public ClassUnit {
public:
    ClassUnitCpp( const std::string& name ) : ClassUnit( name ) { }

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[i].empty() ) {
                continue;
            }

            result += ACCESS_MODIFIERS[i] + ":\n";
            for( const auto& f : m_fields[i] ) {
                result += f->compile( level + 1 );
            }

            result += "\n";
        }
        result += generateShift( level ) + "};\n";

        return result;
    }
};
#endif // CLASSUNITCPP_H
