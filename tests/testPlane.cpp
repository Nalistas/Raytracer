/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** testPlane
*/

#include <criterion/criterion.h>
#include "../Primitives/Plane/Plane.hpp"

Test(plane, get_position)
{
    RayTracer::Plane plane(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1));
    Math::Point3D position = plane.getP1();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 0);
    cr_assert_eq(position.getZ(), 0);
}

Test(plane, get_position_after_construction)
{
    RayTracer::Plane plane;
    Math::Point3D position = plane.getP1();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 5);
    cr_assert_eq(position.getZ(), 0);
}

Test(plane, get_position_after_custom_construction)
{
    RayTracer::Plane plane(Math::Point3D(1, 2, 3), Math::Vector3D(0, 0, 1));
    Math::Point3D position = plane.getP1();
    cr_assert_eq(position.getX(), 1);
    cr_assert_eq(position.getY(), 2);
    cr_assert_eq(position.getZ(), 3);
}

Test(plane, hits)
{
    RayTracer::Plane plane(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1));
    RayTracer::Ray ray(Math::Point3D(0, 0, -10), Math::Vector3D(0, 0, 1));
    RayTracer::bounce result = plane.hits(ray);
    cr_assert(result.t != NAN);
}

Test(plane, get_infos)
{
    RayTracer::Plane plane(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1));
    std::map<std::string, std::string> infos = plane.getInfos();
    cr_assert_str_eq(infos["type"].c_str(), "plane");
    cr_assert_str_eq(infos["x"].c_str(), "0");
    cr_assert_str_eq(infos["y"].c_str(), "0");
    cr_assert_str_eq(infos["z"].c_str(), "0");
    cr_assert_str_eq(infos["normal_x"].c_str(), "0");
    cr_assert_str_eq(infos["normal_y"].c_str(), "0");
    cr_assert_str_eq(infos["normal_z"].c_str(), "1");
}
