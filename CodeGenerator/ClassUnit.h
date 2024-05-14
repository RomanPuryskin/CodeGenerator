#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "Unit.h"
#include <iostream>
class ClassUnit : public Unit {
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL,

    };

    explicit ClassUnit( const std::string& name ) : m_name( name ){}

protected:
    std::string m_name;
    std::vector<  std::vector< std::shared_ptr<Unit> >  > m_fields;

};
#endif // CLASSUNIT_H
