#ifndef _OUTPUT_TEST_
#define _OUTPUT_TEST_

#include "gtest/gtest.h"
#include "../src/command.hpp"
#include <iostream>

TEST(OutputDUP, testDUP){
	string executable = "echo hello > firstfile";
	Command* test = new Command(executable);
	test->evaluate();
	cout << "reached end" << endl;
}

TEST(OutputDUPCAT, testDUPCAT){
        string executable = "cat newfile";
        Command* test = new Command(executable);
        test->evaluate();
        cout << "reached end" << endl;
}
#endif
