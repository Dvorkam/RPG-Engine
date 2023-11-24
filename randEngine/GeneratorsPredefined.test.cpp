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
    generators::GeneratorGeneric<generators::DumbGenerator>,
    generators::ConcurrentGeneratorGeneric<std::mt19937>,
    generators::ConcurrentGeneratorGeneric<std::mt19937_64>
>;

using UniformRandomNumberGeneratorConceptTypes = ::testing::Types<
    std::mt19937,
    std::mt19937_64,
    generators::DumbGenerator
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

template <typename ConceptType>
class ConceptTest : public ::testing::Test {
public:
    using result_type = typename ConceptType::result_type;
protected:
    std::unique_ptr<ConceptType> generator;

    void SetUp() override {
        result_type seed = static_cast<result_type>(2567890);
        generator = std::make_unique<ConceptType>(seed);
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
    auto min = std::numeric_limits<result_type>::min();
    auto max = std::numeric_limits<result_type>::max();
    EXPECT_EQ(this->generator->min(), min);
    EXPECT_EQ(this->generator->max(), max);
    }

TYPED_TEST_SUITE(ConceptTest, UniformRandomNumberGeneratorConceptTypes);
TYPED_TEST(ConceptTest, nothrow){
    using result_type = typename TestFixture::result_type;
    EXPECT_TRUE(true);
}