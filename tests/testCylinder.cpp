/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** testCylinder
*/

#include <criterion/criterion.h>
#include "../Primitives/Cylinder/Cylinder.hpp"

Test(cylinder, get_radius)
{
    RayTracer::Cylinder cylinder(Math::Point3D(0, 0, 0), 1);
    cr_assert_eq(cylinder.getRadius(), 1);
}

Test(cylinder, get_position)
{
    RayTracer::Cylinder cylinder(Math::Point3D(0, 0, 0), 1);
    Math::Point3D position = cylinder.getPosition();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 0);
    cr_assert_eq(position.getZ(), 0);
}

Test(cylinder, get_position_after_construction)
{
    RayTracer::Cylinder cylinder;
    Math::Point3D position = cylinder.getPosition();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 5);
    cr_assert_eq(position.getZ(), 0);
}

Test(cylinder, get_position_after_custom_construction)
{
    RayTracer::Cylinder cylinder(Math::Point3D(1, 2, 3), 1);
    Math::Point3D position = cylinder.getPosition();
    cr_assert_eq(position.getX(), 1);
    cr_assert_eq(position.getY(), 2);
    cr_assert_eq(position.getZ(), 3);
}

Test(cylinder, hits)
{
    RayTracer::Cylinder cylinder(Math::Point3D(0, 0, 0), 1);
    RayTracer::Ray ray(Math::Point3D(0, 0, -10), Math::Vector3D(0, 0, 1));
    RayTracer::bounce result = cylinder.hits(ray);
    cr_assert(result.t != NAN);
}

Test(cylinder, get_infos)
{
    RayTracer::Cylinder cylinder(Math::Point3D(0, 0, 0), 1);
    std::map<std::string, std::string> infos = cylinder.getInfos();
    cr_assert_str_eq(infos["type"].c_str(), "cylinder");
    cr_assert_str_eq(infos["x"].c_str(), "0");
    cr_assert_str_eq(infos["y"].c_str(), "0");
    cr_assert_str_eq(infos["z"].c_str(), "0");
    cr_assert_str_eq(infos["radius"].c_str(), "1");
}
