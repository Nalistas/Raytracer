/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

extern "C" std::unique_ptr<RayTracer::IObject> entryPoint()
{
    return std::make_unique<RayTracer::Plane>();
}

RayTracer::Plane::Plane()
{
    _position = Math::Point3D(0, 5, 0);
    _rotation = Math::Vector3D(0, 0, 1);
    _rotation.normalize();
}

RayTracer::Plane::Plane(Math::Point3D const &point, Math::Vector3D const &rotation)
{
    _position = point;
    _rotation = rotation;
    _rotation.normalize();
}

void RayTracer::Plane::fromMap(std::map<std::string, float> params)
{
    _position = Math::Point3D(params["x"], params["y"], params["z"]);
    _rotation = Math::Vector3D(params["normal_x"], params["normal_y"], params["normal_z"]);
    _rotation.normalize();
}

struct RayTracer::bounce RayTracer::Plane::hits(const Ray &r)
{
    double denom = _rotation.dotProduct(r.getDirection());
    bounce b = {NAN, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0};

    if (denom == 0)
        return b;

    double t = -(_rotation.dotProduct(r.getOrigin() << _position) / denom);
    if (t < 0)
        return b;

    Math::Vector3D n = _rotation;
    if (n.dotProduct(r.getDirection()) > 0)
        n *= -1;

    Math::Point3D hit = r.getOrigin() + r.getDirection() * t;

    b.t = t;
    b.hitPosition = hit;
    b.normal = n;
    b.color = r.getColor();
    return b;
}

void RayTracer::Plane::printObject() const
{
    Math::Point3D position = _position;
    Math::Vector3D normal = _rotation;
    std::cout << "Plane => coord (x y z): " << position.getX() << " " << position.getY() << " " << position.getZ() << " normal (x y z): " << normal.getX() << " " << normal.getY() << " " << normal.getZ() << std::endl;
}

Math::Point3D RayTracer::Plane::getP1() const
{
    return _position;
}

Math::Vector3D RayTracer::Plane::getNormal() const
{
    return _rotation;
}

std::map<std::string, std::string> RayTracer::Plane::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "plane";    
    infos["x"] = _position.getX();
    infos["y"] = _position.getY();
    infos["z"] = _position.getZ();
    infos["normal_x"] = _rotation.getX();
    infos["normal_y"] = _rotation.getY();
    infos["normal_z"] = _rotation.getZ();
    return infos;
}
