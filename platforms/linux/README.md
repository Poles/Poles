Linux
=============
The SDL2 packages for Ubuntu 12.04 are provided for convenience since only the old 1.2 version of the framework is available from the official repositories. Just install them throught your package manager as usual.

You can compile SDL2 yourself running the following commands from a terminal in the `SDL2-2.0.0` folder:

1. `./configure`.
2. `make`.
3. `sudo make install`.

For Artemis-Cpp we provide a compiled version (Ubuntu 12.04 again) of the framework linked to the NetBeans' project.

You can compile and install Artemis-Cpp your self by running the following commands from a terminal in the `Artemis-Cpp` folder:

1. `make`.
2. `sudo make install`.

## Troubleshoot
If you have problems running the app after compiling or trying to debug because of missing libraries you should add `/usr/local/lib` to your `LD_LIBRARY_PATH` system's variable or do the following (tested on Ubuntu):

1. Create a new file called `.conf` in `/etc/ld.so.conf.d/`.
2. Edit the new file an add a new line with the following: `/usr/local/lib`.
3. Run `sudo ldconfig`.
4. Profit.