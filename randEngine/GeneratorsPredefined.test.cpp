#include "include/GeneratorsPredefined.hpp"
#include <iostream>

int main(){
    std::random_device r;
    GeneratorMt19937 rng1({r(),r(),r()});
    std::cout<<rng1.getRandomNumber()<<std::endl;
    std::cout<<rng1.getRandomNumber()<<std::endl;
    std::cout<<rng1.getRandomNumber()<<std::endl;
    std::cout<<"Test passed"<<std::endl;
}