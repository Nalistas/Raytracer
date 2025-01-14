/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** DirectionnalLight
*/

#include "DirectionnalLight.hpp"

RayTracer::DirectionnalLight::DirectionnalLight(std::shared_ptr<Mediator> const &mediator, double x, double y, double z, double intensity) :
    _direction(x, y, z), _intensity(intensity), _mediator(mediator)
{
    _direction.normalize();
    _intensity = intensity;
}

RayTracer::DirectionnalLight::DirectionnalLight(Math::Vector3D const &direction) :
    _direction(direction)
{
    _direction.normalize();
}

RayTracer::Color RayTracer::DirectionnalLight::lighting(const bounce& hit) const
{
    Ray shadowRay(hit.hitPosition + (-_direction * 0.001), -_direction, Color(255, 255, 255));
    bounce shadowHit = _mediator->hits(shadowRay);
    double lightIntensity = std::max(0.0, hit.normal.dotProduct(-_direction) * _intensity);
    if (!std::isnan(shadowHit.t) && shadowHit.t > 0) {
        if (shadowHit.transparency > 0) {
            return Color(
                std::min(hit.color.rf(), shadowHit.color.rf()),
                std::min(hit.color.gf(), shadowHit.color.gf()),
                std::min(hit.color.bf(), shadowHit.color.bf())
            ) * lightIntensity;
        } else {
            return Color(0, 0, 0);
        }
    }
    return hit.color * lightIntensity;
}

void RayTracer::DirectionnalLight::printObject() const
{
    std::cout << "DirectionnalLight => direction (x y z): " << _direction.getX() << " " << _direction.getY() << " " << _direction.getZ() << " intensity: " << _intensity << std::endl;
}

Math::Vector3D RayTracer::DirectionnalLight::getDirection() const
{
    return _direction;
}

double RayTracer::DirectionnalLight::computeLightIntensity(__attribute__((unused)) struct bounce const &b) const
{
    return _intensity;
}

double RayTracer::DirectionnalLight::getIntensity() const
{
    return _intensity;
}

std::map<std::string, std::string> RayTracer::DirectionnalLight::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "directionnalLight";
    infos["x"] = std::to_string(_direction.getX());
    infos["y"] = std::to_string(_direction.getY());
    infos["z"] = std::to_string(_direction.getZ());
    infos["intensity"] = std::to_string(_intensity);
    return infos;
}
