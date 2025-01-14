/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** SphericChessBoard
*/

#include "interface/IObjectDecorator.hpp"
#include "3D/Ray.hpp"
#include "interface/IObject.hpp"
#include <iostream>

#ifndef SphericChessBoard_HPP_
    #define SphericChessBoard_HPP_

namespace RayTracer {
    class SphericChessBoard : public IObjectDecorator {
        public:
            SphericChessBoard(std::unique_ptr<IObject> object, int size);
            ~SphericChessBoard() = default;

            struct bounce hits(const Ray &) override;
            void printObject() const override;
            std::map<std::string, std::string> getInfos() const override;
            void fromMap(std::map<std::string, float> params) override;

        private:
            int _size;
    };
}

#endif /* !SphericChessBoard_hpp */
