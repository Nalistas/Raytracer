/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** BasicTexture
*/

#include "BasicTexture.hpp"

RayTracer::BasicTexture::BasicTexture(std::unique_ptr<IObject> object, std::array<int, 3> color) :
    IObjectDecorator(std::move(object)), _color(color)
{}

struct RayTracer::bounce RayTracer::BasicTexture::hits(const Ray &ray)
{
    struct bounce bnce = _object->hits(ray);

    int r = std::min(_color.ri(), ray.getColor().ri());
    int g = std::min(_color.gi(), ray.getColor().gi());
    int b = std::min(_color.bi(), ray.getColor().bi());

    bnce.color.seti(r, g, b);
    return bnce;
}

void RayTracer::BasicTexture::fromMap(std::map<std::string, float> params)
{
    _color.seti(params["color_r"], params["color_g"], params["color_b"]);
    _object->fromMap(params);
}


void RayTracer::BasicTexture::printObject() const
{
    _object->printObject();
    std::cout << "Color: " << _color.ri() << " " << _color.gi() << " " << _color.bi() << std::endl;
}

std::array<int, 3> RayTracer::BasicTexture::getColor() const
{
    return std::array<int, 3> { _color.ri(), _color.gi(), _color.bi() };
}

std::map<std::string, std::string> RayTracer::BasicTexture::getInfos() const
{
    std::map<std::string, std::string> infos = _object->getInfos();

    infos["color_r"] = std::to_string(_color.ri());
    infos["color_g"] = std::to_string(_color.gi());
    infos["color_b"] = std::to_string(_color.bi());
    return infos;
}
