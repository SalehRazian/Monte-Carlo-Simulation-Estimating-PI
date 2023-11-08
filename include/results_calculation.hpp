// Could have used #pragma once
#ifndef RESULTS_CALCULATION_HPP
#define RESULTS_CALCULATION_HPP

class ResultsAggregation {
    private:
        int total_inputs = 0;
        int inputs_sum = 0;

    public:
        void compute(int value);
        double get_ratio();
        int get_total_inputs();
        int get_inputs_sum();
};

#endif