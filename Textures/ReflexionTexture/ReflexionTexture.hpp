/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ReflexionTexture
*/

#include "interface/IObjectDecorator.hpp"
#include "Mediator/Mediator.hpp"
#include <iostream>

#ifndef REFLEXIONTEXTURE_HPP_
    #define REFLEXIONTEXTURE_HPP_

namespace RayTracer {
    class ReflexionTexture : public IObjectDecorator {
        public:
            ReflexionTexture(std::unique_ptr<IObject> object, double reflexion, std::shared_ptr<Mediator> mediator);
            ~ReflexionTexture() = default;

            void printObject() const override;
            struct bounce hits(const Ray &ray) override;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;
        private:
            double _reflexion;
            std::shared_ptr<Mediator> _mediator;
    };
}

#endif /* !REFLEXIONTEXTURE_HPP_ */
