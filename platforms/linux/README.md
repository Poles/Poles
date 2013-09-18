Libraries
===========

Here you can find the source code for the libraries used in Poles. This source code is used to compile and link the librarys toward the executable using CMake.

You can compile them by yourself, but we recommend you to use the `install_libraries.sh` script that will do it automatically.

## Artemis-Cpp

Implements the Entity/Component system used throught Poles. It gives an incredible amount of freedom and abstraction for creating game objects.

You can check out this awesome project [here](http://github.com/vinova/Artemis-Cpp).

## JsonCpp

JSON files parsing to store data. It is used, for example, for Sprites animation information.

## SDL2

Used for basic rendering, window creation and event handling.

## SDL2_image

Submodule of SDL2 that allowed us to load image files of a variety of formats (usually PNG).

## SDL2_ttf

Text rendering using custom fonts.