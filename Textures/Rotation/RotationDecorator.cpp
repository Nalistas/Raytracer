/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ColorLight
*/

#include "RotationDecorator.hpp"
#include <cmath>
#include <iostream>
#include <string>

RayTracer::RotationDecorator::RotationDecorator(std::unique_ptr<IObject> object,
    Math::Point3D rotationCenter, double angle1, double angle2) :
    IObjectDecorator(std::move(object)), _rotationCenter(rotationCenter), _angle1(angle1), _angle2(angle2)
{}

struct RayTracer::bounce RayTracer::RotationDecorator::hits(const Ray &ray)
{
    Math::Vector3D v = (_rotationCenter >> ray.getOrigin());
    v.rotateX(-_angle1);
    v.rotateZ(-_angle2);
    Math::Vector3D v2 = ray.getDirection();
    v2.rotateX(_angle1);
    v2.rotateZ(_angle2);

    Ray newRay(_rotationCenter + v, v2, ray.getColor());
    struct bounce bnce = _object->hits(newRay);
    // if (!std::isnan(bnce.t) && bnce.t > 0) {
    //     Math::Vector3D normal = bnce.hitPosition << _rotationCenter;
    //     normal.normalize();
    //     normal.rotateX(_angle1);
    //     normal.rotateZ(_angle2);
    //     bnce.normal = normal;
    //     Math::Vector3D hitPosition = bnce.hitPosition << _rotationCenter;
    //     hitPosition.rotateX(_angle1);
    //     hitPosition.rotateZ(_angle2);
    //     bnce.hitPosition = _rotationCenter + hitPosition;
    // }
    return bnce;
}

Math::Point3D RayTracer::RotationDecorator::getRotationCenter() const
{
    return _rotationCenter;
}

double RayTracer::RotationDecorator::getRotationAngle1() const
{
    return _angle1;
}

double RayTracer::RotationDecorator::getRotationAngle2() const
{
    return _angle2;
}

void RayTracer::RotationDecorator::printObject() const
{
    std::cout << "RotationDecorator => rotationCenter: "
        << _rotationCenter.getX() << " " << _rotationCenter.getY() << " " << _rotationCenter.getZ()
        << " angle1: " << _angle1 << " angle2: " << _angle2 << std::endl;
}

std::map<std::string, std::string> RayTracer::RotationDecorator::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["rotation_x"] = std::to_string(_rotationCenter.getX());
    infos["rotation_y"] = std::to_string(_rotationCenter.getY());
    infos["rotation_z"] = std::to_string(_rotationCenter.getZ());
    infos["angle1"] = std::to_string(_angle1);
    infos["angle2"] = std::to_string(_angle2);
    return infos;
}

void RayTracer::RotationDecorator::fromMap(std::map<std::string, float> params)
{
    _rotationCenter = Math::Point3D(params["rotation_x"], params["rotation_y"], params["rotation_z"]);
    _angle1 = params["angle1"];
    _angle2 = params["angle2"];
}
