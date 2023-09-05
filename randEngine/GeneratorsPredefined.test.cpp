#include <iostream>
#include <randEngine/GeneratorsPredefined.tpp>

#include <gtest/gtest.h>

TEST(randEngine_generic, gtest_integration)
{
    ASSERT_TRUE(true);
}

template <typename GeneratorType>
class GeneratorTest : public testing::Test {
protected:
    using result_type = typename GeneratorType::result_type;
    GeneratorType generator;

    void SetUp() override {
        result_type seed = static_cast<result_type>(2567890);
        generator = GeneratorType(seed);
    }
};

template <typename T>
class MyFixture : public testing::Test {
 public:
  ...
  using List = std::list<T>;
  static T shared_;
  T value_;
};


using MyTypes = ::testing::Types<generators::GeneratorMt19937,
                                    generators::GeneratorMt19937_64,
                                    generators::GeneratorGeneric<generators::DumbGenerator>>;
TYPED_TEST_SUITE(MyFixture, MyTypes);


TYPED_TEST(GeneratorTest, OperatorParenthesesTest) {
    EXPECT_NO_THROW(this->generator());
    EXPECT_NE(this->generator(), this->generator());
    EXPECT_NE(this->generator(), this->generator());
}

//TEST_CASE_TEMPLATE("getRandomNumber() test for generators", 
//G, 
//generators::GeneratorMt19937, 
//generators::GeneratorMt19937_64, 
//generators::GeneratorGeneric<generators::DumbGenerator>)
//{
//    using result_type = typename G::result_type;
//    auto seed = static_cast<result_type>(2567890);
//    G g1(seed);
//    CHECK_NOTHROW(g1.getRandomNumber());
//    CHECK_NE(g1.getRandomNumber(),g1.getRandomNumber());
//    CHECK_NE(g1.getRandomNumber(),g1.getRandomNumber());
//}
//
//TEST_CASE_TEMPLATE("Test min and max values for predefined generators", 
//G, 
//generators::GeneratorMt19937, 
//generators::GeneratorMt19937_64,
//generators::GeneratorGeneric<generators::DumbGenerator>)
//{
//    using result_type = typename G::result_type;
//    auto seed = static_cast<result_type>(2567890);
//    G g1(seed);
//    CHECK_NOTHROW(g1.min());
//    CHECK_NOTHROW(g1.max());
//    CHECK(g1.min()<g1.max());
//    static_assert(g1.min() == std::numeric_limits<result_type>::min(), "Minimum value does not match expected value");
//    static_assert(g1.max() == std::numeric_limits<result_type>::max(), "Maximum value does not match expected value");
//}
//
//TEST_CASE_TEMPLATE("Test generator concept for standard and custom generators", 
//G, 
//std::mt19937, std::mt19937_64, generators::DumbGenerator)
//{
//    using result_type = typename G::result_type;
//    auto seed = static_cast<result_type>(2567890);
//    CHECK_NOTHROW(generators::GeneratorGeneric<G> gtest(seed));
//}