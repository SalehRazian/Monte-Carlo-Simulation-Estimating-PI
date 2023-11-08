#include "../include/inputs_domain.hpp"

// Constructors
SquaredCircleDomain::SquaredCircleDomain(int side_length) 
    : SIDE_LENGTH(side_length), 
      RADIUS(side_length / 2.0f), 
      RADIUS_SQUARED(RADIUS * RADIUS),
      RESOLUTION(side_length * side_length)
{}

// Member Functions
SquaredCircleDomain::Point::Point() : x(-1), y(-1) {}

bool SquaredCircleDomain::Point::isInvalid() const {
    return x < 0 || y < 0;
}

// Public Functions
int SquaredCircleDomain::get_domain_buffer_size() const {
    return DOMAIN_BUFFER_SIZE;
}

int SquaredCircleDomain::get_resolution() const {
    return RESOLUTION;
}

const int* SquaredCircleDomain::get_value(int index) {
    Point domain_index = domain_translator(index);
    if (domain_index.isInvalid()) {
        domain_buffer[0] = -1;
        return domain_buffer;
    }
    domain_fetch(domain_index);
    return domain_buffer;
}

// Private Functions
SquaredCircleDomain::Point SquaredCircleDomain::domain_translator(int linear_position) {
    Point position;
    if (linear_position > RESOLUTION) {
        return position;
    }
    position.x = linear_position / SIDE_LENGTH;

    // More efficient than % function : depending on the compiler and architecture
    position.y = linear_position - (position.x * SIDE_LENGTH);
    return position;
}

void SquaredCircleDomain::domain_fetch(Point position) {
    float dx = position.x - RADIUS;
    float dy = position.y - RADIUS;
    domain_buffer[0] = ((dx * dx) + (dy * dy)) <= RADIUS_SQUARED;
}