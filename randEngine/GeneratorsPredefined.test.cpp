#include <iostream>
#include <memory>
#include <limits>

#include <randEngine/GeneratorsPredefined.tpp>

#include <gtest/gtest.h>

TEST(diceLibrary_generic, gtest_GeneratorsPredefined_integration) {
    // Your test code goes here
    ASSERT_TRUE(true);
}

using GeneratorTypes = ::testing::Types<
    generators::GeneratorMt19937,
    generators::GeneratorMt19937_64,
    generators::GeneratorGeneric<generators::DumbGenerator>
>;

template <typename GeneratorType>
class GeneratorTest : public ::testing::Test {
public:
    using result_type = typename GeneratorType::result_type;
protected:
    std::unique_ptr<GeneratorType> generator;

    void SetUp() override {
        result_type seed = static_cast<result_type>(2567890);
        generator = std::make_unique<GeneratorType>(seed);
    }
    void TearDown() override{
        generator.reset();
    }
};

TYPED_TEST_SUITE(GeneratorTest, GeneratorTypes);
TYPED_TEST(GeneratorTest, getRandomNumberTest) {
    EXPECT_NO_THROW(this->generator->getRandomNumber());
    EXPECT_NE(this->generator->getRandomNumber(), this->generator->getRandomNumber());
    EXPECT_NE(this->generator->getRandomNumber(), this->generator->getRandomNumber());
}

TYPED_TEST(GeneratorTest, minMaxValTest) {
    using result_type = typename TestFixture::result_type;
    EXPECT_LT(this->generator->min(), this->generator->max());
    auto min = std::numeric_limits<unsigned int>::min();
    auto max = std::numeric_limits<unsigned int>::max();
    EXPECT_EQ(this->generator->min(), min);
    EXPECT_EQ(this->generator->max(), max);
    }


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