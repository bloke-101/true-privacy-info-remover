#include <iostream>

#include "random_generator.h"


void initGenerator(PRNG& generator) {
    std::random_device device;
    generator.engine.seed(device());
}

uint random(PRNG& generator, uint left, uint right) {
    std::uniform_int_distribution<unsigned int> distribution(left, right);
    return distribution(generator.engine);
}
