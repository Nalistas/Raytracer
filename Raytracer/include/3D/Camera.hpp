/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#include "Point3D.hpp"
#include "Rectangle3D.hpp"
#include "Ray.hpp"
#include <iostream>


#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

namespace RayTracer
{
    class Camera {
        public:
            Camera();
            ~Camera() = default;

            Ray ray(double x, double y) const;

            void setScreen(Math::Rectangle3D screen);
            void setOrigin(Math::Point3D origin);


            double getResolutionX() const;
            double getResolutionY() const;
            void setResolution(std::size_t x, std::size_t y);
            void moveTo(Math::Point3D point);
            void moveBy(Math::Vector3D vector);

            double getHeightInc(double start, double end) const;
            double getWidthInc(double start, double end) const;
            std::array<int, 3> getOrigin() const;
            Math::Rectangle3D getScreen() const;

            // void setAngleOfView(double angle);
            void rotateX(double angle);
            void rotateY(double angle);
            void rotateZ(double angle);

            void printCamera() const;

            //move
            void moveUp(int distance);
            void moveLeft(int distance);
            void moveForward(int distance);


        private:
            Math::Rectangle3D _screen;
            Math::Point3D _origin;
            std::size_t _resolutionX;
            std::size_t _resolutionY;
    };
} // namespace RayTracer

#endif /* !CAMERA_HPP_ */
