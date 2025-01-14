/*
** EPITECH PROJECT, 2024
** SFML.cpp
** File description:
** SFML
*/

#include "SFML/SFML.hpp"

SFML::SFML(std::shared_ptr<RayTracer::Mediator> mediator, std::unique_ptr<RayTracer::Camera> &cam, int width, int height) :
    // _window(sf::VideoMode(width, height), "Ray Tracer"),
    _mediator(mediator),
    _cam(cam),
    _i(0),
    _j(0),
    _width(width),
    _height(height),
    _precision(2048)
{

    // _window.setFramerateLimit(60);
    _image.create(width, height, sf::Color::Black);
    displayImage();
}

SFML::~SFML()
{}

void SFML::setColorOnScreen(int r, int g, int b)
{
    if (_i * _precision >= _height || _j * _precision >= _width)
        return;
    _image.setPixel(_j * _precision, _i * _precision, sf::Color(r, g, b));
}

void SFML::display()
{
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
    _window.clear();
    _window.draw(_sprite);
    _window.display();
}

void SFML::advanceImageCursor()
{
    if ((_i * _precision) > (_height)) {
        if (_precision <= 1) {
            return;
        }
        _precision /= 8;
        _i = 0;
        _j = 0;
        display();
        return;
    }
    _j += 1;
    if ((_j * _precision) > _width) {
        _j = 0;
        _i += 1;
        if (_i % 10 == 0)
            display();
    }
}

void SFML::updateImage()
{
    _i = 0;
    _j = 0;
    _precision = 2048;
    _image.create(_width, _height, sf::Color::Black);
}

void SFML::moveCamera(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        auto it = _keyMap.find(event.key.code);
        if (it != _keyMap.end()) {
            it->second();
            updateImage();
        }
    }
}

void SFML::displayImage()
{
    struct RayTracer::bounce b;
    struct RayTracer::Color c;

    _keyMap = {
        {sf::Keyboard::Up, std::bind([this](){ this->_cam->moveUp(-1); })},
        {sf::Keyboard::Down, std::bind([this](){ this->_cam->moveUp(1); })},
        {sf::Keyboard::Left, std::bind([this](){ this->_cam->moveLeft(-1); })},
        {sf::Keyboard::Right, std::bind([this](){ this->_cam->moveLeft(1); })},
        {sf::Keyboard::Z, std::bind([this](){ this->_cam->moveForward(1); })},
        {sf::Keyboard::S, std::bind([this](){ this->_cam->moveForward(-1); })},
        {sf::Keyboard::Q, std::bind([this](){ this->_cam->rotateY(-1); })},
        {sf::Keyboard::D, std::bind([this](){ this->_cam->rotateY(1); })}
    };

    _precision = 1;

    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            RayTracer::Ray r = _cam->ray(i, j);
            b = _mediator->hits(r);
            c = _mediator->lights(b);
            _i = i;
            _j = j;
            this->setColorOnScreen(c.ri(), c.gi(), c.bi());
            // this->advanceImageCursor();
        }
    }

    // while (_window.isOpen()) {
    //     sf::Event event;
    //     while (_window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed) {
    //             _window.close();
    //         }
    //         moveCamera(event);
    //     }
    //     if ((_i * _precision) > (_height) && (_precision <= 1)) {
    //         continue;
    //     }
    //     RayTracer::Ray r = _cam->ray(_i * _precision, _j * _precision);
    //     b = _mediator->hits(r);
    //     c = _mediator->lights(b);
    //     this->setColorOnScreen(c.ri(), c.gi(), c.bi());
    //     this->advanceImageCursor();
    // }
    _image.saveToFile("./output.jpg");
}