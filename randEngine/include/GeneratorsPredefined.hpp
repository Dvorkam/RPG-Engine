#pragma once
#include <limits>
#include "IGenerator.hpp"

namespace generators{
    template<UniformRandomNumberGenerator Generator>
    class GeneratorGeneric:public IGenerator<typename Generator::result_type>{
        Generator generator;
        GeneratorGeneric();

        public:
        using result_type = typename Generator::result_type;
        GeneratorGeneric(result_type seed){generator.seed(seed);}
        virtual constexpr result_type min()
        {
            return std::numeric_limits<result_type>::min();
        }
        virtual constexpr result_type max()
        {
            return std::numeric_limits<result_type>::max();
        }
        virtual result_type operator()()
        {
            return getRandomNumber();
        }
        virtual result_type getRandomNumber()
        {
            return generator();
        }
        virtual void seed(result_type sseq)
        {
            generator.seed(sseq);
        }
    };

    class DumbGenerator:public IGenerator<uint8_t>{
        public: 
        using result_type = uint8_t;
        private:
        result_type number{};

        
        public:
            DumbGenerator(){};
            DumbGenerator(uint8_t seed):number(seed){};
            constexpr result_type min(){return 0;}
            constexpr result_type max(){return 255;}

            virtual uint8_t operator ()(){return number++;}

            virtual uint8_t getRandomNumber(){return number++;}
            virtual void seed(uint8_t sseq){number = sseq;}

    };

    using GeneratorMt19937 = GeneratorGeneric<std::mt19937>;
    using GeneratorMt19937_64 = GeneratorGeneric<std::mt19937_64>;
}
