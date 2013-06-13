Poles
=======
Description here.

## Configure project

In order to compile Poles you need to configure some libraries in your project:

* SDL2.
* OpenGL.

We'll explain how to download, install and configure those libraries to create a working project of Poles in each platform.

### Windows

Work in progress...

### OS X

We will use XCode to create our project and configure the libraries. Using OS X and XCode needs some extra work compared to other platforms but it is not that hard, don't worry ;-)


Here is a quick guide for configuring the project. A more detailed guide is presented after this one:

1. Download the necesary SDL2 development libraries for OS X from the official SDL website.
2. Install them following the instructions in the Readme file of each library.
3. Create a new Cocoa Application for OS X.
4. Add OpenGL and SDL2 libraries to the project linked libraries.
5. Add SDL2 libraries' Headers folder path to the "Header Search Path" option in the "Build Settings" tab.
6. Add a new Build step to copy the SDL2 Frameworks to the Frameworks folder of the compiled application.
7. Move the frameworks' files added to your project navigator to the Frameworks folder.
8. Delete every file outside the "Supporting Files" folder in the "Project Navigator".
9. Clone de repository inside the project.
10. Profit.

Download the development libraries for SDL2 from the official website (or click this [link](http://www.libsdl.org/tmp/release/SDL2-2.0.0.dmg) to download it). Mount the `.dmg` and copy the folder named `SDL2.framework` in `/Library/Frameworks`.

Now it is time to create the XCode project. Launch XCode an create a new project. When asked what type of project choose Cocoa Application under the OS X category. Set the name of the project to whatever you want (we will asume the project name is `Poles`) and **uncheck** all the optiones ("Create Document-Based Application", "Use Core Data", "Use Automatic Reference Counting" and "Include Unit Test"). In the next step XCode will ask you were to save the projet folder. The location isn't relevant but make sure to uncheck the option to create a local git repository since we will clone ours from GitHub.

We have our project created and the next step is to add and configure our libraries. To do so open the project details view (click in the project icon, the uppermost element in the project navigator in the left sidebar). In the Summary tab locate the section named "Linked Frameworks and Libraries" and clic the plus icon. In the new dialog use the search box to find the OpenGL framework (OpenGL is natively included in XCode) and clic "Add". Now open the dialog again but this time clic "Add Other..." and add the folders of the libraries we copied to `/Library/Frameworks` at the beginning, one by one.

The next steps will be to tell XCode where the framwork's header files are located, so go to the "Build Settings" tab and search for the option "Header Search Paths". Edit it and add the path to the folder `Headers` of all the SDL Frameworks (ie. `/Library/Frameworks/SDL2.framework/Headers`). Search the option "Framework Search Paths" and modify it addind the following line: `/Library/Frameworks`.

Now we need to tell XCode to copy those libraries to our destination App in order to make de application execute even if the user does not have the SDL Frameworks installed in his system. Open the Build Phases tab and add a new build phase with the "Add Build Phase" button, selecting the option "Add Copy Files". Change the "Destination" dropdown value to "Frameworks" and use the plus icon to add the SDL Frameworks we copied in `/Library/Frameworks` (ie. `/Library/Frameworks/SDL2.framework`).

Before cloning the repository we need to make some cleaning work on the project. In the project navigator you can see there is a number of new yellow icons representing the frameworks we added (they appear twice, it's normal), so we will select and move them to the folder "Frameworks". Now we need to delete some unnecesary files XCode created with our project. Delete all files outside the "Supporting Files" folder (choose "Move to Trash" when asked how to delete them).

This is the last step and involves cloning the repository into our project. The source code must bo cloned into `Poles/Poles` so we need to change our working directory to `Poles`. If we take a look at the files in that directory we will see the following:

* Poles
* Poles.xcodeproj

If we try to clone our project Git won't do it beacuse the folder `Poles` isn't empty. We need to move the files inside it to somewhere else, clone the repository and move them back again. When we clone the repository we will use the existing `Poles` folder wich have the same name as the folder Git will create for the cloned repository. Once we have cloned our repository move back the files we get out of the folder before (don't worry, they are already ignored in the .gitignore).

Your project is configured and ready to compile Poles. Enjoy!

### Linux

Work in progress...