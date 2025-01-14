/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** testSphere
*/

#include <criterion/criterion.h>
#include "../Primitives/Sphere/Sphere.hpp"

Test(sphere, get_radius)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 1);
    cr_assert_eq(sphere.getRadius(), 1);
}

Test(sphere, get_position)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 1);
    Math::Point3D position = sphere.getPosition();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 0);
    cr_assert_eq(position.getZ(), 0);
}

Test(sphere, get_rotation)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 1);
    Math::Vector3D rotation = sphere.getRotation();
    cr_assert_eq(rotation.getX(), 0);
    cr_assert_eq(rotation.getY(), 0);
    cr_assert_eq(rotation.getZ(), 0);
}

Test(sphere, get_infos)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 1);
    std::map<std::string, std::string> infos = sphere.getInfos();
    cr_assert_str_eq(infos["type"].c_str(), "sphere");
    cr_assert_str_eq(infos["x"].c_str(), "0");
    cr_assert_str_eq(infos["y"].c_str(), "0");
    cr_assert_str_eq(infos["z"].c_str(), "0");
    cr_assert_str_eq(infos["radius"].c_str(), "1");
}

Test(sphere, get_radius)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 2);
    cr_assert_eq(sphere.getRadius(), 2);
}

Test(sphere, get_position)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 2);
    Math::Point3D position = sphere.getPosition();
    cr_assert_eq(position.getX(), 1);
    cr_assert_eq(position.getY(), 2);
    cr_assert_eq(position.getZ(), 3);
}

Test(sphere, get_rotation)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 2);
    Math::Vector3D rotation = sphere.getRotation();
    cr_assert_eq(rotation.getX(), 1);
    cr_assert_eq(rotation.getY(), 2);
    cr_assert_eq(rotation.getZ(), 3);
}

Test(sphere, get_infos)
{
    RayTracer::Sphere sphere(Math::Point3D(0, 0, 0), 2);
    std::map<std::string, std::string> infos = sphere.getInfos();
    cr_assert_str_eq(infos["type"].c_str(), "sphere");
    cr_assert_str_eq(infos["x"].c_str(), "1");
    cr_assert_str_eq(infos["y"].c_str(), "2");
    cr_assert_str_eq(infos["z"].c_str(), "3");
    cr_assert_str_eq(infos["radius"].c_str(), "2");
}
