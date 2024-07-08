#include "header.h"
#include <iostream>

int headerNonVirtualFun()
{
    std::cout<<"NonVirtual fun Globally"<<std::endl;
    return 1;
}


int header::headerNonVirtualFun_inside_class()
{
    std::cout<<"NonVirtual fun Inside Class "<<std::endl;
    return 1;
}

int header::headerNonVirtualFun_inside_classpecial()
{
    std::cout<<"NonVirtual fun Inside Class  special using Pointer we can access "<<std::endl;
    return 1;
}