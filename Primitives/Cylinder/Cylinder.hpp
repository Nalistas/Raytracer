/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_

#include "3D/Point3D.hpp"
#include "3D/Ray.hpp"
#include "3D/Vector3D.hpp"
#include "interface/IObject.hpp"
#include <cmath>
#include <iostream>
#include <memory>

namespace RayTracer {
    class Cylinder : public IObject {
        public:
            Cylinder();
            Cylinder(const Cylinder &other);
            Cylinder(Math::Point3D const &center, double radius);
            ~Cylinder() = default;

            struct bounce hits(const Ray &ray) override;
            void printObject() const override;
            Math::Point3D getCenter() const;
            Math::Vector3D getNormal() const;
            double getRadius() const;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;
            Math::Point3D getPosition() const;
            Math::Vector3D getRotation() const;


        private:
            double _radius;
            Math::Point3D _position;
    };
}

#endif /* !CYLINDER_HPP_ */
