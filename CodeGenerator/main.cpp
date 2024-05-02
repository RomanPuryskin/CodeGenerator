#include <QCoreApplication>
#include "IGenerateCodeFactory.h"
#include <iostream>

std::string generateProgram() {
    ClassUnitCpp myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnitCpp >( "testFunc1", "void", 0 ),
        ClassUnitCpp::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodUnitCpp >( "testFunc2", "void", MethodUnitCpp::STATIC ),
        ClassUnitCpp::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodUnitCpp >( "testFunc3", "void", MethodUnitCpp::VIRTUAL | MethodUnitCpp::CONST ),
        ClassUnitCpp::PUBLIC
        );
    auto method = std::make_shared< MethodUnitCpp >( "testFunc4", "void", MethodUnitCpp::STATIC );
    method->add( std::make_shared< PrintOperatorUnitCpp >( R"(Hello, world!\n)" ) );//R для печати \n
    myClass.add( method, ClassUnitCpp::PROTECTED );
    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    return 0;
}
