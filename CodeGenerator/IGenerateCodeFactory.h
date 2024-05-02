#ifndef IGENERATECODEFACTORY_H
#define IGENERATECODEFACTORY_H
#include <memory>
#include "classunitcpp.h"
#include "methodunitcpp.h"
#include "PrintOperatorUnitcpp.h"

class IGenerateCodeFactory {

public:
    virtual ~IGenerateCodeFactory() = default;

    virtual std::shared_ptr<Unit> addClass (const std::string& name) = 0;

    virtual std::shared_ptr<Unit> addMethod(const std::string& name,
                                                  const std::string& returnType,
                                                  Unit::Flags flags ) = 0;

    virtual std::shared_ptr<Unit> addPrintOperator(const std::string& text) = 0;

};

#endif // IGENERATECODEFACTORY_H
