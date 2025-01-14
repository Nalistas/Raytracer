/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IObject
*/

#include "3D/Ray.hpp"
#include "3D/Color.hpp"

#include <array>
#include <fstream>
#include <cmath>
#include <array>
#include <map>

#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_

namespace RayTracer {

    struct bounce {
        float t;
        Math::Point3D hitPosition;
        Math::Vector3D normal;
        Color color;
        float reflectivity;
        float transparency;
    };

    class IObject {
        public:
            ~IObject() = default;
            virtual struct bounce hits(const Ray &) = 0;
            virtual void printObject() const = 0;
            virtual std::map<std::string, std::string> getInfos() const = 0;
            virtual void fromMap(std::map<std::string, float> params) = 0;
    };
}

std::ofstream &operator<<(std::ofstream &outputFile, RayTracer::bounce const &bounce);

#endif /* !IOBJECT_HPP_ */
