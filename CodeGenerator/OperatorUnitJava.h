#ifndef OPERATORUNITJAVA_H
#define OPERATORUNITJAVA_H
#include "OperatorUnit.h"

class OperatorUnitJava : public OperatorUnit {
public:
    OperatorUnitJava ( const std::string& text ) : OperatorUnit( text ) { }

    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level + 1 ) + "System.out.print( \"" + m_text + "\" );\n";
    }
};
#endif // OPERATORUNITJAVA_H
