/**
 * @file GeneratorsPredefined.tpp
 * @author Michal D
 * @brief Contains a set of predefined Uniform 
 * @version 0.1
 * @date 2023-04-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
        constexpr result_type min() const noexcept override
        {
            return std::numeric_limits<result_type>::min();
        }
        constexpr result_type max() const noexcept override
        {
            return std::numeric_limits<result_type>::max();
        }
        result_type operator()() override
        {
            return getRandomNumber();
        }
        /**
         * @brief Get the Random Number object
         * 
         * @return result_type 
         */
        result_type getRandomNumber() override
        {
            return generator();
        }
        /**
         * @brief 
         * 
         * @param sseq 
         */
        void seed(result_type sseq) noexcept override
        {
            generator.seed(sseq);
        }
    };

    /**
     * @brief 
     * 
     */
    class DumbGenerator:public IGenerator<uint8_t>{
        public: 
        using result_type = uint8_t;
        private:
        result_type number{};

        
        public:
            DumbGenerator(){};
            DumbGenerator(uint8_t seed):number(seed){};
            constexpr result_type min() const noexcept override{return 0;}
            constexpr result_type max() const noexcept override{return 255;}

            uint8_t operator ()()override{return number++;}
            uint8_t getRandomNumber()override{return number++;}
            void seed(uint8_t sseq) noexcept override{number = sseq;}

    };

    using GeneratorMt19937 = GeneratorGeneric<std::mt19937>;
    using GeneratorMt19937_64 = GeneratorGeneric<std::mt19937_64>;
}
