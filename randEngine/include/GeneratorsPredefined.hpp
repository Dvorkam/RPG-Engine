#pragma once
#include <limits>
#include "IGenerator.hpp"

namespace generators{
    template<typename UIntRetType, typename Generator>
    class GeneratorGeneric:public IGenerator<UIntRetType>{
        Generator generator;
        GeneratorGeneric();

        public:
        GeneratorGeneric(UIntRetType seed){generator.seed(seed);}
        virtual constexpr UIntRetType min()
        {
            return std::numeric_limits<UIntRetType>::min();
        }
        virtual constexpr UIntRetType max()
        {
            return std::numeric_limits<UIntRetType>::max();
        }
        virtual UIntRetType operator()()
        {
            return getRandomNumber();
        }
        virtual UIntRetType getRandomNumber()
        {
            return generator();
        }
        virtual void setSeed(std::seed_seq sseq)
        {
            generator.seed(sseq);
        }
    };

    using GeneratorMt19937 = GeneratorGeneric<uint32_t,std::mt19937>;
    using GeneratorMt19937_64 = GeneratorGeneric<uint32_t,std::mt19937_64>;
}
