// Could have used #pragma once
#ifndef INPUT_GENERATOR_HPP
#define INPUT_GENERATOR_HPP
#include <random>

class RandomGenerator {
    private:
        // Random Setup
        std::mt19937 mt_generator; // Mersenne Twister 
        std::uniform_real_distribution<double> distributor;

        // Boundry
        const int LOWER_BOUND;
        const int UPPER_BOUND;
        const int BOUND_RANGE;

    public:
        RandomGenerator(int lower_bound = 0, int upper_bound = 1);
        int generate();
    private:
        double uniform_generator();
        // int probability_generator(double random_value);
        // double probability_distribution(double random_value);
};

#endif