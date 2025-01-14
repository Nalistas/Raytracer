/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane
*/

#include "IObject.hpp"
#include "Ray.hpp"
#include "Point3D.hpp"
#include <iostream>
#include <memory>

#ifndef PLANE_HPP_
    #define PLANE_HPP_

namespace RayTracer {
    class Plane : public IObject {
        public:
            Plane();
            Plane(Math::Point3D const &p1, Math::Vector3D const &normal);

            struct bounce hits(const Ray &ray) override;
            void printObject() const override;
            Math::Point3D getP1() const;
            Math::Vector3D getNormal() const;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;

        private:
            Math::Point3D _position;
            Math::Vector3D _rotation;

    };
}

#endif /* !PLANE_HPP_ */
