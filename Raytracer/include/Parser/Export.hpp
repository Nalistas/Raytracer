/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Export
*/

#ifndef EXPORT_HPP_
#define EXPORT_HPP_

#include "Mediator/Mediator.hpp"
#include "3D/Point3D.hpp"
#include "3D/Vector3D.hpp"
#include "3D/Camera.hpp"
#include "interface/ILight.hpp"
#include "interface/IObject.hpp"
#include "Core/DLLoader.hpp"
#include <libconfig.h++>
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <fstream>
#include <sstream>
#include <functional>

using namespace libconfig;

namespace RayTracer {
    class Export {
        public:
            Export();
            ~Export();
            void writeIntoFile(std::unique_ptr<RayTracer::Camera> &camera, std::shared_ptr<RayTracer::Mediator> mediator, std::string filename);
            void writeCamera(Config &cfg, std::unique_ptr<RayTracer::Camera> &camera);
            void writeSphere(Setting& parent, std::map<std::string, std::string> infos);
            void writeCylinder(Setting& parent, std::map<std::string, std::string> infos);
            void writeCone(Setting& parent, std::map<std::string, std::string> infos);
            void writePlane(Setting& parent, std::map<std::string, std::string> infos);
            void writePointLight(Setting& parent, std::map<std::string, std::string> infos);
            void writeAmbientLight(Setting& parent, std::map<std::string, std::string> infos);
            void writeDirectionnalLight(Setting& parent, std::map<std::string, std::string> infos);

        protected:
        private:
            std::map<std::string, std::function<void(Setting&, std::map<std::string, std::string>)>> _writeFunctions;
    };
}

#endif /* !EXPORT_HPP_ */
