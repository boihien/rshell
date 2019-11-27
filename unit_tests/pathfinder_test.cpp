#ifndef __PATHFINDER_TEST_CPP
#define __PATHFINDER_TEST_CPP
#include "gtest/gtest.h"
#include "../src/command.h"

TEST(PathFinder, testsPath){
	string input;
	Command* c = new Command(input);
	char flag2 = 'e';
	EXPECT_EQ(c->filePath(c->argm[2], flag2), (false));

}
#endif
