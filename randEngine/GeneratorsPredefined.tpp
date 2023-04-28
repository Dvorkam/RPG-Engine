#pragma once
#include <limits>
#include <randEngine/IGenerator.tpp>

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
        result_type operator()() override
        {
            return getRandomNumber();
        }
        result_type getRandomNumber() override
        {
            return generator();
        }
        void seed(result_type sseq) override
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

            uint8_t operator ()()override{return number++;}
            uint8_t getRandomNumber()override{return number++;}
            void seed(uint8_t sseq)override{number = sseq;}

    };

    using GeneratorMt19937 = GeneratorGeneric<std::mt19937>;
    using GeneratorMt19937_64 = GeneratorGeneric<std::mt19937_64>;
}
