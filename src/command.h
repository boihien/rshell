#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <iostream>
using namespace std;
#include <string>
#include "base.h"

class Command: public Base{
    private:
        string in;
    public:
        Command(string input);
        char * parse(string input);
        void evaluate();
	string comm;
};

#endif
