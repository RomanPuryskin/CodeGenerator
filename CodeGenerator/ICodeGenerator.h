#ifndef ICODEGENERATOR_H
#define ICODEGENERATOR_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "OperatorUnit.h"

class ICodeGenerator {
public:
    virtual ~ICodeGenerator() = default;

    virtual std::shared_ptr< ClassUnit > addClass( const std::string& name ) = 0;

    virtual std::shared_ptr< MethodUnit > addMethod( const std::string& name,
                                                     const std::string& returnType,
                                                     Unit::Flags flags) = 0;

    virtual std::shared_ptr< OperatorUnit > addOperator( const std::string& text ) = 0;
};
#endif // ICODEGENERATOR_H
