#include <QCoreApplication>
#include <iostream>
#include "classgeneration.h"

int main() {
    std::cout<< "Choose language for generate:\n"
                 "1 for C++\n"
                 "2 for Java\n"
                 "3 for C#\n" <<std::endl;
    unsigned int classControl;
    while(true)
    {
        std::cin>>classControl;
        auto generate = std::make_shared<ClassGeneration>(classControl);
        std::cout<<generate->Program();
    }
    return 0;
}
