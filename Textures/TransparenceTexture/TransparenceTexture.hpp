/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** TransparenceTexture
*/

#include "interface/IObjectDecorator.hpp"
#include "Mediator/Mediator.hpp"
#include "3D/Vector3D.hpp"
#include <iostream>

#ifndef TRANSPARENCETEXTURE_HPP_
    #define TRANSPARENCETEXTURE_HPP_

namespace RayTracer {
    class TransparenceTexture : public IObjectDecorator {
        public:
            TransparenceTexture(std::unique_ptr<IObject> object, double transparency, std::shared_ptr<Mediator> mediator);

            struct bounce hits(const Ray &ray) override;
            void printObject() const override;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;

        private:
            double _transparency;
            std::shared_ptr<Mediator> _mediator;
            Ray _ray;
    };
}

#endif /* !TRANSPARENCETEXTURE_HPP_ */
