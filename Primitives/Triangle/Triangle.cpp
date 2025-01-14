/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** Triangle
*/

#include "Triangle.hpp"

extern "C" std::unique_ptr<RayTracer::IObject> entryPoint()
{
    return std::make_unique<RayTracer::Triangle>();
}

RayTracer::Triangle::Triangle() :
    _p1(0, 0, 0), _p2(1, 0, 0), _p3(0, 1, 0)
{}

RayTracer::Triangle::Triangle(const Triangle &other) :
    _p1(other._p1), _p2(other._p2), _p3(other._p3)
{}

RayTracer::Triangle::Triangle(Math::Point3D const &p1, Math::Point3D const &p2, Math::Point3D const &p3) :
    _p1(p1), _p2(p2), _p3(p3)
{}

void RayTracer::Triangle::fromMap(std::map<std::string, float> params)
{
    _position = Math::Point3D(params["x"], params["y"], params["z"]);
    _rotation = Math::Vector3D(params["normal_x"], params["normal_y"], params["normal_z"]);
}


RayTracer::bounce RayTracer::Triangle::hits(const Ray &ray)
{
    struct bounce bounce = {NAN, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0};

    const Math::Point3D &origin = ray.getOrigin();
    const Math::Vector3D &direction = ray.getDirection();

    Math::Vector3D e1 = _p3 - _p1;
    Math::Vector3D e2 = _p2 - _p1;
    Math::Vector3D h = direction.crossProduct(e2);
    double det = e1.dotProduct(h);

    if (std::abs(det) < 1e-8) {
        return bounce;
    }

    double f = 1.0 / a;
    Math::Vector3D s = origin - _p1;
    double u = f * s.dotProduct(h);

    if (u < 0.0 || u > 1.0) {
        return bounce;
    }

    Math::Vector3D q = s.crossProduct(e1);
    double v = f * direction.dotProduct(q);

    if (v < 0.0 || u + v > 1.0) {
        return bounce;
    }

    double t = f * e2.dotProduct(q);

    if (t > 0.1 && (std::isnan(bounce.t) || t < bounce.t)) {
        bounce.t = t;
        bounce.hitPosition = origin + direction * t;

        Math::Vector3D normal = e1.crossProduct(e2);
        normal.normalize();
        bounce.normal = normal;
    }

    return bounce;
}

void RayTracer::Triangle::printObject() const
{
    std::cout << "Triangle => points: (" << _p1.getX() << ", " << _p1.getY() << ", " << _p1.getZ() << "), "
              << "(" << _p2.getX() << ", " << _p2.getY() << ", " << _p2.getZ() << "), "
              << "(" << _p3.getX() << ", " << _p3.getY() << ", " << _p3.getZ() << ")" << std::endl;
}

std::map<std::string, std::string> RayTracer::Triangle::getInfos() const
{
    std::map<std::string, std::string> infos;
    infos["type"] = "triangle";
    infos["x1"] = _p1.getX();
    infos["y1"] = _p1.getY();
    infos["z1"] = _p1.getZ();
    infos["x2"] = _p2.getX();
    infos["y2"] = _p2.getY();
    infos["z2"] = _p2.getZ();
    infos["x3"] = _p3.getX();
    infos["y3"] = _p3.getY();
    infos["z3"] = _p3.getZ();
    return infos;
}
