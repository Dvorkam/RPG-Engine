
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

template <typename UIntRetType>
class IGenerator{
    public:
    using result_type = UIntRetType;

    virtual ~IGenerator() = default;
    
    virtual result_type operator ()() = 0;

    virtual result_type getRandomNumber() = 0;
    virtual void seed(result_type sseq) noexcept = 0;
    virtual constexpr result_type min() const noexcept = 0;
    virtual constexpr result_type max() const noexcept = 0;
};