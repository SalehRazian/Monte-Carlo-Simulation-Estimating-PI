// Could have used #pragma once
#ifndef RESULTS_OUTPUT_HPP
#define RESULTS_OUTPUT_HPP

class PIApproximation {
    private:
        static constexpr double PI = 3.141592653589;
        double pi_approximation;

    public:
        void compute_output(double results);
        void output();

    // private:
    // void compute_pi();

};

#endif