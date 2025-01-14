/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include <iostream>
#include "Parser/Parser.hpp"
#include "Parser/Cli.hpp"
#include "../SFML/SFML.hpp"

namespace RayTracer {
    class Core {
        public:
            Core();
            ~Core();

            void run(std::string file);
            void help();

        protected:
    };
}

#endif /* !CORE_HPP_ */
