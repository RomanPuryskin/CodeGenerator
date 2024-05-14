#include "classgeneration.h"

ClassGeneration::ClassGeneration( unsigned int classFlag)
{
    switch (classFlag)
    {
    case CPP:
        m_factory = std::make_shared< GenerateCodeCpp >();
        break;
    case JAVA:
        m_factory = std::make_shared < GenerateCodeJava > ();
        break;
    case SHARP:
        m_factory = std::make_shared < GenerateCodeSharp > ();
        break;
    default:
        throw std::runtime_error( "Wrong language" );
        break;
    }
    m_flag = classFlag;
}

std::string ClassGeneration::generateProgramCpp( const std::shared_ptr< ICodeGenerator >& factory )
{
    auto myClass = factory->addClass( "MyClass" );
    myClass->add( factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
    myClass->add( factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
    myClass->add( factory->addMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ), ClassUnit::PUBLIC);
    std::shared_ptr< MethodUnit > method = factory->addMethod( "testFunc4", "void", MethodUnit::STATIC );
    method->add( factory->addOperator( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}
std::string ClassGeneration::generateProgramJava( const std::shared_ptr< ICodeGenerator >& factory ) {
    auto myClass = factory->addClass( "MyClass" );
    myClass->add( m_factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
    myClass->add( m_factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
    myClass->add( m_factory->addMethod( "testFunc3", "void", MethodUnit::ABSTRACT), ClassUnit::PUBLIC);
    std::shared_ptr< MethodUnit > method = m_factory->addMethod( "testFunc4", "void", MethodUnit::FINAL );
    method->add( m_factory->addOperator( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}
std::string ClassGeneration::generateProgramSharp( const std::shared_ptr< ICodeGenerator >& factory ) {
    auto myClass = factory->addClass( "MyClass" );
    myClass->add( m_factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
    myClass->add( m_factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
    myClass->add( m_factory->addMethod( "testFunc3", "void", MethodUnit::STATIC), ClassUnit::PRIVATE_PROTECTED);
    std::shared_ptr< MethodUnit > method = m_factory->addMethod( "testFunc4", "void", MethodUnit::FINAL );
    method->add( m_factory->addOperator( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    myClass->add( m_factory->addMethod( "testFunc5", "void", 0), ClassUnit::INTERNAL);
    myClass->add( m_factory->addMethod( "testFunc6", "void", 0), ClassUnit::FILE);
    return myClass->compile();
}

std::string ClassGeneration::Program()
{
    switch (m_flag) {
    case CPP:
        return generateProgramCpp(m_factory);
        break;
    case JAVA:
        return generateProgramJava(m_factory);
        break;
    case SHARP:
        return generateProgramSharp(m_factory);
        break;
    default:
        break;
    }
}
