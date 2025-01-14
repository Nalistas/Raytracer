/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include "Mediator/Mediator.hpp"
#include "ChestBoard/SphericChessBoard.hpp"
#include "Rotation/RotationDecorator.hpp"
#include "TransparenceTexture/TransparenceTexture.hpp"
#include "PointLight/PointLight.hpp"
#include "AmbientLight/AmbientLight.hpp"
#include "DirectionnalLight/DirectionnalLight.hpp"
#include "BasicTexture/BasicTexture.hpp"
#include "3D/Point3D.hpp"
#include "3D/Vector3D.hpp"
#include "3D/Camera.hpp"
#include "Core/DLLoader.hpp"
#include <libconfig.h++>
#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace RayTracer {
    class Parser {
        public:
            Parser(std::string file, std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> &loaders);
            ~Parser();
            void readFile(std::string file);
            void readCamera(void);

            // Lights
            void readPointLights(void);
            void readAmbientLights(void);
            void readDirectionalLights(void);

            // Primitives
            void readPrimitives(void);
            void readOnePrimitiveType(std::string primitive_name, const libconfig::Setting &objects);
            bool readNormal(const libconfig::Setting &primitive, int i, std::map<std::string, float> &params);
            bool readAttributes(const libconfig::Setting &primitive, int i, std::map<std::string, float> &params);

            // Transformations
            void readRotation(const libconfig::Setting &primitive, std::unique_ptr<IObject> &obj);
            void readTransparency(const libconfig::Setting &primitive, std::unique_ptr<IObject> &obj);

            // Materials
            void readChestBoard(const libconfig::Setting &primitive, std::unique_ptr<RayTracer::IObject> &obj);

            std::shared_ptr<RayTracer::Mediator> getMediator() const;
            std::unique_ptr<RayTracer::Camera> &getCamera();
            void readConfigFile(std::string file);
            void readScenes(void);

        protected:
        private:
            libconfig::Config _cfg;
            std::shared_ptr<RayTracer::Mediator> _mediator;
            std::unique_ptr<RayTracer::Camera> _cam;
            std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> &_loaders;
    };
}

#endif /* !PARSER_HPP_ */
