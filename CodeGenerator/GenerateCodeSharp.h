#ifndef GENERATECODESHARP_H
#define GENERATECODESHARP_H
#include "ICodeGenerator.h"
#include "ClassUnitSharp.h"
#include "MethodUnitSharp.h"
#include "OperatorUnitSharp.h"
class GenerateCodeSharp : public ICodeGenerator {
public:
    std::shared_ptr< ClassUnit > addClass( const std::string& name )
    {
        return std::shared_ptr< ClassUnit >( new ClassUnitSharp( name ) );
    }

    std::shared_ptr< MethodUnit > addMethod( const std::string& name,
                                          const std::string& returnType,
                                          Unit::Flags flags)
    {
        return std::shared_ptr< MethodUnit >( new MethodUnitSharp( name, returnType, flags ) );
    }

    std::shared_ptr< OperatorUnit > addOperator( const std::string& text )
    {
        return std::shared_ptr< OperatorUnit >( new OperatorUnitSharp( text ) );
    }
};
#endif // GENERATECODESHARP_H
