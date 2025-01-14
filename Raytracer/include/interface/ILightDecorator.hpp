/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ILightDecorator
*/

#include "ILight.hpp"

#ifndef ILIGHTDECORATOR_HPP_
    #define ILIGHTDECORATOR_HPP_

namespace RayTracer {
    class ILightDecorator : public ILight {
        public:
            explicit ILightDecorator(std::unique_ptr<ILight> &light) : _light(std::move(light)) {};
            ~ILightDecorator() = default;

        protected:
            std::unique_ptr<ILight> _light;
    };
}

#endif /* !ILIGHTDECORATOR_HPP_ */