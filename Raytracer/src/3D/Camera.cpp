/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#include "3D/Camera.hpp"

RayTracer::Camera::Camera() :
    _origin(0, -1, 0), _resolutionX(700), _resolutionY(700)
{
    _screen.setOrigin(Math::Point3D(0, 0, 0));
    _screen.setBottom(Math::Vector3D(0, 0, 1));
    _screen.setLeft(Math::Vector3D(1, 0, 0));
}

void RayTracer::Camera::setScreen(Math::Rectangle3D screen)
{
    _screen = screen;
}

void RayTracer::Camera::setOrigin(Math::Point3D origin)
{
    _origin = origin;
}

void RayTracer::Camera::setResolution(std::size_t x, std::size_t y)
{
    _resolutionX = x;
    _resolutionY = y;
}

void RayTracer::Camera::moveTo(Math::Point3D point)
{
    Math::Vector3D vector(_origin >> _screen.getOrigin());

    _origin = point;
    _screen.setOrigin(point + vector);
}

void RayTracer::Camera::moveBy(Math::Vector3D vector)
{
    moveTo(_origin + vector);
}

double RayTracer::Camera::getHeightInc(double start, double end) const
{
    return (end - start) / std::min(_resolutionY, _resolutionX);
}

double RayTracer::Camera::getWidthInc(double start, double end) const
{
    return (end - start) / std::min(_resolutionY, _resolutionX);
}

double RayTracer::Camera::getResolutionX() const
{
    return _resolutionX;
}

double RayTracer::Camera::getResolutionY() const
{
    return _resolutionY;
}

RayTracer::Ray RayTracer::Camera::ray(double x, double y) const
{
    x = x - (_resolutionX / 2.0);
    y = y - (_resolutionY / 2.0);
    x = x / std::min(_resolutionY, _resolutionX);
    y = y / std::min(_resolutionY, _resolutionX);
    Math::Point3D screenPoint(this->_screen.pointAt(x, y));
    Math::Vector3D vector(_origin >> screenPoint);

    vector.normalize();
    return Ray(_origin, vector);
}

void RayTracer::Camera::rotateX(double angle)
{
    Math::Vector3D vec(_origin >> _screen.getOrigin());

    vec.rotateX(angle);
    _screen.setOrigin(_origin + vec);
    _screen.setBottom(_screen.getBottom().rotateX(angle));
    _screen.setLeft(_screen.getLeft().rotateX(angle));
}

void RayTracer::Camera::rotateY(double angle)
{
    Math::Vector3D vec(_origin >> _screen.getOrigin());

    vec.rotateY(angle);
    _screen.setOrigin(_origin + vec);
    _screen.setBottom(_screen.getBottom().rotateY(angle));
    _screen.setLeft(_screen.getLeft().rotateY(angle));
}

void RayTracer::Camera::rotateZ(double angle)
{
    Math::Vector3D vec(_origin >> _screen.getOrigin());

    vec.rotateZ(angle);
    _screen.setOrigin(_origin + vec);
    _screen.setBottom(_screen.getBottom().rotateZ(angle));
    _screen.setLeft(_screen.getLeft().rotateZ(angle));
}

std::array<int, 3> RayTracer::Camera::getOrigin() const
{
    return {int(_origin.getX()), int(_origin.getY()), int(_origin.getZ())};
}

void RayTracer::Camera::printCamera() const
{
    std::cout << "Camera:" << std::endl;
    std::cout << "Origin: " << _origin.getX() << " " << _origin.getY() << " " << _origin.getZ() << std::endl;
    std::cout << "Resolution: " << _resolutionX << " " << _resolutionY << std::endl;
    std::cout << "Screen:" << std::endl;
}

Math::Rectangle3D RayTracer::Camera::getScreen() const
{
    return _screen;
}

void RayTracer::Camera::moveForward(int distance)
{
    Math::Vector3D vector(_origin >> _screen.getOrigin());

    vector.normalize();
    this->moveBy(vector * distance);
}

void RayTracer::Camera::moveLeft(int distance)
{
    Math::Vector3D vector(_origin >> _screen.getOrigin());

    vector.normalize();
    vector.rotateZ(M_PI / 2);
    this->moveBy(vector * distance);
}

void RayTracer::Camera::moveUp(int distance)
{
    Math::Vector3D vector(this->getScreen().getBottom());

    vector.normalize();
    this->moveBy(vector * distance);
}
