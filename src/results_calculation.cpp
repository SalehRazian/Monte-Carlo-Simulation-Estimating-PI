#include "../include/results_calculation.hpp"
#include <iostream>

void ResultsAggregation::compute(int value) {
    total_inputs = total_inputs + 1;
    inputs_sum = inputs_sum + value;
}

double ResultsAggregation::get_ratio() {
    return static_cast<double>(inputs_sum) / total_inputs;
}

int ResultsAggregation::get_total_inputs() {
    return total_inputs;
}

int ResultsAggregation::get_inputs_sum() {
    return inputs_sum;
}