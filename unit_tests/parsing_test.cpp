//#include "path/to/main.cpp"
#include "gtest/gtest.h"
#include <string>
TEST(InputTest, HelloWorld){
	string uInput = "Hello There"
	EXPECT_EQ("Hello \n There", parse(uInput));
}
