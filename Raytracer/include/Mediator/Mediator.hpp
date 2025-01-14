/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Mediator
*/

#include "interface/IObject.hpp"
#include "interface/ILight.hpp"
#include <memory>
#include <list>
#include <iostream>

#ifndef MEDIATOR_HPP_
    #define MEDIATOR_HPP_

namespace RayTracer {
    class Mediator {
        public:
            Mediator();
            ~Mediator() = default;

            void addObject(std::unique_ptr<IObject> object);
            void addLight(std::unique_ptr<ILight> light);
            struct bounce hits(const Ray &ray);
            Color lights(struct bounce &b);
            std::list<std::unique_ptr<IObject>> &getObjects();
            std::list<std::unique_ptr<ILight>> &getLights();

        private:
            std::size_t nb_hits;
            std::list<std::unique_ptr<IObject>> _objects;
            std::list<std::unique_ptr<ILight>> _lights;
    };
}

#endif /* !MEDIATOR_HPP_ */
