#pragma once

#include "IGenerator.h"

class GeneratorMt19937:IGenerator<uint32_t,std::mt19937>{
std::mt19937 generator;
GeneratorMt19937();

public:
GeneratorMt19937(std::seed_seq sseq);

inline virtual uint32_t getRandomNumber();
inline virtual void setSeed(std::seed_seq sseq);
inline virtual std::mt19937& getGenerator();
};

class GeneratorMt19937_64:IGenerator<uint64_t,std::mt19937_64>{
std::mt19937_64 generator;
GeneratorMt19937_64();
public:

GeneratorMt19937_64(std::seed_seq sseq);
inline virtual uint64_t getRandomNumber();
inline virtual void setSeed(std::seed_seq sseq);
inline virtual std::mt19937_64& getGenerator();
};