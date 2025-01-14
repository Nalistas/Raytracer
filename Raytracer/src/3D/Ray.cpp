/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray
*/

#include "3D/Ray.hpp"

RayTracer::Ray::Ray(Math::Point3D origin, Math::Vector3D direction, Color color) :
    _origin(origin), _direction(direction), _color(color)
{}

Math::Point3D RayTracer::Ray::getOrigin() const {
    return _origin;
}

Math::Vector3D RayTracer::Ray::getDirection() const {
    return _direction;
}

RayTracer::Color RayTracer::Ray::getColor() const {
    return _color;
}

void RayTracer::Ray::setOrigin(const Math::Point3D& origin) {
    _origin = origin;
}

void RayTracer::Ray::setDirection(const Math::Vector3D& direction) {
    _direction = direction;
}

void RayTracer::Ray::setColor(const Color& color) {
    _color = color;
}