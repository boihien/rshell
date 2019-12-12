#ifndef __BASE_HPP_
#define __BASE_HPP_
#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Base{
    public:
        string executable;
        Base(){ };
        virtual void evaluate() = 0;
        virtual char * parse(string input) = 0;
        bool succeeded;
        bool keepexecuting;
};

#endif

