/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** Cone
*/

#include "Cone.hpp"

extern "C" std::unique_ptr<RayTracer::IObject> entryPoint()
{
    return std::make_unique<RayTracer::Cone>();
}

RayTracer::Cone::Cone() :
    _radius(1)
{
    _position = Math::Point3D(0, 5, 0);
    _rotation = Math::Vector3D(0, 0, 1);
}

RayTracer::Cone::Cone(const Cone &other) :
    _radius(other._radius)
{
    _position = other.getPosition();
    _rotation = other.getRotation();
}

Math::Point3D RayTracer::Cone::getPosition() const
{
    return _position;
}

Math::Vector3D RayTracer::Cone::getRotation() const
{
    return _rotation;
}

RayTracer::Cone::Cone(Math::Point3D const &position, Math::Vector3D const &rotation, double radius) :
    _radius(radius)
{
    _position = position;
    _rotation = rotation;
}

void RayTracer::Cone::fromMap(std::map<std::string, float> params)
{
    _radius = params["radius"];
    _position = (Math::Point3D(params["x"], params["y"], params["z"]));
    _rotation = (Math::Vector3D(params["normal_x"], params["normal_y"], params["normal_z"]));
}


struct RayTracer::bounce RayTracer::Cone::hits(const Ray &ray)
{
    Ray tmp_ray(ray);
    const Math::Point3D &pos = tmp_ray.getOrigin();
    const Math::Vector3D &dir = tmp_ray.getDirection();
    struct bounce bnce = {0, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0};
    Math::Point3D center = _position;

    // correct cone equation with no height and no radius
    // double a = dir._x * dir._x + dir._y * dir._y - dir._z * dir._z;
    // double b = (2 * (pos._x - _center._x) * dir._x) + (2 * (pos._y - _center._y) * dir._y) - (2 * (pos._z - _center._z) * dir._z);
    // double c = (pos._x - _center._x) * (pos._x - _center._x) + (pos._y - _center._y) * (pos._y - _center._y) - (pos._z - _center._z) * (pos._z - _center._z);

    // correct cone equation with radius
    double a = dir.getX() * dir.getX() + dir.getY() * dir.getY() - dir.getZ() * dir.getZ() * (_radius * _radius);
    double b = 2 * ((pos.getX() - center.getX()) * dir.getX() + (pos.getY() - center.getY()) * dir.getY() - (pos.getZ() - center.getZ()) * dir.getZ() * (_radius * _radius));
    double c = (pos.getX() - center.getX()) * (pos.getX() - center.getX()) + (pos.getY() - center.getY()) * (pos.getY() - center.getY()) - (pos.getZ() - center.getZ()) * (pos.getZ() - center.getZ()) * (_radius * _radius);

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        bnce.t = NAN;
        return bnce;
    }

    bnce.t = (-b - sqrt(delta)) / (2 * a);
    bnce.hitPosition = pos + dir * bnce.t;
    bnce.normal = (bnce.hitPosition << center) / _radius;
    bnce.normal.setZ(-bnce.normal.getZ());
    bnce.color = ray.getColor();
    return bnce;
}

void RayTracer::Cone::printObject() const
{
    Math::Point3D center = _position;
    std::cout << "Cone => coord (x y z): " << center.getX() << " " << center.getY() << " " << center.getZ() << " radius: " << _radius << std::endl;
}

double RayTracer::Cone::getRadius() const
{
    return _radius;
}

std::map<std::string, std::string> RayTracer::Cone::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "cone";
    infos["x"] = std::to_string(_position.getX());
    infos["y"] = std::to_string(_position.getY());
    infos["z"] = std::to_string(_position.getZ());
    infos["normal_x"] = std::to_string(_rotation.getX());
    infos["normal_y"] = std::to_string(_rotation.getY());
    infos["normal_z"] = std::to_string(_rotation.getZ());
    infos["radius"] = std::to_string(_radius);
    return infos;
}
