/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** main
*/


// #include "SFML/SFML.hpp"

#include "Core/Core.hpp"

std::ofstream &operator<<(std::ofstream &outputFile, RayTracer::bounce const &bounce)
{
    if (std::isnan(bounce.t)) {
        outputFile << "0 0 0";
    } else {
        outputFile  << (int)(((255 / 2) * bounce.normal.getX()) + 255 / 2) << " " << (int)(((255 / 2) * bounce.normal.getY()) + 255 / 2) << " " << (int)(((255 / 2) * bounce.normal.getZ()) + 255 / 2);
    }
    return outputFile;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    RayTracer::Core core;
    core.run(av[1]);
    return 0;
}
