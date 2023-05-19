
#pragma once
#include <random>
#include <concepts>
#include <type_traits>

template <typename G>
concept UniformRandomNumberGenerator = requires(G g) {
    typename G::result_type;
    { g.min() } -> std::same_as<typename G::result_type>;
    { g.max() } -> std::same_as<typename G::result_type>;
    { g() } -> std::same_as<typename G::result_type>;
    requires std::is_unsigned_v<typename G::result_type>;
    g.min() < g.max();
};
/*&&
    requires(G g) {
    g.min() < g.max();
} || G::min() < G::max();*/

template <typename UIntRetType>
class IGenerator{
    public:
    using result_type = UIntRetType;
    
    virtual UIntRetType operator ()() = 0;

    virtual UIntRetType getRandomNumber() = 0;
    virtual void seed(UIntRetType sseq) = 0;
};