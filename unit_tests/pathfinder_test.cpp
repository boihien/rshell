#ifndef __PATHFINDER_TEST_CPP
#define __PATHFINDER_TEST_CPP
#include "gtest/gtest.h"
#include "../src/command.h"
#include <iostream>
TEST(PipeTest, testsPipe){
	string input1 = "echo hello world";
	string input2 = "bin/memoryleak";
	Pipe* p = new Pipe(input1, input2);
	p->evaluate();
	cout << "reached end pipe"<< endl;
	//cout << p->evaluate();
	//EXPECT_EQ(2,2);
}

#endif
