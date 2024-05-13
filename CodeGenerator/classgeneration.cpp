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
}

std::string ClassGeneration::Program(unsigned int classFlag)
{
    auto myClass = m_factory->addClass( "MyClass" );
    switch (classFlag) {
    case CPP:
     {   myClass->add( m_factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
        myClass->add( m_factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
        myClass->add( m_factory->addMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ), ClassUnit::PUBLIC);
        std::shared_ptr< MethodUnit > method = m_factory->addMethod( "testFunc4", "void", MethodUnit::STATIC );
        method->add( m_factory->addOperator( R"(Hello, world!\n)" ) );
        myClass->add( method, ClassUnit::PROTECTED );
        break;
        }
    case JAVA:
        {myClass->add( m_factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
        myClass->add( m_factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
        myClass->add( m_factory->addMethod( "testFunc3", "void", MethodUnit::ABSTRACT), ClassUnit::PUBLIC);
        std::shared_ptr< MethodUnit > method = m_factory->addMethod( "testFunc4", "void", MethodUnit::FINAL );
        method->add( m_factory->addOperator( R"(Hello, world!\n)" ) );
        myClass->add( method, ClassUnit::PROTECTED );
        break; }
    case SHARP:
    { myClass->add( m_factory->addMethod( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
        myClass->add( m_factory->addMethod( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
        myClass->add( m_factory->addMethod( "testFunc3", "void", MethodUnit::STATIC), ClassUnit::PRIVATE_PROTECTED);
        std::shared_ptr< MethodUnit > method = m_factory->addMethod( "testFunc4", "void", MethodUnit::FINAL );
        method->add( m_factory->addOperator( R"(Hello, world!\n)" ) );
        myClass->add( method, ClassUnit::PROTECTED );
        myClass->add( m_factory->addMethod( "testFunc5", "void", 0), ClassUnit::INTERNAL);
        myClass->add( m_factory->addMethod( "testFunc6", "void", 0), ClassUnit::FILE);
        break; }
    default:
        break;
    }
    return myClass->compile();
}
