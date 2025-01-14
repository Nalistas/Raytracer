/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** DirectionnalLight
*/

#include "interface/ILight.hpp"
#include "3D/Point3D.hpp"
#include <iostream>
#include "Mediator/Mediator.hpp"

#ifndef DIRECTIONNALLIGHT_HPP_
#define DIRECTIONNALLIGHT_HPP_

namespace RayTracer {
    class DirectionnalLight : public ILight {
        public:
            DirectionnalLight(std::shared_ptr<Mediator> const &mediator, double x, double y, double z, double intensity = 1);
            DirectionnalLight(Math::Vector3D const &direction);
            RayTracer::Color lighting(struct bounce const &b) const override;
            double computeLightIntensity(struct bounce const &b) const override;

            double getIntensity() const;
            void printObject() const override;
            Math::Vector3D getDirection() const;
            std::map<std::string, std::string> getInfos() const override;

        private:
            Math::Vector3D _direction;
            double _intensity;
            std::shared_ptr<Mediator> const _mediator;
    };
}

#endif /* !DirectionnalLight_HPP_ */
