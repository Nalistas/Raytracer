/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cli
*/

#ifndef CLI_HPP_
#define CLI_HPP_

#include "Mediator/Mediator.hpp"
#include "PointLight/PointLight.hpp"
#include "AmbientLight/AmbientLight.hpp"
#include "DirectionnalLight/DirectionnalLight.hpp"
#include "BasicTexture/BasicTexture.hpp"
#include "3D/Point3D.hpp"
#include "Export.hpp"
#include "3D/Vector3D.hpp"
#include "3D/Camera.hpp"
#include "Core/DLLoader.hpp"
#include "interface/IObject.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <map>
#include <functional>

namespace RayTracer {
    class Cli {
        public:
            Cli(std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> &loaders);
            ~Cli();
            void run();
            void parseSphere();
            void parseCylinder();
            void parseCone();
            void parsePlane();
            void parsePointLight();
            void parseAmbientLight();
            void parseDirectionalLight();
            void parseCamera();
            std::array<int, 3> getXYZ(std::string type);
            std::array<int, 3> getColor(std::string type);
            int getRadius(std::string type);
            void display_help(void);
            void exitCli();
            void exportConfigFile();
            void listPrimitives();
            std::shared_ptr<RayTracer::Mediator> getMediator();
            int promptForInt(std::string prompt);
            int promptForColor(std::string prompt);
            std::unique_ptr<RayTracer::Camera> &getCamera();


        protected:
        private:
            std::shared_ptr<RayTracer::Mediator> _mediator;
            std::unique_ptr<RayTracer::Camera> _cam;
            std::map<std::string, std::function<void()>> _commands;
            std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> &_loaders;
    };
}

#endif /* !CLI_HPP_ */
