#include <random>

using uint = unsigned int;


struct PRNG {
    std::mt19937 engine;
};

void initGenerator(PRNG& generator);

uint random(PRNG& generator, uint left, uint right);
