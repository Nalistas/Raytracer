/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** SphericChessBoard
*/

#include "SphericChessBoard.hpp"

RayTracer::SphericChessBoard::SphericChessBoard(std::unique_ptr<IObject> object, int size) :
    IObjectDecorator(std::move(object)), _size(size)
{}

struct RayTracer::bounce RayTracer::SphericChessBoard::hits(const Ray &ray)
{
    struct bounce bnce = _object->hits(ray);

    double theta = acos(bnce.normal.getZ());
    double phi = atan2(bnce.normal.getY(), bnce.normal.getX());

    const int numCellsTheta = _size;
    const int numCellsPhi = _size;

    if (((int)(theta * numCellsTheta) + (int)(phi * numCellsPhi)) % 2 == 0) {
        bnce.color.reverseLight();
    }
    bnce.reflectivity = 0;
    bnce.transparency = 0;
    return bnce;
}

void RayTracer::SphericChessBoard::fromMap(std::map<std::string, float> params)
{
    _object->fromMap(params);
}


void RayTracer::SphericChessBoard::printObject() const
{
    _object->printObject();
}

std::map<std::string, std::string> RayTracer::SphericChessBoard::getInfos() const
{
    std::map<std::string, std::string> infos = _object->getInfos();
    return infos;
}
