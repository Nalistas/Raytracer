/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Core
*/

#include "Core/Core.hpp"
#include <memory>

RayTracer::Core::Core()
{}

RayTracer::Core::~Core()
{}

void RayTracer::Core::help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>\n SCENE_FILE: scene configuration" << std::endl;
}

void RayTracer::Core::run(std::string file)
{
    std::unique_ptr<RayTracer::Camera> cam;
    std::shared_ptr<RayTracer::Mediator> mediator;
    std::map<std::string, std::unique_ptr<DLLdr::DLLoader<IObject>>> loaders;


    if (file == "-h") {
        help();
        return;
    }
    if (file == "-T") {
        RayTracer::Cli cli(loaders);
        cli.run();
        mediator = cli.getMediator();
        cam = std::move(cli.getCamera());
    } else {
        RayTracer::Parser parser(file, loaders);
        mediator = parser.getMediator();
        cam = std::move(parser.getCamera());
    }

    RayTracer::bounce b;
    RayTracer::Color c;
    double width = cam->getResolutionX();
    double height = cam->getResolutionY();

    std::ofstream outputFile("output.ppm");
    outputFile << "P3\n" << width << " " << height << "\n255\n";
    std::cout << width << " " << height << std::endl;

    for (double i = 0; i < height; i += 1) {
        for (double j = 0; j < width; j += 1) {
            RayTracer::Ray r = cam->ray(i, j);
            b = mediator->hits(r);
            c = mediator->lights(b);
            outputFile << (int)(c.ri()) << " " << (int)(c.gi()) << " " << (int)(c.bi()) << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();

    // SFML sfml(mediator, cam, width, height);
}
