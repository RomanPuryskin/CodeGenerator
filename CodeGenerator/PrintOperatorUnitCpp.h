#ifndef PRINTOPERATORUNITCPP_H
#define PRINTOPERATORUNITCPP_H
#include "unit.h"

class PrintOperatorUnitCpp : public Unit {
public:
    explicit PrintOperatorUnitCpp( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};
#endif // PRINTOPERATORUNITCPP_H
