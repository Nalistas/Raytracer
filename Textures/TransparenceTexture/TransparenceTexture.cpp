/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** TransparenceTexture
*/

#include "TransparenceTexture.hpp"

RayTracer::TransparenceTexture::TransparenceTexture(std::unique_ptr<IObject> object, double transparency, std::shared_ptr<Mediator> mediator)
    : IObjectDecorator(std::move(object)), _transparency(transparency), _mediator(mediator)
{}

struct RayTracer::bounce RayTracer::TransparenceTexture::hits(const Ray &r)
{
    struct bounce hit = _object->hits(r);
    if (std::isnan(hit.t) || hit.t <= 0 || _transparency == 0)
        return hit;

    Color newRayColor = hit.color * (1 - _transparency) + r.getColor() * _transparency;
    newRayColor.setf(
        std::min(newRayColor.rf(), r.getColor().rf()),
        std::min(newRayColor.gf(), r.getColor().gf()),
        std::min(newRayColor.bf(), r.getColor().bf())
    );
    Math::Vector3D newRayDirection = (r.getDirection() + hit.normal * 0.02).normalize();

    Ray reflectedRay(
        hit.hitPosition + newRayDirection * 0.001,
        newRayDirection,
        newRayColor
    );
    struct bounce reflectedHit = _mediator->hits(reflectedRay);

    if (std::isnan(reflectedHit.t) || reflectedHit.t <= 0) {
        reflectedHit.color = newRayColor;
        reflectedHit.t = hit.t;
    }
    reflectedHit.transparency = _transparency;
    return reflectedHit;
}

void RayTracer::TransparenceTexture::fromMap(std::map<std::string, float> params)
{
    _transparency = params["transparency"];
}

void RayTracer::TransparenceTexture::printObject() const
{
    _object->printObject();
}

std::map<std::string, std::string> RayTracer::TransparenceTexture::getInfos() const
{
    std::map<std::string, std::string> infos = _object->getInfos();
    infos["transparency"] = std::to_string(_transparency);
    return infos;
}
