/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** Triangle
*/

#include "Point3D.hpp"
#include "Ray.hpp"
#include "IObject.hpp"
#include "IObject.hpp"
#include <iostream>
#include <memory>

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

namespace RayTracer {
    class Triangle : public IObject {
    public:
        Triangle();
        Triangle(const Triangle &other);
        Triangle(Math::Point3D const &p1, Math::Point3D const &p2, Math::Point3D const &p3);
        ~Triangle() = default;

        struct bounce hits(const Ray &ray) override;
        void printObject() const override;
        std::map<std::string, std::string> getInfos() const override;
        void fromMap(std::map<std::string, float> params) override;


    protected:
    private:
        Math::Point3D _p1, _p2, _p3;
        Math::Point3D _position;
        Math::Vector3D _rotation;

    };
}

#endif /* !TRIANGLE_HPP_ */
