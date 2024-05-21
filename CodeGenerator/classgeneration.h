#ifndef CLASSGENERATION_H
#define CLASSGENERATION_H
#include "GenerateCodeCpp.h"
#include "GenerateCodeJava.h"
#include "GenerateCodeSharp.h"

class ClassGeneration
{
    enum ClassLanguages
    {
        CPP    =   1,
        JAVA   =   2,
        SHARP  =   3
    };

public:
    ClassGeneration( unsigned int classFlag);
    std::string generateProgramCpp();
    std::string generateProgramJava();
    std::string generateProgramSharp();
    std::string Program();

private:
    unsigned int m_flag;
    std::shared_ptr< ICodeGenerator > m_factory;
};

#endif // CLASSGENERATION_H
