#include "gtest/gtest.h"
#include "pathfinder_test.cpp"
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
