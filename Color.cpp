#include "Color.hpp"

//implementations for non inline functions
Color:: Color(double r, 
              double g, 
              double b) : R(r), G(g), B(b) {}

Color::Color() : R(0.0), G(0.0), B(0.0) {}

Color Color::add(const Color &other) {
    return Color(R + other.R, 
                 G + other.G, 
                 B + other.B);
}

Color Color::operator+(const Color &other) {
    R += other.R;
    G += other.G;
    B += other.B;
    return *this;
}

Color Color::add(double scalar) {
    return Color(R + scalar, 
                 G + scalar, 
                 B + scalar);
}

Color Color::operator+(double scalar) {
    R += scalar;
    G += scalar;
    B += scalar;
    return *this;
}

Color Color::mult_scalar(double scalar) {
    return Color(R * scalar, 
                 G * scalar, 
                 B * scalar);
}

Color Color::operator*(double scalar) {
    return Color(R * scalar, 
                 G * scalar, 
                 B * scalar);
}

void Color::cap() {
    if (R > 1.0) R = 1.0;
    if (G > 1.0) G = 1.0;
    if (B > 1.0) B = 1.0;
}
