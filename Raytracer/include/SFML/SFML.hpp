/*
** EPITECH PROJECT, 2024
** SFML.hpp
** File description:
** SFML
*/

#ifndef SFML_HPP_
    #define SFML_HPP_
    #include <SFML/Graphics.hpp>
    #include <functional>
    #include "Mediator/Mediator.hpp"
    #include "3D/Camera.hpp"

class SFML {
    public:
        SFML(std::shared_ptr<RayTracer::Mediator> mediator, std::unique_ptr<RayTracer::Camera> &cam, int width, int height);
        ~SFML();
        void displayImage();
        void setColorOnScreen(int r, int g, int b);
        void advanceImageCursor();
        void display();
        void moveCamera(sf::Event event);

        // void moveUp();
        // void moveLeft();
        // void moveForward();
        // void rotateLeft();
        // void rotateRight();

        void updateImage();

    private:
        sf::Image _image;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::RenderWindow _window;
        std::shared_ptr<RayTracer::Mediator> _mediator;
        std::unique_ptr<RayTracer::Camera> &_cam;
        int _i;
        int _j;
        int _width;
        int _height;
        double _precision;
        std::map<sf::Keyboard::Key, std::function<void()>> _keyMap;
};

#endif /* !SFML_HPP_ */
