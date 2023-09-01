
#pragma once
#include <random>

template <typename UIntRetType, typename GeneratorType>
class IGenerator{
    virtual UIntRetType getRandomNumber() = 0;
    virtual void setSeed(std::seed_seq sseq) = 0;
    virtual GeneratorType& getGenerator() = 0;
};