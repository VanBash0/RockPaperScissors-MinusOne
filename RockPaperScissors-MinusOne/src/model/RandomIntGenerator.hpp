#ifndef RANDOM_INT_GENERATOR
#define RANDOM_INT_GENERATOR

#include <random>

class RandomIntGenerator {
public:
    static std::mt19937& GetGenerator();
    static int Next(int min, int max);
};

#endif // RANDOM_INT_GENERATOR