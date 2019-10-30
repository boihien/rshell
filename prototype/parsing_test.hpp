#ifndef __PARSING_TEST_HPP__
#define __PARSING_TEST_HPP__

#include "gtest/gtest.h"
#include "parsing.hpp"

TEST(ParsingTest, ParsingEvalInput) {
    Op* one = new Op(1);
    Op* two = new Op(2);
    Parsing* test = new Parsing(one, two);
    EXPECT_EQ(test->evaluate(),hello world);
}

#endif
