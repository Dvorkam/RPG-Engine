
#pragma once
#include <random>
#include <concepts>
#include <type_traits>

template <typename G>
concept UniformRandomNumberGenerator = requires(G g) {
    typename G::result_type;
    { G::min() } -> std::same_as<typename G::result_type>;
    { G::max() } -> std::same_as<typename G::result_type>;
    { g() } -> std::same_as<typename G::result_type>;

    requires std::is_unsigned_v<typename G::result_type>;
    requires G::min() < G::max();
};

template <typename UIntRetType>
class IGenerator{
    public:
    using result_type = UIntRetType;
    
    virtual constexpr result_type min() = 0;
    virtual constexpr result_type max() = 0;
    
    virtual result_type operator ()() = 0;

    virtual UIntRetType getRandomNumber() = 0;
    virtual void setSeed(std::seed_seq sseq) = 0;
};