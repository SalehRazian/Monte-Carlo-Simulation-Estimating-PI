#include "include/inputs_domain.hpp"
#include "include/inputs_generator.hpp"
#include "include/results_calculation.hpp"
#include "include/results_output.hpp"

int main() {
    int domain_size = 1000; 
    SquaredCircleDomain domain(domain_size);
    RandomGenerator random_index(0, domain.get_resolution());
    ResultsAggregation aggregator;
    PIApproximation display;

    int index;
    const int* BUFFER_POINTER;
    double ratio;

    const int NUM_SAMPLES = 10000000;
    for (int i = 0; i < NUM_SAMPLES; ++i) {
        index = random_index.generate();
        BUFFER_POINTER = domain.get_value(index);
        if (BUFFER_POINTER[0] < 0) {
            return 1;
        }
        aggregator.compute(BUFFER_POINTER[0]);
        if ((i % 1000000) == 0) {
            ratio = aggregator.get_ratio();
            display.compute_output(ratio);
            display.output();
        }
    }
    return 0;
}