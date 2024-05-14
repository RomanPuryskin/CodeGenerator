#ifndef GENERATECODEJAVA_H
#define GENERATECODEJAVA_H
#include "ICodeGenerator.h"
#include "ClassUnitJava.h"
#include "MethodUnitJava.h"
#include "OperatorUnitJava.h"
class GenerateCodeJava : public ICodeGenerator {
public:
    std::shared_ptr< ClassUnit > addClass( const std::string& name )
    {
        return std::shared_ptr< ClassUnit >( new ClassUnitJava( name ) );
    }

    std::shared_ptr< MethodUnit > addMethod( const std::string& name,
                                          const std::string& returnType,
                                          Unit::Flags flags)
    {
        return std::shared_ptr< MethodUnit >( new MethodUnitJava( name, returnType, flags ) );
    }

    std::shared_ptr< OperatorUnit > addOperator( const std::string& text )
    {
        return std::shared_ptr< OperatorUnit >( new OperatorUnitJava( text ) );
    }
};
#endif // GENERATECODEJAVA_H
