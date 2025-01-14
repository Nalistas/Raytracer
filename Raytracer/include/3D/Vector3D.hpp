/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

    #include <cmath>
    #include <array>

namespace Math {
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Vector3D &other);
            Vector3D(std::array<int, 3>);
            ~Vector3D() = default;

            Vector3D &operator+=(const Vector3D &other);
            Vector3D operator+(const Vector3D &other) const;

            Vector3D &operator-=(const Vector3D &other);
            Vector3D operator-(const Vector3D &other) const;

            Vector3D &operator*=(const Vector3D &other);
            Vector3D operator*(const Vector3D &other) const;

            Vector3D &operator*=(double other);
            Vector3D operator*(double other) const;
            Vector3D &operator/=(double other);
            Vector3D operator/(double other) const;

            Vector3D &operator=(const Vector3D &other);
            Vector3D operator-() const;

            bool operator==(const Vector3D &other) const;
            double operator,(const Vector3D &other) const;
            double dotProduct(const Vector3D &other) const;
            double length() const;
            Math::Vector3D reflect(const Math::Vector3D &normal) const;
            Vector3D &normalize();
            Vector3D &rotateLatitude(double angle);
            Vector3D &rotateLongitude(double angle);
            Vector3D &rotateX(double angle);
            Vector3D &rotateY(double angle);
            Vector3D &rotateZ(double angle);
            Vector3D crossProduct(const Vector3D &other) const;

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

#endif /* !VECTOR3D_HPP_ */
