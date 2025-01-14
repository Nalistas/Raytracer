/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Point3D
*/

#include "3D/Point3D.hpp"

Math::Point3D::Point3D() :
    _x(0), _y(0), _z(0)
{}

Math::Point3D::Point3D(double x, double y, double z) :
    _x(x), _y(y), _z(z)
{}

Math::Point3D::Point3D(std::array<double, 3> arr) :
    _x(arr[0]), _y(arr[1]), _z(arr[2])
{}

Math::Point3D::Point3D(const Point3D &other) :
    _x(other._x), _y(other._y), _z(other._z)
{}

Math::Point3D &Math::Point3D::operator+=(const Vector3D &other)
{
    _x += other.getX();
    _y += other.getY();
    _z += other.getZ();
    return *this;
}

Math::Point3D Math::Point3D::operator+(const Vector3D &other) const
{
    return Point3D(_x + other.getX(), _y + other.getY(), _z + other.getZ());
}

Math::Point3D &Math::Point3D::operator-=(const Vector3D &other)
{
    _x -= other.getX();
    _y -= other.getY();
    _z -= other.getZ();
    return *this;
}

Math::Point3D Math::Point3D::operator-(const Vector3D &other) const
{
    return Point3D(_x - other.getX(), _y - other.getY(), _z - other.getZ());
}

Math::Vector3D Math::Point3D::operator>>(const Point3D &other) const
{
    return Vector3D(other._x - _x, other._y - _y, other._z - _z);
}

Math::Vector3D Math::Point3D::operator<<(const Point3D &other) const
{
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

Math::Point3D &Math::Point3D::operator=(const Point3D &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

Math::Point3D &Math::Point3D::operator-=(const Point3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

Math::Point3D Math::Point3D::operator-(const Point3D &other) const
{
    return Point3D(_x - other._x, _y - other._y, _z - other._z);
}

Math::Point3D &Math::Point3D::operator+=(const Point3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

Math::Point3D Math::Point3D::operator+(const Point3D &other) const
{
    return Point3D(_x + other._x, _y + other._y, _z + other._z);
}

bool Math::Point3D::operator==(const Point3D &other) const
{
    return round(this->_x) == round(other._x) && round(this->_y) == round(other._y) && round(this->_z) == round(other._z);
}

bool Math::Point3D::operator!=(const Point3D &other) const
{
    return !(*this == other);
}

double Math::Point3D::getX() const {
    return _x;
}

double Math::Point3D::getY() const {
    return _y;
}

double Math::Point3D::getZ() const {
    return _z;
}

void Math::Point3D::setX(double x) {
    _x = x;
}

void Math::Point3D::setY(double y) {
    _y = y;
}

void Math::Point3D::setZ(double z) {
    _z = z;
}