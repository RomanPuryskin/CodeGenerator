#ifndef OPERATORUNITSHARP_H
#define OPERATORUNITSHARP_H
#include "OperatorUnit.h"
class OperatorUnitSharp : public OperatorUnit {
public:
    OperatorUnitSharp ( const std::string& text ) : OperatorUnit( text ) { }

    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level + 1 ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};
#endif // OPERATORUNITSHARP_H
