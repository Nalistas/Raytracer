/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ColorLight
*/

#include "interface/IObjectDecorator.hpp"

#ifndef ROTATIONDECORATOR_HPP_
    #define ROTATIONDECORATOR_HPP_

namespace RayTracer {
    class RotationDecorator : public IObjectDecorator {
        public:
            explicit RotationDecorator(std::unique_ptr<IObject> obj,
                Math::Point3D rotationCenter, double angle1, double angle2);

            ~RotationDecorator() = default;

            struct bounce hits(const Ray &ray) override;

            Math::Point3D getRotationCenter() const;
            double getRotationAngle1() const;
            double getRotationAngle2() const;

            void printObject() const override;
            std::map<std::string, std::string> getInfos() const override;

            void fromMap(std::map<std::string, float> params) override;

        private:
            Math::Point3D _rotationCenter;
            double _angle1;
            double _angle2;
    };
}

#endif /* !ILIGHT_HPP_ */