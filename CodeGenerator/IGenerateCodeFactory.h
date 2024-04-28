#ifndef IGENERATECODEFACTORY_H
#define IGENERATECODEFACTORY_H
#include <memory>
#include "classunit.h"
#include "methodunit.h"
#include "PrintOperatorUnit.h"

class IGenerateCodeFactory {

public:
    virtual ~IGenerateCodeFactory() = default;

    virtual std::shared_ptr<ClassUnit> addClass (const std::string& name) = 0;

    virtual std::shared_ptr<MethodUnit> addMethod(const std::string& name,
                                                  const std::string& returnType,
                                                  Unit::Flags flags ) = 0;

    virtual std::shared_ptr<PrintOperatorUnit> addPrintOperator(const std::string& text) = 0;

};

#endif // IGENERATECODEFACTORY_H
