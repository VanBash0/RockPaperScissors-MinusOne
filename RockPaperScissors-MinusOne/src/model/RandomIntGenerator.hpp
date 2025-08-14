#ifndef RANDOM_INT_GENERATOR
#define RANDOM_INT_GENERATOR

#include <random>

class RandomIntGenerator {
private:
    static std::mt19937& getGenerator();
public:
    static int Next(int min, int max);
};

#endif // RANDOM_INT_GENERATOR