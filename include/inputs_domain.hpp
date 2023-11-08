// Could have used #pragma once
#ifndef INPUT_DOMAIN_HPP
#define INPUT_DOMAIN_HPP

class SquaredCircleDomain {
    private:

        // Domain Environment
        const int SIDE_LENGTH;
        const float RADIUS;
        const float RADIUS_SQUARED;
        const int RESOLUTION;

        // Buffers
        static const int DOMAIN_BUFFER_SIZE = 1;
        int domain_buffer[DOMAIN_BUFFER_SIZE];

        // Structures
        struct Point{
            int x;
            int y;
            Point();
            bool isInvalid() const;
        };

    public:
        SquaredCircleDomain(int side_length);
        int get_domain_buffer_size() const;
        int get_resolution() const;
        const int* get_value(int index);

    private:
        Point domain_translator(int linear_position);
        void domain_fetch(Point position);
};

#endif