/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** PointLight
*/

#include "PointLight/PointLight.hpp"

RayTracer::PointLight::PointLight(std::shared_ptr<Mediator> const &mediator, double x, double y, double z, double intensity) :
    _position(x, y, z), _intensity(intensity), _mediator(mediator)
{}

RayTracer::Color RayTracer::PointLight::lighting(const bounce& hit) const
{
    Math::Vector3D lightDirection = (_position >> hit.hitPosition).normalize();

    Ray shadowRay(hit.hitPosition + (-lightDirection * 0.001), -lightDirection, Color(255, 255, 255));
    bounce shadowHit = _mediator->hits(shadowRay);
    double lightIntensity = std::max(0.0, hit.normal.dotProduct(-lightDirection) * _intensity);
    if (!std::isnan(shadowHit.t) && shadowHit.t > 0 &&
        (shadowHit.hitPosition << _position).length() < (hit.hitPosition << _position).length()) {
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

double RayTracer::PointLight::getIntensity() const
{
    return _intensity;
}

void RayTracer::PointLight::printObject() const
{
    std::cout << "PointLight => coord (x y z): " << _position.getX() << " " << _position.getY() << " " << _position.getZ() << " intensity: " << _intensity << std::endl;
}

Math::Point3D RayTracer::PointLight::getPosition() const
{
    return _position;
}

double RayTracer::PointLight::computeLightIntensity(__attribute__((unused)) struct bounce const &b) const
{
    return _intensity;
}

std::map<std::string, std::string> RayTracer::PointLight::getInfos() const
{
    std::map<std::string, std::string> infos;

    infos["type"] = "pointLight";
    infos["x"] = std::to_string(_position.getX());
    infos["y"] = std::to_string(_position.getY());
    infos["z"] = std::to_string(_position.getZ());
    infos["intensity"] = std::to_string(_intensity);
    return infos;
}