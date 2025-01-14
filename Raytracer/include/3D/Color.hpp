/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color
*/
#include <array>

#ifndef COLOR_HPP_
    #define COLOR_HPP_

namespace RayTracer {
    class Color {
    private:
        double _r;
        double _g;
        double _b;
        void checkColor();

    public:
        Color();
        Color(int r, int g, int b);
        Color(double r, double g, double b);
        Color(const Color &other);
        Color(std::array<int, 3> &color);
        Color(std::array<double, 3> &color);
        ~Color();

        bool operator==(const Color &other) const;
        bool operator!=(const Color &other) const;
        Color &operator=(const Color &other);
        Color &operator*=(double other);
        Color operator*(double other) const;
        Color &operator<<=(const Color &other);
        Color operator+(const Color &other) const;
        Color operator-(const Color &other) const;
        Color &operator+=(const Color &other);


        double rf() const;
        double gf() const;
        double bf() const;

        void setf(double r, double g, double b);
        int ri() const;
        int gi() const;
        int bi() const;
        void seti(int r, int g, int b);

        void reverseLight();
    };
}

#endif /* !COLOR_HPP_ */
