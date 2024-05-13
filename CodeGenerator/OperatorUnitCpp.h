#ifndef OPERATORUNITCPP_H
#define OPERATORUNITCPP_H
#include "OperatorUnit.h"

class OperatorUnitCpp : public OperatorUnit {
public:
    OperatorUnitCpp ( const std::string& text ) : OperatorUnit( text ) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + getText() + "\" );\n";
    }
};
#endif // OPERATORUNITCPP_H
