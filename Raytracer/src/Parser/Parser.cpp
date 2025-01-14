/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Parser
*/

#include "Parser/Parser.hpp"

using namespace std;
using namespace libconfig;

RayTracer::Parser::Parser(std::string file, std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> &loaders) :
    _loaders(loaders)
{
    _mediator = std::make_shared<RayTracer::Mediator>();
    _cam = nullptr;
    readConfigFile(file);
}

void RayTracer::Parser::readConfigFile(std::string file)
{
    readFile(file);
    readCamera();
    readScenes();
}

void RayTracer::Parser::readScenes(void)
{
    try {
        const Setting& root = _cfg.getRoot();
        const Setting& scene = root["scene"];

        readConfigFile(scene);
    } catch(const SettingNotFoundException &nfex) {
        cerr << "No 'scene' setting in configuration file." << endl;
    }
}

void RayTracer::Parser::readCamera(void)
{
    try {
        const Setting &root = _cfg.getRoot();
        const Setting &camera = root["camera"];
        const Setting &resolution = camera["resolution"];
        const Setting &position = camera["position"];
        const Setting &rotation = camera["rotation"];
        int width, height, x_pos, y_pos, z_pos, x_rot, y_rot, z_rot;
        _cam = std::make_unique<RayTracer::Camera>();

        if (resolution.lookupValue("width", width) && resolution.lookupValue("height", height)) {
            cout << "Camera resolution: " << width << "x" << height << endl;
        } else {
            cerr << "Missing or invalid camera resolution settings." << endl;
        }
        if (position.lookupValue("x", x_pos) && position.lookupValue("y", y_pos) && position.lookupValue("z", z_pos)) {
            cout << "Camera position: x: " << x_pos << " y: " << y_pos << " z: " << z_pos << endl;
        } else {
            cerr << "Missing or invalid camera position settings." << endl;
        }
        if (rotation.lookupValue("x", x_rot) && rotation.lookupValue("y", y_rot) && rotation.lookupValue("z", z_rot)) {
            cerr << "Camera rotation: x: " << x_rot << " y: " << y_rot << " z: " << z_rot << endl;
        } else {
            cerr << "Missing or invalid camera rotation settings." << endl;
        }

        _cam->setResolution(width, height);
        _cam->moveTo(Math::Point3D(x_pos, y_pos, z_pos));
     
        _cam->rotateX(x_rot);
        _cam->rotateY(y_rot);
        _cam->rotateZ(z_rot);

    } catch(const SettingNotFoundException &nfex) {
        cerr << "No 'camera' setting in configuration file." << endl;
        if (_cam == nullptr)
            exit(84);
    }
}

void RayTracer::Parser::readPointLights(void)
{
    try {
        const Setting& root = _cfg.getRoot();
        const Setting& lights = root["lights"];
        const Setting& points = lights["points"];
        int x, y, z, r, g, b;
        float intensity;

        int length = points.getLength();
        for(int i = 0; i < length; ++i) {
            const Setting& point = points[i];
            if (point.exists("color")) {
                const Setting& color = point["color"];
                if (!(color.lookupValue("r", r) &&
                        color.lookupValue("g", g) &&
                        color.lookupValue("b", b))) {
                    cerr << "Error reading a point light at index " << i << "." << endl;
                    continue;
                }
            }
            if (!(point.lookupValue("x", x) &&
                    point.lookupValue("y", y) &&
                    point.lookupValue("z", z) &&
                    point.lookupValue("intensity", intensity))) {
                cerr << "Error reading a point light at index " << i << "." << endl;
                continue;
            }
            if (intensity < 0 || intensity > 1) {
                cerr << "Error reading a point light at index " << i << ": intensity must be between 0-1." << endl;
                continue;
            }
            _mediator->addLight(std::make_unique<RayTracer::PointLight>(_mediator, x, y, z, intensity));
        }
    } catch(const SettingNotFoundException &nfex) {
        cerr << "No 'lights' setting in configuration file." << endl;
    }
}

void RayTracer::Parser::readAmbientLights(void)
{
    try {
        const Setting& root = _cfg.getRoot();
        const Setting& lights = root["lights"];
        const Setting& ambients = lights["ambients"];
        float intensity;
        int r, g, b;

        int length = ambients.getLength();
        for(int i = 0; i < length; ++i) {
            const Setting& ambient = ambients[i];
            if (ambient.exists("color")) {
                const Setting& color = ambient["color"];
                if (!(color.lookupValue("r", r) &&
                        color.lookupValue("g", g) &&
                        color.lookupValue("b", b))) {
                    cerr << "Error reading a ambient light at index " << i << "." << endl;
                    continue;
                }
            }
            if (!(ambient.lookupValue("intensity", intensity))) {
                cerr << "Error reading a ambient light at index " << i << "." << endl;
                continue;
            }
            if (intensity < 0 || intensity > 1) {
                cerr << "Error reading a ambient light at index " << i << ": intensity must be between 0-1." << endl;
                continue;
            }
            _mediator->addLight(std::make_unique<RayTracer::AmbientLight>(intensity));
        }
    } catch(const SettingNotFoundException &nfex) {
        cerr << "No 'ambient light' setting in configuration file." << endl;
    }
}

void RayTracer::Parser::readDirectionalLights(void)
{
    try {
        const Setting& root = _cfg.getRoot();
        const Setting& lights = root["lights"];
        const Setting& directionals = lights["directionals"];
        int x, y, z, r, g, b;
        float intensity;

        int length = directionals.getLength();
        for(int i = 0; i < length; ++i) {
            const Setting& directional = directionals[i];
            if (directional.exists("color")) {
                const Setting& color = directional["color"];
                if (!(color.lookupValue("r", r) &&
                        color.lookupValue("g", g) &&
                        color.lookupValue("b", b))) {
                    cerr << "Error reading a directional light at index " << i << "." << endl;
                    continue;
                }
            }
            if (!(directional.lookupValue("x", x) &&
                    directional.lookupValue("y", y) &&
                    directional.lookupValue("z", z) &&
                    directional.lookupValue("intensity", intensity))) {
                cerr << "Error reading a directional light at index " << i << "." << endl;
                continue;
            }
            if (intensity < 0 || intensity > 1) {
                cerr << "Error reading a directional light at index " << i << ": intensity must be between 0-1." << endl;
                continue;
            }
            _mediator->addLight(std::make_unique<RayTracer::DirectionnalLight>(_mediator, x, y, z, intensity));
        }
    } catch(const SettingNotFoundException &nfex) {
        cerr << "No 'directional light' setting in configuration file." << endl;
    }
}

void RayTracer::Parser::readRotation(const Setting &primitive, std::unique_ptr<RayTracer::IObject> &obj)
{
    float angle_1, angle_2, rot_x, rot_y, rot_z;

    if (primitive.exists("rotation")) {
        const Setting& rotation = primitive["rotation"];
        if (rotation.lookupValue("angle1", angle_1) &&
            rotation.lookupValue("angle2", angle_2) &&
            rotation.lookupValue("x", rot_x) &&
            rotation.lookupValue("y", rot_y) &&
            rotation.lookupValue("z", rot_z)){
            std::cout << "rotation" << std::endl;
            obj = std::make_unique<RayTracer::RotationDecorator>(std::move(obj), Math::Point3D(rot_x, rot_y, rot_z), angle_1, angle_2);
        }
    }
}

void RayTracer::Parser::readTransparency(const Setting &primitive, std::unique_ptr<RayTracer::IObject> &obj)
{
    double transparency;

    std::cout << "transparency" << std::endl;
    if (primitive.exists("transparency") && primitive.lookupValue("transparency", transparency)) {
        obj = std::make_unique<RayTracer::TransparenceTexture>(std::move(obj), transparency, _mediator);
    }
}

void RayTracer::Parser::readChestBoard(const Setting &primitive, std::unique_ptr<RayTracer::IObject> &obj)
{
    int chestBoard;

    std::cout << "chestBoard" << std::endl;
    if (primitive.exists("chestBoard") && primitive.lookupValue("chestBoard", chestBoard)) {
        obj = std::make_unique<RayTracer::SphericChessBoard>(std::move(obj), chestBoard);
    }
}

bool RayTracer::Parser::readAttributes(const Setting &primitive, int i, std::map<std::string, float> &params)
{
    int x, y, z, radius;

    if (!(primitive.lookupValue("x", x) &&
            primitive.lookupValue("y", y) &&
            primitive.lookupValue("z", z))) {
        cerr << "Error reading a primitive at index " << i << "." << endl;
        return false;
    }
    if (primitive.exists("r")) {
        primitive.lookupValue("r", radius);
        params["radius"] = radius;
    }
    params["x"] = x;
    params["y"] = y;
    params["z"] = z;
    return true;
}

bool RayTracer::Parser::readNormal(const Setting &primitive, int i, std::map<std::string, float> &params)
{
    int normal_x, normal_y, normal_z;

    if (primitive.exists("normal")) {
        const Setting& normal = primitive["normal"];
        if (!(normal.lookupValue("x", normal_x) &&
                normal.lookupValue("y", normal_y) &&
                normal.lookupValue("z", normal_z))) {
            cerr << "Error reading a primitive at index " << i << "." << endl;
            return false;
        }
        params["normal_x"] = normal_x;
        params["normal_y"] = normal_y;
        params["normal_z"] = normal_z;
    }
    return true;
}

void RayTracer::Parser::readOnePrimitiveType(std::string primitive_name, const Setting &objects)
{
    std::map<std::string, float> params;

    if (_loaders.find(primitive_name) == _loaders.end()) {
        _loaders[primitive_name] = make_unique<DLLdr::DLLoader<IObject>>();
        _loaders[primitive_name]->open("./plugins/raytracer_" + primitive_name + ".so");
    }
    const Setting &primitives = objects[primitive_name];
    int r, g, b;
    int length = primitives.getLength();

    for(int i = 0; i < length; ++i) {
        const Setting& primitive = primitives[i];
        const Setting& color = primitive["color"];
        if (!readAttributes(primitive, i, params))
            continue;
        if (!readNormal(primitive, i, params))
            continue;
        if (!(color.lookupValue("r", r) &&
                color.lookupValue("g", g) &&
                color.lookupValue("b", b))) {
            cerr << "Missing color for primitive at index " << i << "." << endl;
            continue;
        }
        std::unique_ptr<IObject> obj_ptr = _loaders[primitive_name]->getSym();
        obj_ptr->fromMap(params);
        obj_ptr = std::make_unique<BasicTexture> (std::move(obj_ptr), std::array<int, 3> {r, g, b});
        readRotation(primitive, obj_ptr);
        readTransparency(primitive, obj_ptr);
        readChestBoard(primitive, obj_ptr);
        _mediator->addObject(std::move(obj_ptr));
    }
}

void RayTracer::Parser::readPrimitives(void)
{
    try {
        const Setting& root = _cfg.getRoot();
        const Setting& objects = root["primitives"];
        const std::array<std::string, 4> primitive_names = {"spheres", "planes", "cylinders", "cones"};
        for (const auto &primitive_name : primitive_names) {
            readOnePrimitiveType(primitive_name, objects);
        }
    } catch(const SettingNotFoundException &nfex) {
        cerr << "No 'primitives primitive' setting in configuration file." << endl;
    }
}

void RayTracer::Parser::readFile(std::string file)
{
    try
    {
        _cfg.readFile(file.c_str());
    }
    catch(const FileIOException &fioex)
    {
        // create a std::exception() class and throw it;
        cerr << "I/O error while reading file." << endl;
        return;
    }
    catch(const ParseException &pex)
    {
        cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << endl;
        return;
    }

    // readLight();
    readAmbientLights();
    readPointLights();
    readDirectionalLights();
    readPrimitives();
}

std::shared_ptr<RayTracer::Mediator> RayTracer::Parser::getMediator() const
{
    return _mediator;
}

std::unique_ptr<RayTracer::Camera> &RayTracer::Parser::getCamera()
{
    return _cam;
}

RayTracer::Parser::~Parser()
{
}
