#!/bin/bash

# Check if it is run using sudo or as root
if [[ $(/usr/bin/id -u) -ne 0 ]]; then
	echo "This script must be run as root";
else
	echo "This script will compile and install all the required libraries.";
	echo "You need Python in your system to actually build JsonCpp since it uses scons.py.";
	echo "Please, make sure you have installed Python in your system and it is accesible from you PATH variable.";
	echo "scons is provided within JsonCpp so you don't need to download it.";
	echo "Do you want to continue? [y/n]"

	read -n 1 -s cont;

	if [ "$cont" == "y" ]; then
		echo "Entering Artemis-Cpp/";
		cd "Artemis-Cpp";
		echo "Compiling Artemis-Cpp.";
		make;
		echo "Installing Artemis-Cpp into the system. This will copy libartemis.a to /usr/local/lib and the header files to /usr/local/include/Artemis.";
		make install;
		echo "Leaving Artemis-Cpp/";
		cd ..;

		echo "Entering JsonCpp/";
		cd JsonCpp;
		echo "Compiling JsonCpp.";
		python scons.py platform=linux-gcc check;
		echo "Installing JsonCpp.";
		cp -r include /usr/local/include;
		cp libs/*/*.a /usr/local/lib;
		# We need to eliminate the compiler sufix to make it platform independent
		ln -s /usr/local/lib/libjson*.a /usr/local/lib/libjson.a;
		echo "Leaving JsonCpp/.";
		cd ..;

		echo "Entering SDL2-2.0.0/";
		cd SDL2-2.0.0;
		echo "Compiling SDL2";
		./autogen;
		./configure;
		make;
		echo "Installing SDL2";
		make install;
		echo "Leaving SDL2-2.0.0/";
		cd ..;

		echo "Entering SDL2_image-2.0.0/.";
		cd SDL2_image-2.0.0;
		echo "Compiling SDL2_image.";
		./autogen;
		./configure;
		make;
		echo "Installing SDL2_image.";
		make install;
		echo "Leaving SDL2_image-2.0.0/.";
		cd ..;

		echo "Entering SDL2_ttf-2.0.12/.";
		cd SDL2_ttf-2.0.12;
		echo "Compiling SDL2_ttf.";
		./autogen;
		./configure;
		make;
		echo "Installing SDL2_ttf.";
		make install;
		echo "Leaving SDL2_ttf-2.0.12/.";

		echo "ALL LIBRARIES WERE INSTALLED INTO YOUR SYSTEM!";
	else
		echo "Cancelling the libraries' installation.";
	fi
fi
