/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** BasicTexture
*/

#include "interface/IObjectDecorator.hpp"
#include "3D/Ray.hpp"
#include "interface/IObject.hpp"
#include <iostream>

#ifndef BasicTexture_HPP_
    #define BasicTexture_HPP_

namespace RayTracer {
    class BasicTexture : public IObjectDecorator {
        public:
            explicit BasicTexture(std::unique_ptr<IObject> object, std::array<int, 3> color);
            ~BasicTexture() = default;

            struct bounce hits(const Ray &) override;
            void printObject() const override;
            std::array<int, 3> getColor() const;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;

        private:
            Color _color;
    };
}

#endif /* !BasicTexture_HPP_ */
