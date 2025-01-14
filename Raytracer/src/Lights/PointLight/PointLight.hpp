/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** PointLight
*/

#include "interface/ILight.hpp"
#include "Mediator/Mediator.hpp"
#include <iostream>

#ifndef POINTLIGHT_HPP_
    #define POINTLIGHT_HPP_

namespace RayTracer {
    class PointLight : public ILight {
        public:
            PointLight(std::shared_ptr<Mediator> const &mediator, double x, double y, double z, double intensity = 1);
            ~PointLight() = default;

            RayTracer::Color lighting(struct bounce const &b) const override;
            double computeLightIntensity(struct bounce const &b) const;

            double getIntensity() const;
            void printObject() const override;
            Math::Point3D getPosition() const;
            std::map<std::string, std::string> getInfos() const override;

        private:
            Math::Point3D _position;
            double _intensity;
            std::shared_ptr<Mediator> const _mediator;
    };
}

#endif /* !POINTLIGHT_HPP_ */
