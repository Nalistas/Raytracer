/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cli
*/

#include "Parser/Cli.hpp"

RayTracer::Cli::Cli(std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> &loaders)
    : _loaders(loaders)
{
    _mediator = std::make_shared<RayTracer::Mediator>();
    _cam = nullptr;
    _commands = {
        {"exit", std::bind(&RayTracer::Cli::exitCli, this)},
        {"export", std::bind(&RayTracer::Cli::exportConfigFile, this)},
        {"help", std::bind(&RayTracer::Cli::display_help, this)},
        {"list", std::bind(&RayTracer::Cli::listPrimitives, this)},
        {"add sphere", std::bind(&RayTracer::Cli::parseSphere, this)},
        {"add cylinder", std::bind(&RayTracer::Cli::parseCylinder, this)},
        {"add cone", std::bind(&RayTracer::Cli::parseCone, this)},
        {"add plane", std::bind(&RayTracer::Cli::parsePlane, this)},
        {"add pointlight", std::bind(&RayTracer::Cli::parsePointLight, this)},
        {"add ambientlight", std::bind(&RayTracer::Cli::parseAmbientLight, this)},
        {"add directionallight", std::bind(&RayTracer::Cli::parseDirectionalLight, this)},
        {"add camera", std::bind(&RayTracer::Cli::parseCamera, this)}
    };
}

RayTracer::Cli::~Cli()
{
}

void RayTracer::Cli::exitCli()
{
    exit(0);
}

void RayTracer::Cli::exportConfigFile()
{
    Export exportConfig;
    std::string file;
    std::cout << "Enter the name of the file who want to save in: ";
    std::getline(std::cin, file);
    std::string filename = file;

    exportConfig.writeIntoFile(_cam, _mediator, filename);
}

void RayTracer::Cli::listPrimitives()
{
    if (_cam != nullptr) {
        _cam->printCamera();
        std::cout << std::endl;
    }
    for (auto &object : _mediator->getObjects()) {
        object->printObject();
        std::cout << std::endl;
    }
}

void RayTracer::Cli::run()
{
    std::string primitive;
    int check = 0;

    while (true) {
        check = 0;
        std::cout << "Enter a command or help: ";
        std::getline(std::cin, primitive);
        for (auto &command : _commands) {
            if (primitive == "render") {
                check = 1;
                if (_cam == nullptr) {
                    std::cout << "You must add a camera" << std::endl;
                    break;
                }
                return;
            }
            if (primitive == command.first) {
                check = 1;
                command.second();
                break;
            }
        }
        if (check == 0)
            std::cout << "Command not found\n" << std::endl;
        std::cin.clear();
    }
}

void RayTracer::Cli::display_help(void)
{
    std::cout << "Commands available:" << std::endl;
    std::cout << "\tadd sphere" << std::endl;
    std::cout << "\tadd cylinder" << std::endl;
    std::cout << "\tadd cone" << std::endl;
    std::cout << "\tadd plane" << std::endl;
    std::cout << "\tadd pointlight" << std::endl;
    std::cout << "\tadd ambientlight" << std::endl;
    std::cout << "\tadd camera\n" << std::endl;
    std::cout << "\tlist" << std::endl;
    std::cout << "\trender" << std::endl;
    std::cout << "\texit" << std::endl;
    std::cout << "\texport" << std::endl;
}

int RayTracer::Cli::promptForInt(std::string prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cerr << "Input must be a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::array<int, 3> RayTracer::Cli::getXYZ(std::string type)
{
    int x = promptForInt("Enter the x value for the " + type + ": ");
    int y = promptForInt("Enter the y value for the " + type + ": ");
    int z = promptForInt("Enter the z value for the " + type + ": ");
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    return {x, y, z};
}

int RayTracer::Cli::promptForColor(std::string prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if ((std::cin >> value) && (value >= 0 && value <= 255)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cerr << "Input must be a number between 0 and 255." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::array<int, 3> RayTracer::Cli::getColor(std::string type) {
    int r = promptForColor("Enter the r color value for the " + type + ": ");
    int g = promptForColor("Enter the g color value for the " + type + ": ");
    int b = promptForColor("Enter the b color value for the " + type + ": ");
    std::cout << "r: " << r << ", g: " << g << ", b: " << b << std::endl;
    return {r, g, b};
}

int RayTracer::Cli::getRadius(std::string type)
{
    int radius;

    std::cout << "Enter the radius for the " << type << ": ";
    if (!(std::cin >> radius) || radius < 0) {
        std::cerr << "Radius cannot be negative" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getRadius(type);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Radius: " << radius << std::endl;
    return radius;
}

void RayTracer::Cli::parseSphere()
{
    if (_loaders.find("spheres") == _loaders.end()) {
        _loaders["spheres"] = std::make_unique<DLLdr::DLLoader<IObject>>();
        _loaders["spheres"]->open("./plugins/raytracer_spheres.so");
    }
    std::array<int, 3> coord = getXYZ("sphere");
    std::array<int, 3> color = getColor("sphere");
    double radius = getRadius("sphere");
    float transparency;
    std::map<std::string, float> params;

    while (true) {
        std::cout << "Enter the transparency for the sphere: ";
        if (!(std::cin >> transparency) || transparency < 0 || transparency > 1) {
            std::cerr << "transparency must be between 0 and 1" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::unique_ptr<IObject> obj_ptr = _loaders["spheres"]->getSym();
    params["x"] = coord[0];
    params["y"] = coord[1];
    params["z"] = coord[2];
    params["radius"] = radius;
    params["transparency"] = transparency;
    obj_ptr->fromMap(params);
    _mediator->addObject(
        std::make_unique<RayTracer::BasicTexture> (
            std::move(obj_ptr), std::array<int, 3> {color[0], color[1], color[2]}
        )
    );
}

void RayTracer::Cli::parseCylinder()
{
    if (_loaders.find("cylinders") == _loaders.end()) {
        _loaders["cylinders"] = std::make_unique<DLLdr::DLLoader<IObject>>();
        _loaders["cylinders"]->open("./plugins/raytracer_cylinders.so");
    }
    std::array<int, 3> coord = getXYZ("cylinder");
    std::array<int, 3> normal_coord = getXYZ("vector normal of the cylinder");
    std::array<int, 3> color = getColor("cylinder");
    int radius = getRadius("cylinder");
    float transparency;

    while (true) {
        std::cout << "Enter the transparency for the cylinder: ";
        if (!(std::cin >> transparency) || transparency < 0 || transparency > 1) {
            std::cerr << "transparency must be between 0 and 1" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::unique_ptr<IObject> obj_ptr = _loaders["cylinders"]->getSym();
    std::map<std::string, float> params;
    params["x"] = coord[0];
    params["y"] = coord[1];
    params["z"] = coord[2];
    params["normal_x"] = normal_coord[0];
    params["normal_y"] = normal_coord[1];
    params["normal_z"] = normal_coord[2];
    params["radius"] = radius;
    params["transparency"] = transparency;
    obj_ptr->fromMap(params);
    _mediator->addObject(
        std::make_unique<RayTracer::BasicTexture> (
            std::move(obj_ptr), std::array<int, 3> {color[0], color[1], color[2]}
        )
    );
}

void RayTracer::Cli::parseCone()
{
    if (_loaders.find("cones") == _loaders.end()) {
        _loaders["cones"] = std::make_unique<DLLdr::DLLoader<IObject>>();
        _loaders["cones"]->open("./plugins/raytracer_cones.so");
    }
    std::array<int, 3> coord = getXYZ("cone");
    std::array<int, 3> normal_coord = getXYZ("vector normal of the cone");
    std::array<int, 3> color = getColor("cone");
    int radius = getRadius("cone");
    float transparency;
    std::map<std::string, float> params;

    while (true) {
        std::cout << "Enter the transparency for the cone: ";
        if (!(std::cin >> transparency) || transparency < 0 || transparency > 1) {
            std::cerr << "transparency must be between 0 and 1" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::unique_ptr<IObject> obj_ptr = _loaders["cones"]->getSym();
    params["x"] = coord[0];
    params["y"] = coord[1];
    params["z"] = coord[2];
    params["normal_x"] = normal_coord[0];
    params["normal_y"] = normal_coord[1];
    params["normal_z"] = normal_coord[2];
    params["radius"] = radius;
    params["transparency"] = transparency;
    obj_ptr->fromMap(params);
    _mediator->addObject(
        std::make_unique<RayTracer::BasicTexture> (
            std::move(obj_ptr), std::array<int, 3> {color[0], color[1], color[2]}
        )
    );
}

void RayTracer::Cli::parsePlane()
{
    if (_loaders.find("planes") == _loaders.end()) {
        _loaders["planes"] = std::make_unique<DLLdr::DLLoader<IObject>>();
        _loaders["planes"]->open("./plugins/raytracer_planes.so");
    }
    std::array<int, 3> coord = getXYZ("plane");
    std::array<int, 3> normal_coord = getXYZ("vector normal of the plane");
    std::array<int, 3> color = getColor("plane");
    float transparency;
    std::map<std::string, float> params;

    while (true) {
        std::cout << "Enter the transparency for the plane: ";
        if (!(std::cin >> transparency) || transparency < 0 || transparency > 1) {
            std::cerr << "transparency must be between 0 and 1" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::unique_ptr<IObject> obj_ptr = _loaders["planes"]->getSym();
    params["x"] = coord[0];
    params["y"] = coord[1];
    params["z"] = coord[2];
    params["normal_x"] = normal_coord[0];
    params["normal_y"] = normal_coord[1];
    params["normal_z"] = normal_coord[2];
    params["transparency"] = transparency;
    obj_ptr->fromMap(params);
    _mediator->addObject(
        std::make_unique<RayTracer::BasicTexture> (
            std::move(obj_ptr), std::array<int, 3> {color[0], color[1], color[2]}
        )
    );
}

void RayTracer::Cli::parsePointLight()
{
    std::array<int, 3> coord = getXYZ("point light");
    float intensity;

    while (true) {
        std::cout << "Enter the intensity for the point light: ";
        if (!(std::cin >> intensity) || intensity < 0 || intensity > 1) {
            std::cerr << "Intensity must be between 0 and 1" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "intensity: " << intensity << std::endl;

    _mediator->addLight(std::make_unique<RayTracer::PointLight>(_mediator, coord[0], coord[1], coord[2], intensity));
}

void RayTracer::Cli::parseDirectionalLight()
{
    std::array<int, 3> coord = getXYZ("directional light");
    float intensity;

    while (true) {
    std::cout << "Enter the intensity for the directional light: ";
        if (!(std::cin >> intensity) || intensity < 0 || intensity > 1) {
            std::cerr << "Intensity must be between 0 and 1" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "intensity: " << intensity << std::endl;

    _mediator->addLight(std::make_unique<RayTracer::DirectionnalLight>(_mediator, coord[0], coord[1], coord[2], intensity));
}

void RayTracer::Cli::parseAmbientLight()
{
    float intensity;

    std::cout << "Enter the intensity for the ambient light: ";
    if (!(std::cin >> intensity) || intensity < 0 || intensity > 1) {
        std::cerr << "Intensity must be between 0 and 1" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        parseAmbientLight();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "intensity: " << intensity << std::endl;

    _mediator->addLight(std::make_unique<RayTracer::AmbientLight>(intensity));
}

void RayTracer::Cli::parseCamera()
{
    if (_cam != nullptr) {
        std::cout << "Camera already added" << std::endl;
        return;
    }
    std::array<int, 3> coord = getXYZ("camera");
    std::array<int, 3> rot = getXYZ("rotation of the camera");
    int height = promptForInt("Enter the height of the camera: ");
    int width = promptForInt("Enter the width of the camera: ");

    std::cout << "height: " << height << ", width: " << width << std::endl;
    _cam = std::make_unique<RayTracer::Camera>();
    _cam->setResolution(width, height);
    _cam->moveTo(Math::Point3D(coord[0], coord[1], coord[2]));
    _cam->setOrigin(Math::Point3D(coord[0], coord[1], coord[2]));
    _cam->rotateX(rot[0]);
    _cam->rotateY(rot[1]);
    _cam->rotateZ(rot[2]);
}

std::shared_ptr<RayTracer::Mediator> RayTracer::Cli::getMediator()
{
    return _mediator;
}

std::unique_ptr<RayTracer::Camera> &RayTracer::Cli::getCamera()
{
    return _cam;
}
