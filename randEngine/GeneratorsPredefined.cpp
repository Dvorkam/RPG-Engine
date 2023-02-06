#include "include/GeneratorsPredefined.hpp"


GeneratorMt19937::GeneratorMt19937(std::seed_seq sseq):generator(sseq){

}

uint32_t GeneratorMt19937::getRandomNumber(){
    return generator();
}
void GeneratorMt19937::setSeed(std::seed_seq sseq){
    generator.seed(sseq);
}
std::mt19937& GeneratorMt19937::getGenerator(){
    return generator;
}


GeneratorMt19937_64::GeneratorMt19937_64(std::seed_seq sseq):generator(sseq){

}
uint64_t GeneratorMt19937_64::getRandomNumber(){
    return generator();
    
}
void GeneratorMt19937_64::setSeed(std::seed_seq sseq){
    generator.seed(sseq);
}
std::mt19937_64& GeneratorMt19937_64::getGenerator(){
    return generator;
}
