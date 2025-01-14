/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

RayTracer::AmbientLight::AmbientLight(double intensity)
{
    _intensity = intensity;
}

RayTracer::Color RayTracer::AmbientLight::lighting(struct bounce const &b) const
{
    return b.color * _intensity;
}

void RayTracer::AmbientLight::printObject() const
{
    std::cout << "AmbientLight => intensity: " << _intensity << std::endl;
}

double RayTracer::AmbientLight::getIntensity() const
{
    return _intensity;
}

double RayTracer::AmbientLight::computeLightIntensity(__attribute__((unused)) struct bounce const &b) const
{
    return _intensity;
}

std::map<std::string, std::string> RayTracer::AmbientLight::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "ambientLight";
    infos["intensity"] = std::to_string(_intensity);
    return infos;
}
