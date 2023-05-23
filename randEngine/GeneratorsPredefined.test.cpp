#include <iostream>

#include <randEngine/GeneratorsPredefined.tpp>


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Succesfull_doctest_integration_test_for_GeneratorsPredefined")
{
    CHECK(true);
}

TEST_CASE_TEMPLATE("() operator test for generators", 
G, 
generators::GeneratorMt19937, 
generators::GeneratorMt19937_64, 
generators::GeneratorGeneric<generators::DumbGenerator>)
{
    using result_type = typename G::result_type;
    auto seed = static_cast<result_type>(2567890);
    G g1(seed);
    CHECK_NOTHROW(g1());
    CHECK_NE(g1(),g1());
    CHECK_NE(g1(),g1());
}

TEST_CASE_TEMPLATE("getRandomNumber() test for generators", 
G, 
generators::GeneratorMt19937, 
generators::GeneratorMt19937_64, 
generators::GeneratorGeneric<generators::DumbGenerator>)
{
    using result_type = typename G::result_type;
    auto seed = static_cast<result_type>(2567890);
    G g1(seed);
    CHECK_NOTHROW(g1.getRandomNumber());
    CHECK_NE(g1.getRandomNumber(),g1.getRandomNumber());
    CHECK_NE(g1.getRandomNumber(),g1.getRandomNumber());
}

TEST_CASE_TEMPLATE("Test min and max values for predefined generators", 
G, 
generators::GeneratorMt19937, 
generators::GeneratorMt19937_64,
generators::GeneratorGeneric<generators::DumbGenerator>)
{
    using result_type = typename G::result_type;
    auto seed = static_cast<result_type>(2567890);
    G g1(seed);
    CHECK_NOTHROW(g1.min());
    CHECK_NOTHROW(g1.max());
    CHECK(g1.min()<g1.max());
    static_assert(g1.min() == std::numeric_limits<result_type>::min(), "Minimum value does not match expected value");
    static_assert(g1.max() == std::numeric_limits<result_type>::max(), "Maximum value does not match expected value");
}

TEST_CASE_TEMPLATE("Test generator concept for standard and custom generators", 
G, 
std::mt19937, std::mt19937_64, generators::DumbGenerator)
{
    using result_type = typename G::result_type;
    auto seed = static_cast<result_type>(2567890);
    CHECK_NOTHROW(generators::GeneratorGeneric<G> gtest(seed));
}