#ifndef OPERATORUNIT_H
#define OPERATORUNIT_H
#include "Unit.h"

class OperatorUnit : public Unit {
public:
    explicit OperatorUnit( const std::string& text ) : m_text( text ){ }
protected:
    std::string m_text;
};
#endif // OPERATORUNIT_H
