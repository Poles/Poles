Poles
=====
Poles is a SDL-based video game in which one has to play with magnets' attractive/repulsive forces in order to beat several puzzles.

This project's main purpose is to explore and learn the basics of game development and to have some fun meanwhile. The goals to be achieved are:
* Deploy a cross-platform application
* Implement engaging game mechanics
* Get experience using SDL developing a basic engine for:
    1. Animations
    1. Physics
    1. Sounds
    1. GUI

## Building Poles
To build Poles, use the IDE projects we provide and follow the instructions in this file.

### Windows
1. Install NetBeans, MinGW and MSYS.
2. Copy `.lib` files in `platforms/windows/SDL2/lib` to your MinGW's `lib` folder.
3. Copy `.lib` files in `platforms/windows/Artemis-Cpp/lib/` to your MinGW's `lib` folder.
4. Open `platforms/windows/Poles`.

Once you build the application you will need to copy `platforms/windows/SDL2/bin/SDL.dll` to the folder where the executable created is (commonly in `platforms/windows/Poles/dist/Debug/MinGW-Windows/`).

### Mac OS X
1. Install XCode.
2. Open platforms/macosx/Poles.xcodeproj

### Linux
1. Install NetBeans.
2. Install development libraries for SDL2 from your package manager. You can find `.deb` packages for Ubuntu in `platforms/linux/SDL2`.
3. Open platforms/linux/Poles with NetBeans.

The SDL2 packages comes from Joseba Garcia Etxeberria's repository [here](https://launchpad.net/~josebagar/+archive/sdl2). Thanks man.

## Credits
This project is developed by [@L4D15](http://twitter.com/L4D15) and [@OmeGak](http://twitter.com/OmeGak) when duties allow.

## License
Poles engine is released under GPL version 3 or later.
Poles art and data files are released under CC-BY-SA 3.0 or later.
