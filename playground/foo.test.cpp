#include <gtest/gtest.h>

#include <iostream>
// import <iostream>;
TEST(playground, pass_test)
{
    std::cout << "hello world" << std::endl;
    ASSERT_TRUE(true);
}