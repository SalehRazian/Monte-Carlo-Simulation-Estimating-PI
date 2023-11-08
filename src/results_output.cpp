#include "../include/results_output.hpp"
#include <iostream>

void PIApproximation::compute_output(double results) {
    pi_approximation = results * 4.0;
}

void PIApproximation::output() {
    std::cout << "Estimated value of PI = " << pi_approximation << std::endl;
}