/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ILight
*/

#include "IObject.hpp"

#ifndef ILIGHT_HPP_
    #define ILIGHT_HPP_

namespace RayTracer {
    class ILight {
        public:
            ~ILight() = default;

            virtual double computeLightIntensity(struct bounce const &b) const = 0;
            virtual RayTracer::Color lighting(struct bounce const &b) const = 0;
            virtual void printObject() const = 0;
            virtual std::map<std::string, std::string> getInfos() const = 0;
    };
}

#endif /* !ILIGHT_HPP_ */
