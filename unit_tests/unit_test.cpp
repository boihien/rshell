#include "gtest/gtest.h"
//#include "parsing_test.cpp"
//#include "command_test.cpp"
//#include "input_test.cpp"
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
