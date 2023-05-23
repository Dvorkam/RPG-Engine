#pragma once

#include "IGenerator.hpp"

class GeneratorMt19937:IGenerator<uint32_t,std::mt19937>{
std::mt19937 generator;
GeneratorMt19937();

public:
GeneratorMt19937(std::seed_seq sseq);

virtual uint32_t getRandomNumber();
virtual void setSeed(std::seed_seq sseq);
virtual std::mt19937& getGenerator();
};

class GeneratorMt19937_64:IGenerator<uint64_t,std::mt19937_64>{
std::mt19937_64 generator;
GeneratorMt19937_64();
public:

GeneratorMt19937_64(std::seed_seq sseq);
virtual uint64_t getRandomNumber();
virtual void setSeed(std::seed_seq sseq);
virtual std::mt19937_64& getGenerator();
};