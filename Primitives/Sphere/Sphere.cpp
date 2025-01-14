/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

extern "C" std::unique_ptr<RayTracer::IObject> entryPoint()
{
    return std::make_unique<RayTracer::Sphere>(Math::Point3D(0, 0, 0), 1);
}

RayTracer::Sphere::Sphere() :
    _radius(1)
{
    _position = Math::Point3D(0, 2, 0);
}

void RayTracer::Sphere::fromMap(std::map<std::string, float> params)
{
    _radius = params["radius"];
    _position = (Math::Point3D(params["x"], params["y"], params["z"]));
}

RayTracer::Sphere::Sphere(const Sphere &other) :
    _radius(other._radius)
{
    _position = other.getPosition();
}

Math::Point3D RayTracer::Sphere::getPosition() const
{
    return _position;
}

Math::Vector3D RayTracer::Sphere::getRotation() const
{
    return _rotation;
}

RayTracer::Sphere::Sphere(Math::Point3D const &center, double radius) :
    _radius(radius)
{
    _position = center;
}

struct RayTracer::bounce RayTracer::Sphere::hits(const Ray &ray)
{
    struct bounce bounce = {0, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0};
    const Math::Point3D &point = ray.getOrigin();
    const Math::Vector3D &vector = ray.getDirection();
    Math::Point3D center = _position;

    double a = vector.getX() * vector.getX() + vector.getY() * vector.getY() + vector.getZ() * vector.getZ(); // ||vector||^2
    double b = 2 * (vector.getX() * (point.getX() - center.getX()) + vector.getY() * (point.getY() - center.getY()) + vector.getZ() * (point.getZ() - center.getZ()));
    double c = (point.getX() - center.getX()) * (point.getX() - center.getX()) +
               (point.getY() - center.getY()) * (point.getY() - center.getY()) +
               (point.getZ() - center.getZ()) * (point.getZ() - center.getZ()) - _radius * _radius;

    double delta = b * b - 4 * a * c;

    if (delta < 0 || _radius == 0) {
        bounce.t = NAN;
        return bounce;
    }
    bounce.t = (-b - sqrt(delta)) / (2 * a);
    bounce.hitPosition = point + vector * bounce.t;
    bounce.normal = (bounce.hitPosition << center) / _radius;
    bounce.color = ray.getColor();
    return bounce;
}

void RayTracer::Sphere::printObject() const
{
    Math::Point3D center = _position;
    std::cout << "Sphere => coord (x y z): " << center.getX() << " " << center.getY() << " " << center.getZ() << " radius: " << _radius << std::endl;
}

double RayTracer::Sphere::getRadius() const
{
    return _radius;
}

std::map<std::string, std::string> RayTracer::Sphere::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "sphere";
    infos["x"] = std::to_string(_position.getX());
    infos["y"] = std::to_string(_position.getY());
    infos["z"] = std::to_string(_position.getZ());
    infos["radius"] = std::to_string(_radius);
    return infos;
}