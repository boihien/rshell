#ifndef __INPUT_TEST_CPP__
#define __INPUT_TEST_CPP__

#include "gtest/gtest.h"
#include "../src/command.h"

TEST(input, testsParse) {
    Command* test = new Command("ls -a");
    
    EXPECT_EQ(test->evaluate(), 0);
}

#endif //__INPUT_TEST_HPP__
