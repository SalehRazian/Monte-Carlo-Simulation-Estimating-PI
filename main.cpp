#include "include/inputs_domain.hpp"
#include "include/inputs_generator.hpp"
#include "include/results_calculation.hpp"
#include "include/results_output.hpp"
#include "include/SFML/Graphics.hpp"

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
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}