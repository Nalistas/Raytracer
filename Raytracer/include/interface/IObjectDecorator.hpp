/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IObjectDecorator
*/

#include <memory>
#include "IObject.hpp"

#ifndef IOBJECTDECORATOR_HPP_
    #define IOBJECTDECORATOR_HPP_

namespace RayTracer {
    class IObjectDecorator : public IObject {
        public:
            explicit IObjectDecorator(std::unique_ptr<IObject> object) : _object(std::move(object)) {};
            ~IObjectDecorator() = default;

        protected:
            std::unique_ptr<IObject> _object;
    };
}

#endif /* !IOBJECTDECORATOR_HPP_ */
