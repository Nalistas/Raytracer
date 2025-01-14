/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"

namespace RayTracer {

    class Ray {
    public:
        Ray() = default;
        ~Ray() = default;

        Ray(Math::Point3D origin, Math::Vector3D direction, Color color = Color(255, 255, 255));

        Math::Point3D getOrigin() const;
        Math::Vector3D getDirection() const;
        RayTracer::Color getColor() const;

        void setOrigin(const Math::Point3D& origin);
        void setDirection(const Math::Vector3D& direction);
        void setColor(const Color& color);

    protected:
    private:
        Math::Point3D _origin;
        Math::Vector3D _direction;
        Color _color;
    };
}

#endif /* !RAY_HPP_ */
