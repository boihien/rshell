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
TEST(RedirectingTest, testsRedirect){
	string input1 = "cat <existingInputFile.txt | tr A-Z a-z |";
	string input2 = "tee newOutputFile1 | tr a-z A-Z > newOutputfile2";
	Redirect* r = new Redirect(input1, input2);
	r->evaluate();
	cout << "reached end of redirect" << endl;
}

TEST(RedirectTest2, testRedirect2){
	string input1 = "echo X && echo Y || echo Z && echo S";
	string input2 = " >> outputfile1.txt | bin/memoryleak";
	Redirect* r2 = new Redirect(input1, input2);
	r2->evaluate();
	cout << "reached end of redirect 2" << endl; 
	
}

#endif
