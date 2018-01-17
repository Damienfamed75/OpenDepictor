# Instructions
_____________

[//]: # (Picture instantiation)

[windows10logo]:https://www.accessfirefox.org/images/index_page/Windows-10-logo-larger.png "Windows 10 Logo"

[linuxmintlogo]:https://winaero.com/blog/wp-content/uploads/2015/06/cinnamon-linux-mint-logo-icon.png "Linux Mint Logo"

[propertiesdropdown]: https://i.imgur.com/eDqdH3M.jpg "properties drop down menu"

#### Overview
- [Installing GCC/G++](#GCCInstall)
- [Installing GLFW 3.3](#GLFWInstall)
- [Installing GLAD](#GLADInstall)
- [Setting up your Development Environment](#DevEnvSetup)
_________________
##### Disclaimer
_These instructions were only tested for Linux Mint Cinnamon and Windows 10
If you are having troubles getting these files to work in your own instance.
You can contact me at: <damienstamates@gmail.com>_

![linux logo][linuxmintlogo] ![windows logo][windows10logo]

_________________

### Installing GCC/G++ <a name="GCCInstall"></a>

> *GCC/G++ is what we're going to be compiling our code in*
> *Which is the "GNU Compiler Collection" is produced by*
> *GNU Project which supports many programming languages.*
> *This compiler is made for Unix use, but we're going to*
> *be using this on both systems.*


<h4>Linux Mint</h4>


Installing GCC/G++ on Linux couldn't be any easier.
All you need to do is do a quick update with:

`sudo apt-get update`

and then download the package for GCC/G++

`sudo apt-get install g++`

When this is installed you can move on to [installing GLFW.](#GLFWInstall)

<h4>Windows 10</h4>


Installing GCC/G++ is going to require you do to do a little bit more work
in Windows. If you're going to be using *Visual Studio* *(not include Visual Studio Code)* then you can skip this step.
1. First you're going to want to pick a folder where you
want to install *G++*. It's recommended you put this straight into your
`C:` drive, but you can choose a different one if you wish.
2. Now you'll want to download [this executable.](fhttp://www1.cmc.edu/pages/faculty/alee/g++/full.exe) 
*This download was provided by [Arthur H. Lee](http://www1.cmc.edu/pages/faculty/alee/) for his Computer Science students.*
3. Place the executable *full.exe* to `C:\full.exe` by using the **Save Link As...** or **Save Target As...**
4. Now run the executable. This will install *G++* *"and a lot of other things that you don't really need"* on your hard drive.
5. Locate where the `bin` folder was created from the installation.
This location should be somewhere like: `C:\cygnus\cygwin-b20\H-i586-cygwin32\bin`
6. Now you should add this to the `Path` environment variable. You get here by doing the following 
`Start -> Control Panel -> System and Security -> System -> Change Settings -> Advanced -> Environment Variables`
Now here you can see the `Path` variable. This could be a User variable, System variable, or both. What you need to do is add the *G++* `bin` path in the `Path` variables *`(If you have it in both System and User then add it to System)`* by clicking the `Edit...` button and then clicking `New`.
**Make sure you do not delete any other values.**
7. Restart your computer. When your computer is restarted you should see a `Cygwin B20` or other `Cygwin Solutions` entry in your Start menu. **Don't use them!**
8. Now you should be able to use the `g++` command froma DOS command prompt window. For example if I want to compile a simple program at `C:\MyAppDirectory\HelloWorld.cpp` then I use the `cd` command to connect to the `C:\MyAppDirectory\` folder and enter:
`g++ -g HelloWorld.cpp -o HelloWorld -lm` then you should be able to run the application through command prompt.
9. Now you can delete the `full.exe` file you saved from earlier and now *GCC/G++* is installed! Now you can move on to [installing GLFW.](#GLFWInstall)

__________________
### Installing GLFW <a name="GLFWInstall"></a>

> *[GLFW or "Graphics Library Framework"](http://www.glfw.org/) is a utility library*
> *for the use with OpenGL. We're using this library because it*
> *handles simple things like joystick and keyboard inputs for us.*


<h4>Linux Mint</h4>


On Linux we have to manually compile the library framework ourselves
So first off we're going to need the source code of GLFW and clone it.

1. [Clone the GLFW repository.](https://github.com/glfw/glfw)
2. Luckily GLFW is quite easy to compile. All we need to do is quickly install *CMake*. Quickly just run this command to install *CMake*
`sudo apt-get install cmake`
This should quickly run and install *CMake* for you.
3. Now locate where you cloned the repository and direct your terminal to the root folder. Now what you'll want to do is run these commands.
`cmake .`
`make`
`make install`
These commands should install the library to `usr/local/include`

4. Now that we have GLFW let's [install GLAD.](#GLADInstall)

<h4>Windows 10</h4>


On Windows installing GLFW is quite easy. All it takes is downloading GLFW's pre-compiled
binaries and linking your flavor of text-editor to it.

1. First off we're going to just download the binaries from [their download page.](http://www.glfw.org/download.html)
Don't download the 64-bit binaries unless *you know that you NEED them!*
You can download these anywhere you'd like. Just make sure you know
where you downloaded them to.
2. Now you should have a zipped folder and you just need to extract it quickly.
3. Once it's extracted you can go inside and see multiple folders such as 
`include` and `lib-vc2012` what you're going to be doing is using the 
`lib-vc2015` folder for linking your libraries even if you have a newer
version of Visual Studio *(Or Visual Studio Code)*.
4. Now that you have GLFW installed you won't have to do anything with these
files until you begin setting up your environment. Next step is to [download GLAD.](#GLADInstall)

__________________
### Installing GLAD <a name="GLADInstall"></a>

> *Glad is a GL/GLES/EGL/GLX/WGL Loader-Generator for*
> *GLFW. This make it easy to create cross-platform*
> *code without having to deal with input drivers.*

<h4>Linux Mint</h4>


Setting up *GLAD* is going to be very similar to setting up GLFW. We just need to
clone the official repository and compile it for ourselves using CMake.

1. [Clone the repository.](https://github.com/Dav1dde/glad)
2. Locate the directory and direct your terminal to the root folder.
3. Run these commands
`cmake .`
`make`
`make install`
4. And you're finished! Now you should have GLAD in the same directory as GLFW.
Which should be `usr/local/include` You're now ready to [setup your Development Environment.](#DevEnvSetup)

<h4>Windows 10</h4>


Downloading GLAD is quite easy on Windows. It's just going to require you to
go through their easy web service.

1. [Go to their web service.](http://glad.dav1d.de/)
2. For 'language' choose "C/C++"
3. 'Specification' choose "OpenGL"
4. API you want to change 'gl' to "Version 3.3" and leave the rest empty.
5. For the 'Profile' you want to choose "Core"
6. Now at the bottom of the page just click "Generate" and you should
be visited by a page that should list three things.
`include`
`src`
`glad.zip`
What you're going to want to do is click `glad.zip` and save it somewhere
you won't forget.
7. Now extract the zipped folder like you did for GLFW and you're now ready
to [setup your Development Environment.](#DevEnvSetup)

_____________
### Setting up Development Environment <a name="DevEnvSetup"></a>

> *This part of the instructions isn't meant for every*
> *occassion or situation. This is only made for a few*
> *cases if you need help with these specific things.*
> *This isn't going to cover setting up intellisense for VSCode.*


<h4>GCC/G++ Commands</h4>

Using GCC/G++ can be tricky sometimes when working in this environment.
If CMake isn't working properly or it's outdated you'll have to resort to using
GCC/G++ for compiling your code.

Compiling this project is going to require you to link GLAD, GLFW, and all cpp files.
For example we need to keep it in this very specific order.
`g++ <glad.c directory> Source.cpp <the rest of the cpp files> -std=c++11 -AllOtherLibraries`

When you downloaded GLAD you either got a zipped folder (on Windows) or the official repository.
Whatever you have go to that folder and locate the `src` folder. In there should be a file nammed `glad.c`
You want to have the directory to this file and place it before everything in your g++ command.

With `-AllOtherLibraries` this might depend on what Operating system you're running on.
You're going to have to play around with the commands and see what works and what doesn't.
Feel free to mix and match, but I'm going to sort them out by Operating System and you can see
what works and what doesn't for your needs.

**Linux**
`-lglfw or -lglfw3`
`-lGL`
`-lX11`
`-lpthread`
`-lXrandr`
`-lXi`
`-lbl`
**Windows**
`-I<path to headers>`
`-L<path to libraries>`
`-lopengl32`
`-lglfw3 or -lglfw`
`-lglad`
`-lkernel32`
`-luser32`
`-lgdi32`
`-lws3_32`

<h4>Using CMake</h4>

We use CMake primarily when building versions of this application now,
because it's easier to manage and type out than long and teadious
GCC/G++ commands.

To this project built you first go into terminal and direct it to
the build folder within the root of the project.

Next you want to type in `rm -rf ./*` which will delete all the files
within the folder.

Then you'll type in `cmake ..` which tells cmake to place all the CMake files
in your current folder, but it's building the parent folder.

Now type in `make` which will compile the project and once it's done type in
`./IdolScheme` which will run the application.

<h4>Linking Visual Studio</h4>

This does not include Visual Studio Code. What this section will do
is link *GLAD* and *GLFW* to Visual Studio. Luckily it's quite easy
and simple to do.

1. First start off by creating your project and making at least a source file
for example put this
```cpp
#ifdef _WIN32
    #define APIENTRY __stdcall // this is optional and NOT required.
#endif

#include <glad/glad.h> // make sure to place glad before iostream

#ifdef _WINDOWS_
    #error windows.h was included! // confirm that glad didn't include windows.h
#endif

#include <GLFW/glfw3.h>
#include <iostream>

// function prototypes.
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

// declaring the window dimensions.
const GLuint SCR_WIDTH = 800, SCR_HEIGHT = 600;

int main() {
    glfwInit(); // initializes the library

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // creates a GLFWwindow object that we can use for GLFW functions.
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Test Window", NULL, NULL);
    glfwMakeContextCurrent(window);
    if(window == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // kset required callback functions.
    glfwSetKeyCallback(window, key_callback);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    // defines the viewport dimensions.
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    // render loop
    while(!glfwWindowShouldClose(window)) {
        // check if any events have been activated(key presses, mouse move etc.)
        glfwPollEvents();

        // Render
        // clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap the screen buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

// is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    std::cout << key << std::endl;
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
```

2. Go to the project properties via the dropdown menu located at the top of the screen.
![dropdown menu][propertiesdropdown]
3. In this menu go to `VC++ Directories` and edit the `Include Directories`
4. In here you want to add the directories to GLFW and GLAD's include folders.
5. Next you want to edit the `Library Directories` and add GLFW's `lib-vc2015` folder.
6. Next open the `Linker` tab on the left side of the window and select `Input`
7. Now here you'll want to edit the `Additional Dependencies` and add these libraries.
`glfw3.lib`
`opengl32.lib`
8. Now you want to go to your GLAD folder and open the `src` folder. In here you should find a file named `glad.c` Drag and drop this into your project Solution Explorer.
9. Now Visual Studio should be all setup and now your code should be able to compile by just hitting `F5`


<h4>Additional Resources</h4>

- [GLFW: Window guide](http://www.glfw.org/docs/latest/window_guide.html): The official guide on setting up a GLFW window.
- [Building C/C++ applications](http://www.opengl-tutorial.org/miscellaneous/building-your-own-c-application/): An in depth guide on the compiling/linking process of your application.
- [Installing CMake](https://cmake.org/install/): Official guide on how to install CMake.
- [Running CMake](https://cmake.org/runningcmake): And official overview on how to use CMake.
- [Wonderful OpenGL 3.3 Tutorial](https://learnopengl.com/#!Introduction): A great tutorial on learning the basics of OpenGL 3.3
- [Writing a Build System on Linux](http://learnopengl.com/demo/autotools_tutorial.txt): An autotools guide on how to write a build system on Linux.
- [Official GLFW Repo](https://github.com/glfw/glfw): The official GLFW Github Repository.
- [Official Glad Repo](http://github.com/Dav1dde/glad): The official Glad Github Repository.
- [Building OpenGL/GLFW Apps](web.eecs.umich.edu/~sugih/courses/eecs487/glfw-howto/): An in-depth guide to building OpenGL/GLFW apps in Linux/Mac/Windows/Cygwin.
