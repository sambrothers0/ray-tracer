#ifndef COLOR_HPP
#define COLOR_HPP

// class definition for color, containing arithmetic operations, cap function, and getter functions for color channels
class Color {
private:
    double R;
    double G;
    double B;

public:
    Color(double r, 
          double g, 
          double b);

    Color();

    double getR() const { return R; }
    double getG() const { return G; }
    double getB() const { return B; }

    Color add(const Color &other);
    Color operator+(const Color &other);

    Color add(double value);
    Color operator+(double value);

    Color mult_scalar(double scalar);
    Color operator*(double scalar);

    void cap(void);
};

#endif