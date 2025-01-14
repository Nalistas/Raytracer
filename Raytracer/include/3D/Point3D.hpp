/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "Vector3D.hpp"
#include <array>

namespace Math {
    class Point3D {
    public:
        Point3D();
        Point3D(const Point3D &other);
        Point3D(double x, double y, double z);
        Point3D(std::array<double, 3> arr);
        ~Point3D() = default;

        Point3D &operator+=(const Vector3D &other);
        Point3D operator+(const Vector3D &other) const;
        Point3D &operator-=(const Vector3D &other);
        Point3D operator-(const Vector3D &other) const;

        Point3D &operator-=(const Point3D &other);
        Point3D operator-(const Point3D &other) const;
        Point3D &operator+=(const Point3D &other);
        Point3D operator+(const Point3D &other) const;

        Point3D &operator=(const Point3D &other);

        Vector3D operator>>(const Point3D &other) const;
        Vector3D operator<<(const Point3D &other) const;

        bool operator==(const Point3D &other) const;
        bool operator!=(const Point3D &other) const;

        double getX() const;
        double getY() const;
        double getZ() const;

        void setX(double x);
        void setY(double y);
        void setZ(double z);

    private:
        double _x;
        double _y;
        double _z;
    };
}

#endif /* !POINT3D_HPP_ */
