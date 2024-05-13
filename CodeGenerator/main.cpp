#include <QCoreApplication>
#include <iostream>
#include "GenerateCodeCpp.h"
std::string generateProgram( const std::shared_ptr< ICodeGenerator >& factory ) {
    auto myClass = factory->addClass( "MyClass" );
    myClass->add( factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
    myClass->add( factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
    myClass->add( factory->addMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ), ClassUnit::PUBLIC);
    std::shared_ptr< MethodUnit > method = factory->addMethod( "testFunc4", "void", MethodUnit::STATIC );
    method->add( factory->addOperator( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}
int main() {
    std::cout << generateProgram( std::make_shared< GenerateCodeCpp >() ) << std::endl;
    return 0;
}
