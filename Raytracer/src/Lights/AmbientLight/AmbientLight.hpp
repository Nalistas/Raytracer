/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** AmbientLight
*/

#include "interface/ILight.hpp"
#include "3D/Point3D.hpp"
#include <iostream>

#ifndef AmbientLight_HPP_
    #define AmbientLight_HPP_

namespace RayTracer {
    class AmbientLight : public ILight {
        public:
            AmbientLight();
            AmbientLight(double intensity = 0.2);

            RayTracer::Color lighting(struct bounce const &b) const override;
            double computeLightIntensity(struct bounce const &b) const;
            double getIntensity() const;

            void printObject() const override;
            std::map<std::string, std::string> getInfos() const override;

        private:
            double _intensity;
    };
}

#endif /* !AmbientLight_HPP_ */
