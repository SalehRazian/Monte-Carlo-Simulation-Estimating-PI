#include "../include/inputs_generator.hpp"
#include <chrono>

RandomGenerator::RandomGenerator(int lower_bound, int upper_bound) 
    : mt_generator(std::chrono::system_clock::now().time_since_epoch().count()),
      distributor(0.0, 1.0), 
      LOWER_BOUND(lower_bound),
      UPPER_BOUND(upper_bound),
      BOUND_RANGE(upper_bound - lower_bound)
{}

int RandomGenerator::generate() {
    return static_cast<int>((uniform_generator() * BOUND_RANGE) + LOWER_BOUND);
}

double RandomGenerator::uniform_generator() {
    return distributor(mt_generator);
}

// int RandomGenerator::probability_generator(double random_value) {
//     return 0;
// }

// double RandomGenerator::probability_distribution(double value) {
//     return 0;
// }