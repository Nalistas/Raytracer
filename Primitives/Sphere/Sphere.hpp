/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#include "Point3D.hpp"
#include "Ray.hpp"
#include "IObject.hpp"
#include "IObject.hpp"
#include <cmath>
#include <iostream>
#include <map>
#include <memory>


#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

namespace RayTracer {
    class Sphere : public IObject {
        public:
            Sphere();
            Sphere(const Sphere &other);
            Sphere(Math::Point3D const &center = Math::Point3D(0, 0, 0), double radius = 1);
            ~Sphere() = default;

            struct bounce hits(const Ray &ray) override;
            void fromMap(std::map<std::string, float> params) override;
            void printObject() const override;
            double getRadius() const;
            Math::Point3D getCenter() const;
            std::map<std::string, std::string> getInfos() const override;
            Math::Point3D getPosition() const;
            Math::Vector3D getRotation() const;


        protected:
        private:
            double _radius;
            Math::Point3D _position;
            Math::Vector3D _rotation;

    };
}

#endif /* !SPHERE_HPP_ */
