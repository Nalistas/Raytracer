/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-hugo.tesson
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

#include "interface/IObject.hpp"
#include "interface/IObject.hpp"
#include "3D/Vector3D.hpp"
#include "3D/Point3D.hpp"
#include "3D/Ray.hpp"
#include <cmath>
#include <iostream>
#include <memory>

namespace RayTracer {
    class Cone: public IObject {
        public:
            Cone();
            Cone(const Cone &other);
            Cone(Math::Point3D const &center, Math::Vector3D const &normal, double radius);
            ~Cone() = default;

            struct bounce hits(const Ray &ray);
            void printObject() const override;
            Math::Point3D getCenter() const;
            Math::Vector3D getNormal() const;
            double getRadius() const;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;
            Math::Point3D getPosition() const;
            Math::Vector3D getRotation() const;


        protected:
        private:
            double _radius;
            Math::Point3D _position;
            Math::Vector3D _rotation;

    };
}

#endif /* !CONE_HPP_ */
