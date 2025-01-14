/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Export
*/

#include "Parser/Export.hpp"

using namespace std;
using namespace libconfig;

RayTracer::Export::Export()
{
    _writeFunctions["sphere"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writeSphere(parent, infos);
    };
    _writeFunctions["cylinder"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writeCylinder(parent, infos);
    };;
    _writeFunctions["cone"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writeCone(parent, infos);
    };
    _writeFunctions["plane"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writePlane(parent, infos);
    };
    _writeFunctions["pointLight"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writePointLight(parent, infos);
    };
    _writeFunctions["ambientLight"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writeAmbientLight(parent, infos);
    };
    _writeFunctions["directionnalLight"] = [this](libconfig::Setting& parent, std::map<std::string, std::string> infos) {
        this->writeDirectionnalLight(parent, infos);
    };
}

RayTracer::Export::~Export()
{
}

void RayTracer::Export::writeCamera(Config &cfg, std::unique_ptr<RayTracer::Camera> &camera)
{
    Setting &cameraSetting = cfg.getRoot().add("camera", Setting::TypeGroup);

    Setting &resolution = cameraSetting.add("resolution", Setting::TypeGroup);
    resolution.add("width", Setting::TypeInt) = int(camera->getResolutionX());
    resolution.add("height", Setting::TypeInt) = int(camera->getResolutionY());

    Setting &position = cameraSetting.add("position", Setting::TypeGroup);
    position.add("x", Setting::TypeInt) = camera->getOrigin().at(0);
    position.add("y", Setting::TypeInt) = camera->getOrigin().at(1);
    position.add("z", Setting::TypeInt) = camera->getOrigin().at(2);

    Setting &rotation = cameraSetting.add("rotation", Setting::TypeGroup);
    rotation.add("x", Setting::TypeInt) = 0;
    rotation.add("y", Setting::TypeInt) = 0;
    rotation.add("z", Setting::TypeInt) = 0;
}

void RayTracer::Export::writeSphere(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &primitiveSetting = parent.exists("primitives") ? parent["primitives"] : parent.add("primitives", Setting::TypeGroup);
    Setting &list = primitiveSetting.exists("spheres") ? primitiveSetting["spheres"] : primitiveSetting.add("spheres", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("x", Setting::TypeInt) = stoi(infos["x"]);
    newObj.add("y", Setting::TypeInt) = stoi(infos["y"]);
    newObj.add("z", Setting::TypeInt) = stoi(infos["z"]);
    newObj.add("r", Setting::TypeInt) = stoi(infos["radius"]);

    Setting &colorSetting = newObj.add("color", Setting::TypeGroup);
    colorSetting.add("r", Setting::TypeInt) = stoi(infos["color_r"]);
    colorSetting.add("g", Setting::TypeInt) = stoi(infos["color_g"]);
    colorSetting.add("b", Setting::TypeInt) = stoi(infos["color_b"]);
}

void RayTracer::Export::writeCylinder(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &primitiveSetting = parent.exists("primitives") ? parent["primitives"] : parent.add("primitives", Setting::TypeGroup);
    Setting &list = primitiveSetting.exists("cylinders") ? primitiveSetting["cylinders"] : primitiveSetting.add("cylinders", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("x", Setting::TypeInt) = stoi(infos["x"]);
    newObj.add("y", Setting::TypeInt) = stoi(infos["y"]);
    newObj.add("z", Setting::TypeInt) = stoi(infos["z"]);
    newObj.add("r", Setting::TypeInt) = stoi(infos["radius"]);

    Setting &normalSetting = newObj.add("normal", Setting::TypeGroup);
    normalSetting.add("x", Setting::TypeInt) = stoi(infos["normal_x"]);
    normalSetting.add("y", Setting::TypeInt) = stoi(infos["normal_y"]);
    normalSetting.add("z", Setting::TypeInt) = stoi(infos["normal_z"]);

    Setting &colorSetting = newObj.add("color", Setting::TypeGroup);
    colorSetting.add("r", Setting::TypeInt) = stoi(infos["color_r"]);
    colorSetting.add("g", Setting::TypeInt) = stoi(infos["color_g"]);
    colorSetting.add("b", Setting::TypeInt) = stoi(infos["color_b"]);
}

void RayTracer::Export::writeCone(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &primitiveSetting = parent.exists("primitives") ? parent["primitives"] : parent.add("primitives", Setting::TypeGroup);
    Setting &list = primitiveSetting.exists("cones") ? primitiveSetting["cones"] : primitiveSetting.add("cones", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("x", Setting::TypeInt) = stoi(infos["x"]);
    newObj.add("y", Setting::TypeInt) = stoi(infos["y"]);
    newObj.add("z", Setting::TypeInt) = stoi(infos["z"]);
    newObj.add("r", Setting::TypeInt) = stoi(infos["radius"]);

    Setting &normalSetting = newObj.add("normal", Setting::TypeGroup);
    normalSetting.add("x", Setting::TypeInt) = stoi(infos["normal_x"]);
    normalSetting.add("y", Setting::TypeInt) = stoi(infos["normal_y"]);
    normalSetting.add("z", Setting::TypeInt) = stoi(infos["normal_z"]);

    Setting &colorSetting = newObj.add("color", Setting::TypeGroup);
    colorSetting.add("r", Setting::TypeInt) = stoi(infos["color_r"]);
    colorSetting.add("g", Setting::TypeInt) = stoi(infos["color_g"]);
    colorSetting.add("b", Setting::TypeInt) = stoi(infos["color_b"]);
}

void RayTracer::Export::writePlane(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &primitiveSetting = parent.exists("primitives") ? parent["primitives"] : parent.add("primitives", Setting::TypeGroup);
    Setting &list = primitiveSetting.exists("planes") ? primitiveSetting["planes"] : primitiveSetting.add("planes", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("x", Setting::TypeInt) = stoi(infos["x"]);
    newObj.add("y", Setting::TypeInt) = stoi(infos["y"]);
    newObj.add("z", Setting::TypeInt) = stoi(infos["z"]);

    Setting &normalSetting = newObj.add("normal", Setting::TypeGroup);
    normalSetting.add("x", Setting::TypeInt) = stoi(infos["normal_x"]);
    normalSetting.add("y", Setting::TypeInt) = stoi(infos["normal_y"]);
    normalSetting.add("z", Setting::TypeInt) = stoi(infos["normal_z"]);

    Setting &colorSetting = newObj.add("color", Setting::TypeGroup);
    colorSetting.add("r", Setting::TypeInt) = stoi(infos["color_r"]);
    colorSetting.add("g", Setting::TypeInt) = stoi(infos["color_g"]);
    colorSetting.add("b", Setting::TypeInt) = stoi(infos["color_b"]);
}


void RayTracer::Export::writePointLight(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &lightsSetting = parent.exists("lights") ? parent["lights"] : parent.add("lights", Setting::TypeGroup);
    Setting &list = lightsSetting.exists("points") ? lightsSetting["points"] : lightsSetting.add("points", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("x", Setting::TypeInt) = stoi(infos["x"]);
    newObj.add("y", Setting::TypeInt) = stoi(infos["y"]);
    newObj.add("z", Setting::TypeInt) = stoi(infos["z"]);
    newObj.add("intensity", Setting::TypeFloat) = stof(infos["intensity"]);
}

void RayTracer::Export::writeAmbientLight(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &lightsSetting = parent.exists("lights") ? parent["lights"] : parent.add("lights", Setting::TypeGroup);
    Setting &list = lightsSetting.exists("ambients") ? lightsSetting["ambients"] : lightsSetting.add("ambients", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("intensity", Setting::TypeFloat) = stof(infos["intensity"]);
}

void RayTracer::Export::writeDirectionnalLight(Setting& parent, std::map<std::string, std::string> infos)
{
    Setting &lightsSetting = parent.exists("lights") ? parent["lights"] : parent.add("lights", Setting::TypeGroup);
    Setting &list = lightsSetting.exists("directionals") ? lightsSetting["directionals"] : lightsSetting.add("directionals", Setting::TypeList);
    Setting &newObj = list.add(Setting::TypeGroup);

    newObj.add("x", Setting::TypeInt) = stoi(infos["x"]);
    newObj.add("y", Setting::TypeInt) = stoi(infos["y"]);
    newObj.add("z", Setting::TypeInt) = stoi(infos["z"]);
    newObj.add("intensity", Setting::TypeFloat) = stof(infos["intensity"]);

    if (infos.find("color_r") != infos.end()) {
        Setting &colorSetting = newObj.add("color", Setting::TypeGroup);
        colorSetting.add("r", Setting::TypeInt) = stoi(infos["color_r"]);
        colorSetting.add("g", Setting::TypeInt) = stoi(infos["color_g"]);
        colorSetting.add("b", Setting::TypeInt) = stoi(infos["color_b"]);
    }
}

void RayTracer::Export::writeIntoFile(std::unique_ptr<RayTracer::Camera> &camera, std::shared_ptr<RayTracer::Mediator> mediator, std::string filename)
{
    try {
        Config cfg;

        Setting &root = cfg.getRoot();

        root.add("version", Setting::TypeInt) = 2;
        root.add("name", Setting::TypeString) = "Exported configuration";

        if (camera != nullptr)
            writeCamera(cfg, camera);

        for (auto &object : mediator->getObjects()) {
            for (auto _functions : _writeFunctions) {
                if (object->getInfos()["type"] == _functions.first) {
                    _functions.second(root, object->getInfos());
                }
            }
        }
        for (auto &light : mediator->getLights()) {
            std::cout << light->getInfos()["type"] << std::endl;
            for (auto _functions : _writeFunctions) {
                if (light->getInfos()["type"] == _functions.first) {
                    _functions.second(root, light->getInfos());
                }
            }
        }
        cfg.writeFile(filename.c_str());
        cout << "New configuration successfully written to: " << filename << endl;
    } catch(const FileIOException &fioex) {
        cerr << "I/O error while writing file: " << filename << endl;
        return;
    } catch(const SettingTypeException &fioex) {
        cerr << "I/O error while writing file: " << filename << endl;
        return;
    }
}
