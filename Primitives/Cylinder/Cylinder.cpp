/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

extern "C" std::unique_ptr<RayTracer::IObject> entryPoint()
{
    return std::make_unique<RayTracer::Cylinder>();
}

RayTracer::Cylinder::Cylinder() :
    _radius(1)
{
    _position = Math::Point3D(0, 5, 0);
}

RayTracer::Cylinder::Cylinder(const Cylinder &other) :
    _radius(other._radius)
{
    _position = other.getPosition();
}

Math::Point3D RayTracer::Cylinder::getPosition() const
{
    return _position;
}

void RayTracer::Cylinder::fromMap(std::map<std::string, float> params)
{
    _radius = params["radius"];
    _position = (Math::Point3D(params["x"], params["y"], params["z"]));
}


RayTracer::Cylinder::Cylinder(Math::Point3D const &position, double radius) :
    _radius(radius)
{
    _position = position;
}

struct RayTracer::bounce RayTracer::Cylinder::hits(const Ray &ray)
{
    struct bounce bnce = {0, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0};
    Ray tmp_ray(ray);
    const Math::Point3D &ori = tmp_ray.getOrigin();
    const Math::Vector3D &dir = tmp_ray.getDirection();
    Math::Point3D tmp_center = getPosition();
    Math::Point3D center = getPosition();

    double a = dir.getX() * dir.getX() + dir.getY() * dir.getY();
    double b = 2 * (dir.getX() * (ori.getX() - center.getX()) + dir.getY() * (ori.getY() - center.getY()));
    double c = (ori.getX() - center.getX()) * (ori.getX() - center.getX()) +
               (ori.getY() - center.getY()) * (ori.getY() - center.getY()) - _radius * _radius;

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        bnce.t = NAN;
        return bnce;
    }
    bnce.t = (-b - sqrt(delta)) / (2 * a);
    bnce.hitPosition = ori + dir * bnce.t;
    tmp_center.setZ(bnce.hitPosition.getZ());
    bnce.normal = (bnce.hitPosition << tmp_center) / _radius;
    bnce.color = ray.getColor();
    return bnce;
}


void RayTracer::Cylinder::printObject() const
{
    Math::Point3D center = _position;
    std::cout << "Cylinder => coord (x y z): " << center.getX() << " " << center.getY() << " " << center.getZ() << " radius: " << _radius << std::endl;
}

double RayTracer::Cylinder::getRadius() const
{
    return _radius;
}

std::map<std::string, std::string> RayTracer::Cylinder::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "cylinder";
    infos["x"] = std::to_string(_position.getX());
    infos["y"] = std::to_string(_position.getY());
    infos["z"] = std::to_string(_position.getZ());
    infos["radius"] = std::to_string(_radius);
    return infos;
}
