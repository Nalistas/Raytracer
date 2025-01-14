/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** testCone
*/

#include <criterion/criterion.h>
#include "../Primitives/Cone/Cone.hpp"

Test(cone, get_radius)
{
    RayTracer::Cone cone(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1), 1);
    cr_assert_eq(cone.getRadius(), 1);
}

Test(cone, get_position)
{
    RayTracer::Cone cone(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1), 1);
    Math::Point3D position = cone.getPosition();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 0);
    cr_assert_eq(position.getZ(), 0);
}

Test(cone, get_position_after_construction)
{
    RayTracer::Cone cone;
    Math::Point3D position = cone.getPosition();
    cr_assert_eq(position.getX(), 0);
    cr_assert_eq(position.getY(), 5);
    cr_assert_eq(position.getZ(), 0);
}

Test(cone, get_position_after_custom_construction)
{
    RayTracer::Cone cone(Math::Point3D(1, 2, 3), Math::Vector3D(0, 0, 1), 1);
    Math::Point3D position = cone.getPosition();
    cr_assert_eq(position.getX(), 1);
    cr_assert_eq(position.getY(), 2);
    cr_assert_eq(position.getZ(), 3);
}

Test(cone, hits)
{
    RayTracer::Cone cone(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1), 1);
    RayTracer::Ray ray(Math::Point3D(0, 0, -10), Math::Vector3D(0, 0, 1));
    RayTracer::bounce result = cone.hits(ray);
    cr_assert(result.t != NAN);
}

Test(cone, get_infos)
{
    RayTracer::Cone cone(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1), 1);
    std::map<std::string, std::string> infos = cone.getInfos();
    cr_assert_str_eq(infos["type"].c_str(), "cone");
    cr_assert_str_eq(infos["x"].c_str(), "0");
    cr_assert_str_eq(infos["y"].c_str(), "0");
    cr_assert_str_eq(infos["z"].c_str(), "0");
    cr_assert_str_eq(infos["normal_x"].c_str(), "0");
    cr_assert_str_eq(infos["normal_y"].c_str(), "0");
    cr_assert_str_eq(infos["normal_z"].c_str(), "1");
    cr_assert_str_eq(infos["radius"].c_str(), "1");
}
