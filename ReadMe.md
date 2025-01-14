# Raytracer
## Introduction

This repository houses our second-year project at Epitech named "Raytracer". The project entails the implementation of ray tracing, a distinct 3D rendering algorithm, divergent from those commonly used in the video game industry. We accomplish this task using C++ with the assistance of the SFML graphical library.

# Table of content

* Introduction
* How To Build
* Implement config file 
* Features
* Dependancy
* Terminology
* Reference
* Our Team

# How To Build

```
cd B-OOP-400-BAR-4-1-raytracer-hugo.tesson/
make -j -s
```

# Implement config file 

Create a .cfg file at the root of the repository.
Populate this file with a list of elements, allowing you to specify the objects to be included in your scene. Each primitive object should include parameters such as type, X, Y, Z positions, rotation (AxisX, AxisY, AxisZ), size (radius for spheres, width and length for planes), and RGB color.

Example of Light configuration:

```
lights :
{
    points = (
        { x = 10; y = -20; z = -15; intensity = 0.9;} //  intensity=[0-1]<
        { x = -10; y = 0; z = 15; intensity = 1.0;}, //  intensity=[0-1]
        { x = -3; y = 0; z = -2; intensity = 0.5;} //  intensity=[0-1]
    );

    ambients = (
        { intensity = 0.3 }
    );

    directionals = (
        {x = 1; y = 1; z = 0; intensity = 0.5}
    );
};
```

# Transparency

![Transparency](output/image.png)

# Dependancy

You need SFML, lconfig++ and ldl

## Lib SFML

SFML serves as a graphical programming interface designed for the creation of video games or interactive programms.

## C++

C++ is an object-oriented programming language.

## 3D

Three dimensions, three-dimensional or 3D are expressions that characterize the space that surrounds us.

# Reference

[libconfig](https://hyperrealm.github.io/libconfig/libconfig_manual.html)

# Authors' Addresses

Ambroise: ambroise.jacquemet-ramirez--vega@epitech.eu

Etienne: etienne.namur@epitech.eu

Lucia: lucia.jimenez-diaz@epitech.eu

Hugo: hugo.tesson@epitech.eu

Satine: satine.fouque@epitech.eu

Epitech Barcelona, 2024