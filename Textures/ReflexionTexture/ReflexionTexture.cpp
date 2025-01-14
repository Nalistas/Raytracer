/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ReflexionTexture
*/

#include "ReflexionTexture.hpp"

RayTracer::ReflexionTexture::ReflexionTexture(std::unique_ptr<IObject> object, double reflexion, std::shared_ptr<Mediator> mediator) :
    IObjectDecorator(std::move(object)), _reflexion(reflexion), _mediator(mediator)
{}

void RayTracer::ReflexionTexture::fromMap(std::map<std::string, float> params)
{
    _reflexion = params["reflexion"];
}

RayTracer::bounce RayTracer::ReflexionTexture::hits(const Ray &r)
{
    bounce hit = _object->hits(r);
    if (std::isnan(hit.t) || hit.t <= 0 || _reflexion == 0)
        return hit;

    Color newRayColor = hit.color * (1 - _reflexion) + r.getColor() * _reflexion;
    newRayColor.setf(
        std::min(newRayColor.rf(), r.getColor().rf()),
        std::min(newRayColor.gf(), r.getColor().gf()),
        std::min(newRayColor.bf(), r.getColor().bf())
    );
    Math::Vector3D newRayDirection = (r.getDirection().reflect(hit.normal));

    Ray reflectedRay(
        hit.hitPosition + newRayDirection * 0.001,
        newRayDirection,
        newRayColor
    );
    struct bounce reflectedHit = _mediator->hits(reflectedRay);

    if (std::isnan(reflectedHit.t) || reflectedHit.t <= 0) {
        reflectedHit.t = 0;
        reflectedHit.color = Color(0, 0, 0);
    }
    return reflectedHit;
}


void RayTracer::ReflexionTexture::printObject() const
{
    _object->printObject();
    std::cout << "Reflexion: " << _reflexion << std::endl;
}

std::map<std::string, std::string> RayTracer::ReflexionTexture::getInfos() const
{
    std::map<std::string, std::string> infos = _object->getInfos();

    infos["reflexion"] = std::to_string(_reflexion);
    return infos;
}
