/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Rectangle3D
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"

#ifndef RECTANGLE3D_HPP_
    #define RECTANGLE3D_HPP_

namespace Math
{
    class Rectangle3D {
        public:
            Rectangle3D() = default;
            ~Rectangle3D() = default;
            Point3D pointAt(double u, double v) const;

            Point3D getOrigin();
            Vector3D getLeft();
            Vector3D getBottom();
            
            void setOrigin(const Point3D& origin);
            void setLeft(const Vector3D& left);
            void setBottom(const Vector3D& bottom);
        
        private:
            Point3D _origin;
            Vector3D _left;
            Vector3D _bottom;
    };
}

#endif /* !RECTANGLE3D_HPP_ */
