#include <QCoreApplication>
#include <iostream>
#include "GenerateCodeCpp.h"
#include "GenerateCodeJava.h"
#include "GenerateCodeSharp.h"
std::string generateProgram( const std::shared_ptr< ICodeGenerator >& factory ) {
    auto myClass = factory->addClass( "MyClass" );
    myClass->add( factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
    myClass->add( factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE_PROTECTED);
    myClass->add( factory->addMethod( "testFunc3", "void", /*MethodUnit::FINAL |*/ MethodUnit::STATIC ), ClassUnit::PUBLIC);
    std::shared_ptr< MethodUnit > method = factory->addMethod( "testFunc4", "void", 0/*MethodUnit::ABSTRACT*/ );
    method->add( factory->addOperator( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}
int main() {
    std::cout << generateProgram( std::make_shared< GenerateCodeSharp >() ) << std::endl;
    return 0;
}
