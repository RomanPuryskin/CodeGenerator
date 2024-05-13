#ifndef GENERATECODECPP_H
#define GENERATECODECPP_H
#include "ICodeGenerator.h"
#include "ClassUnitCpp.h"
#include "MethodUnitCpp.h"
#include "OperatorUnitCpp.h"
class GenerateCodeCpp : public ICodeGenerator {
public:
    std::shared_ptr< ClassUnit > addClass( const std::string& name )
    {
        return std::shared_ptr< ClassUnit >( new ClassUnitCpp( name ) );
    }

    std::shared_ptr< MethodUnit > addMethod( const std::string& name,
                                          const std::string& returnType,
                                          Unit::Flags flags)
    {
        return std::shared_ptr< MethodUnit >( new MethodUnitCpp( name, returnType, flags ) );
    }

    std::shared_ptr< OperatorUnit > addOperator( const std::string& text )
    {
        return std::shared_ptr< OperatorUnit >( new OperatorUnitCpp( text ) );
    }
};
#endif // GENERATECODECPP_H
