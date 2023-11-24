import dicesLibrary.Dice;

#include <iostream>
#include <gtest/gtest.h>
#include <iostream>

//#include <dicesLibrary/Dice.tpp>

TEST(Dice, integration) {
    ASSERT_TRUE(true);
}

TEST(Dice, get_sidess) {
    // Your test code goes here
    auto dice = Dice(6);
    ASSERT_EQ(dice.get_sides(),static_cast<size_t>(6));
}
//
//
//int main(){
//    auto dice = Dice(6);
//    std::cout << "Hello world" << std::endl;
//}