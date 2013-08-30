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
3. Copy `.lib` files in `platforms/windows/Artemis-Cpp/lib` to your MinGW's `lib` folder.
4. Create a new folder named `Artemis` in your MinGW installation (`C:\MinGW\include`).
5. Copy all `.h` files from `platforms/windows/Artemis-Cpp/include` EXCEPT `Artemis.h` to the folder you just created.
6. Copy `Artemis.h` to your include folder (not the Artemis folder) `C:\MinGW\include`.
7. Open `platforms/windows/Poles`.

Once you build the application you will need to copy `platforms/windows/SDL2/bin/SDL.dll` to the folder where the executable is (commonly in `platforms/windows/Poles/dist/Debug/MinGW-Windows/`).

### Mac OS X
1. Install XCode.
2. Copy `platforms/macosx/SDL/SDL2.framework` to your system's `/Library/Frameworks` folder.
3. Run `make` and `make install` from a terminal inside the Artemis-Cpp folder `platforms/linux/Artemis-Cpp`. It will install the library and headers files into your system.
4. Open `platforms/macosx/Poles.xcodeproj`.

### Linux
1. Install NetBeans.
2. Install development libraries for SDL2 from your package manager. You can find `.deb` packages for Ubuntu in `platforms/linux/SDL2`.
3. Run `make` and `make install` from a terminal inside the Artemis-Cpp folder `platforms/linux/Artemis-Cpp`. It will install the library and headers files into your system.
4. Open platforms/linux/Poles with NetBeans.

The SDL2 packages comes from Joseba Garcia Etxeberria's repository [here](https://launchpad.net/~josebagar/+archive/sdl2). Thanks man.

## Credits
This project is developed by [@L4D15](http://twitter.com/L4D15) and [@OmeGak](http://twitter.com/OmeGak) when duties allow.

## License
Poles engine is released under GPL version 3 or later.
Poles art and data files are released under CC-BY-SA 3.0 or later.
