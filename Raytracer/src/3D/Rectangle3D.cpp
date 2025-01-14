/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Rectangle3D
*/

#include "3D/Rectangle3D.hpp"
#include <iostream>

Math::Point3D Math::Rectangle3D::pointAt(double u, double v) const
{
    return _origin + _bottom * u + _left * v;
}

Math::Point3D Math::Rectangle3D::getOrigin()
{
    return _origin;
}

Math::Vector3D Math::Rectangle3D::getBottom()
{
    return _bottom;
}

Math::Vector3D Math::Rectangle3D::getLeft()
{
    return _left;
}

void Math::Rectangle3D::setOrigin(const Math::Point3D& origin)
{
    _origin = origin;
}

void Math::Rectangle3D::setBottom(const Math::Vector3D& bottom)
{
    _bottom = bottom;
}

void Math::Rectangle3D::setLeft(const Math::Vector3D& left)
{
    _left = left;
}
