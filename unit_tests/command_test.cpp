#include "command.h"
#include <string>
#include "gtest/gtest.h"

TEST(CommandTest, CTest){
	string uInput;
	Command* p = new Command(uInput);
	p->evaluate();
	EXPECT_EQ(0);
}
