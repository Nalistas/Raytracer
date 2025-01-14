/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Mediator
*/

#include "Mediator/Mediator.hpp"

RayTracer::Mediator::Mediator() : nb_hits(0)
{}

void RayTracer::Mediator::addObject(std::unique_ptr<IObject> object)
{
    _objects.push_back(std::move(object));
}

void RayTracer::Mediator::addLight(std::unique_ptr<ILight> light)
{
    _lights.push_back(std::move(light));
}

RayTracer::Color RayTracer::Mediator::lights(struct bounce &b)
{
    Color c({0, 0, 0});

    if (std::isnan(b.t)) {
        return c;
    }
    for (auto &light : _lights) {
        Color tmp = light->lighting(b);
        c += (tmp);
    }
    return c;
}

RayTracer::bounce RayTracer::Mediator::hits(const Ray &ray)
{
    bounce closest = {NAN, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0};

    for (auto &object : _objects) {
        bounce candidate = object->hits(ray);
        if (std::isnan(candidate.t)) {
            continue;
        }
        if ((candidate.t > 0 && candidate.t < closest.t) || std::isnan(closest.t)) {
            closest = candidate;
        }
    }
    return closest;
}

std::list<std::unique_ptr<RayTracer::IObject>> &RayTracer::Mediator::getObjects()
{
    return _objects;
}

std::list<std::unique_ptr<RayTracer::ILight>> &RayTracer::Mediator::getLights()
{
    return _lights;
}
