/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector3D
*/

#include "3D/Vector3D.hpp"

Math::Vector3D::Vector3D() :
    _x(0), _y(0), _z(0)
{}

Math::Vector3D::Vector3D(double x, double y, double z) :
    _x(x), _y(y), _z(z)
{}

Math::Vector3D::Vector3D(const Vector3D &other) :
    _x(other._x), _y(other._y), _z(other._z)
{}

Math::Vector3D::Vector3D(std::array<int, 3> array) :
    _x(array[0]), _y(array[1]), _z(array[2])
{}

double Math::Vector3D::length() const
{
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}

Math::Vector3D Math::Vector3D::operator+(const Vector3D &other) const
{
    return Vector3D(_x + other._x, _y + other._y, _z + other._z);
}

Math::Vector3D Math::Vector3D::operator-(const Vector3D &other) const
{
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

Math::Vector3D Math::Vector3D::operator*(double other) const
{
    return Vector3D(_x * other, _y * other, _z * other);
}

Math::Vector3D Math::Vector3D::operator/(double other) const
{
    return Vector3D(_x, _y, _z) /= other;
}

Math::Vector3D &Math::Vector3D::operator*=(double other)
{
    _x *= other;
    _y *= other;
    _z *= other;
    if (_x == 0) {
        _x = 0;
    }
    if (_y == 0) {
        _y = 0;
    }
    if (_z == 0) {
        _z = 0;
    }
    return *this;
}

Math::Vector3D &Math::Vector3D::operator/=(double other)
{
    if (other == 0) {
        _x = 0;
        _y = 0;
        _z = 0;
        return *this;
    }
    if (_x != 0) {
        _x /= other;
    }
    if (_y != 0) {
        _y /= other;
    }
    if (_z != 0) {
        _z /= other;
    }
    return *this;
}

Math::Vector3D &Math::Vector3D::operator+=(const Vector3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator-=(const Vector3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator=(const Vector3D &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator-() const
{
    return *this * -1.0;
}



Math::Vector3D Math::Vector3D::operator*(const Vector3D &other) const
{
    return Vector3D(*this) *= other;
}

Math::Vector3D &Math::Vector3D::operator*=(const Vector3D &other)
{
    _x = _y * other._z - _z * other._y;
    _y = _z * other._x - _x * other._z;
    _z = _x * other._y - _y * other._x;
    return *this;
}

double Math::Vector3D::operator,(const Vector3D &other) const
{
    return dotProduct(other);
}

double Math::Vector3D::dotProduct(const Vector3D &other) const
{
    return _x * other._x + _y * other._y + _z * other._z;
}

bool Math::Vector3D::operator==(const Vector3D &other) const
{
    return round(_x) == round(other._x) && round(_y) == round(other._y) && round(_z) == round(other._z);
}

Math::Vector3D &Math::Vector3D::normalize()
{
    double length = this->length();
    if (length == 0) {
        _x = 0;
        _y = 0;
        _z = 0;
        return *this;
    }
    _x /= length;
    _y /= length;
    _z /= length;
    return *this;
}

Math::Vector3D &Math::Vector3D::rotateLatitude(double angle)
{
    double x = _x;
    _x = x * cos(angle) - _z * sin(angle);
    _z = x * sin(angle) + _z * cos(angle);
    return *this;
}

Math::Vector3D &Math::Vector3D::rotateLongitude(double angle)
{
    double y = _y;
    _y = y * cos(angle) - _z * sin(angle);
    _z = y * sin(angle) + _z * cos(angle);
    return *this;
}

Math::Vector3D &Math::Vector3D::rotateX(double angle)
{
    double y = _y;
    double z = _z;
    _y = y * cos(angle) - z * sin(angle);
    _z = y * sin(angle) + z * cos(angle);
    return *this;
}

Math::Vector3D &Math::Vector3D::rotateY(double angle)
{
    double x = _x;
    double z = _z;
    _x = x * cos(angle) - z * sin(angle);
    _z = x * sin(angle) + z * cos(angle);
    return *this;
}

Math::Vector3D &Math::Vector3D::rotateZ(double angle)
{
    double x = _x;
    double y = _y;
    _x = x * cos(angle) - y * sin(angle);
    _y = x * sin(angle) + y * cos(angle);
    return *this;
}

Math::Vector3D Math::Vector3D::reflect(const Math::Vector3D& other) const
{
    double dot = dotProduct(other);
    return (other) - (*this * (2.0 * dot)).normalize();
}


Math::Vector3D Math::Vector3D::crossProduct(const Vector3D &other) const
{
    return Math::Vector3D(
        _y * other._z - _z * other._y,
        _z * other._x - _x * other._z,
        _x * other._y - _y * other._x
    );
}

double Math::Vector3D::getX() const { 
    return _x; 
}

double Math::Vector3D::getY() const { 
    return _y; 
}

double Math::Vector3D::getZ() const { 
    return _z; 
}

void Math::Vector3D::setX(double x) { 
    _x = x; 
}

void Math::Vector3D::setY(double y) { 
    _y = y; 
}

void Math::Vector3D::setZ(double z) { 
    _z = z; 
}
