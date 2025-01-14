/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ColorLight
*/

#include "ColorLight.hpp"
#include "3D/Vector3D.hpp"

RayTracer::ColorLight::ColorLight(std::unique_ptr<ILight> &light, const Color &color)
    : ILightDecorator(light), _color(color)
{
}

RayTracer::Color RayTracer::ColorLight::lighting(struct bounce const &b) const
{
    struct bounce b2 = b;
    b2.color.setf(
        std::min(b.color.rf(), _color.rf()),
        std::min(b.color.gf(), _color.gf()),
        std::min(b.color.bf(), _color.bf())
    );
    return _light->lighting(b2);
}

void RayTracer::ColorLight::printObject() const
{
    std::cout << "ColorLight => color: " << _color.ri() << " " << _color.gi() << " " << _color.bi() << std::endl;
}

std::map<std::string, std::string> RayTracer::ColorLight::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["color_r"] = std::to_string(_color.ri());
    infos["color_g"] = std::to_string(_color.gi());
    infos["color_b"] = std::to_string(_color.bi());
    return infos;
}
