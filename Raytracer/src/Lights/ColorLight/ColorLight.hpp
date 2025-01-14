/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ColorLight
*/

#include <iostream>
#include <memory>
#include "interface/ILightDecorator.hpp"
#include "3D/Vector3D.hpp"

#ifndef COLORLIGHT_HPP_
    #define COLORLIGHT_HPP_

namespace RayTracer {
    class ColorLight : public ILightDecorator {
        public:
            ColorLight(std::unique_ptr<ILight> &light, const Color &color);
            ~ColorLight() = default;

            RayTracer::Color lighting(struct bounce const &b) const override;

            void printObject() const override;
            std::map<std::string, std::string> getInfos() const override;
        
        private:
            Color _color;

    };
}

#endif /* !COLORLIGHT_HPP_ */