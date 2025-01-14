/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color
*/

#include "3D/Color.hpp"

RayTracer::Color::Color() : _r(0), _g(0), _b(0)
{}

RayTracer::Color::Color(int r, int g, int b) : _r(0), _g(0), _b(0)
{
    seti(r, g, b);
}

RayTracer::Color::Color(double r, double g, double b) : _r(0), _g(0), _b(0)
{
    setf(r, g, b);
}

RayTracer::Color::Color(const Color &other) : _r(other._r), _g(other._g), _b(other._b)
{}

RayTracer::Color::Color(std::array<int, 3> &color) : _r(0), _g(0), _b(0)
{
    seti(color[0], color[1], color[2]);
}

RayTracer::Color::Color(std::array<double, 3> &color) : _r(0), _g(0), _b(0)
{
    setf(color[0], color[1], color[2]);
}

RayTracer::Color::~Color() = default;

RayTracer::Color &RayTracer::Color::operator=(const Color &other)
{
    _r = other._r;
    _g = other._g;
    _b = other._b;
    checkColor();
    return *this;
}

RayTracer::Color &RayTracer::Color::operator*=(double other)
{
    _r *= other;
    _g *= other;
    _b *= other;
    checkColor();
    return *this;
}

RayTracer::Color &RayTracer::Color::operator<<=(const Color &other)
{
    _r = (_r > other._r) ? _r : other._r;
    _g = (_g > other._g) ? _g : other._g;
    _b = (_b > other._b) ? _b : other._b;
    checkColor();
    return *this;
}

RayTracer::Color RayTracer::Color::operator+(const Color &other) const
{
    return Color(_r + other._r, _g + other._g, _b + other._b);
}

RayTracer::Color RayTracer::Color::operator-(const Color &other) const
{
    
    return Color(_r - other._r, _g - other._g, _b - other._b);
}

RayTracer::Color &RayTracer::Color::operator+=(const Color &other)
{
    _r += other._r;
    _g += other._g;
    _b += other._b;
    checkColor();
    return *this;
}

double RayTracer::Color::rf() const
{
    return _r;
}

double RayTracer::Color::gf() const
{
    return _g;
}

double RayTracer::Color::bf() const
{
    return _b;
}

void RayTracer::Color::setf(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
    checkColor();
}

int RayTracer::Color::ri() const
{
    return (int)(_r * 255);
}

int RayTracer::Color::gi() const
{
    return (int)(_g * 255);
}

int RayTracer::Color::bi() const
{
    return (int)(_b * 255);
}

void RayTracer::Color::seti(int r, int g, int b)
{
    _r = ((double)r) / 255;
    _g = ((double)g) / 255;
    _b = ((double)b) / 255;
    checkColor();
}

void RayTracer::Color::checkColor()
{
    if (_r > 1) _r = 1;
    if (_g > 1) _g = 1;
    if (_b > 1) _b = 1;
    if (_r < 0) _r = 0;
    if (_g < 0) _g = 0;
    if (_b < 0) _b = 0;
}

void RayTracer::Color::reverseLight()
{
    _r = 1 - _r;
    _g = 1 - _g;
    _b = 1 - _b;
    checkColor();
}

bool RayTracer::Color::operator==(const Color &other) const
{
    return _r == other._r && _g == other._g && _b == other._b;
}

bool RayTracer::Color::operator!=(const Color &other) const
{
    return _r != other._r || _g != other._g || _b != other._b;
}

RayTracer::Color RayTracer::Color::operator*(double other) const
{
    return Color(_r * other, _g * other, _b * other);
}
