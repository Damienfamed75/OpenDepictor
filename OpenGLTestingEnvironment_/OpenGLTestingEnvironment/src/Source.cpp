#ifdef _WIN32
	#define APIENTRY __stdcall
#endif //!_WIN32

#ifndef __glad_h_
	#include <glad/glad.h>
#endif //!__glad_h_

#ifdef _WINDOWS_
	#error windows.h was included!
#endif //!_WINDOWS_

#ifndef _glfw3_h_
	#include <GLFW/glfw3.h>
#endif //!_glfw3_h_

#ifndef TRIANGLE_H
	#include "../include/Triangle.h"
#endif //!TRIANGLE_H

#ifndef SHADERS_H
	#include "../include/VariableObjects/Shaders.h"
#endif //!SHADERS_H

#ifndef REGULARPOLYGON_H
	#include "../include/RegularPolygon.h"
#endif //!REGULARPOLYGON_H

#ifdef _WIN32
	#ifndef _IOSTREAM_
		#include <iostream>
	#endif //!_IOSTREAM_
#else // !_WIN32
	#ifndef _GLIBCXX_IOSTREAM
		#include <iostream>
	#endif //!_GLIBCXX_IOSTREAM
#endif //!_WIN32

#ifndef _VECTOR_
	#include <vector>
#endif //!_VECTOR_

#ifndef NOTE_H
	#include "../include/Note.h"
#endif //!NOTE_H

#ifndef DEBUGVERTEXCONTROLLER_H
	#include "../include/DebugVertexController.h"
#endif //!DEBUGVERTEXCONTROLLER_H

#ifndef RENDERINGOBJECTS_HPP
	#include "../include/VariableObjects/RenderingObjects.hpp"
#endif //!RENDERINGOBJECTS_HPP

#ifndef CONTROLS_H
	#include "../include/VariableObjects/Controls.h"
#endif //!CONTROLS_H

#ifndef DEBUGVERTEXCONTROLLER_H
	#include "../include/DebugVertexController.h"
#endif //!DEBUGVERTEXCONTROLLER_H

#ifndef CONDUCTOR_H
	#include "../include/Conductor.h"
#endif

#ifdef _WIN32
	#ifndef _STRING_
		#include <string>
	#endif //!_STRING_
#endif //!_WIN32

#define NOT_ENOUGH_ARGS_ERROR 1
#define DEBUG
#define TAU (M_PI * 2.0)


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;
const GLint JOY_SENSITIVITY = 12;
const GLfloat JOY_MODIFIER = 0.001f;
int keyPrevState = GLFW_RELEASE;
int keyCurrentState;


// TODO - ADD TEXT
// https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Text_Rendering_01
// https://www.freetype.org/download.html


int main(int argc, char** argv) {
	if (argc < 4) {
		std::cout << "Not enough arguments supplied.";
		return NOT_ENOUGH_ARGS_ERROR;
	}
#pragma region GLFW_INITIALIZATION
	// glfw: initialize and configure
	// ------------------------------
	glfwInit(); // initializes the library
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this to fix compilation on OS X
#endif


	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Testing Environment", NULL, NULL); // Creates window object
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // makes the window's context current
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	/// Glad Initilization
	/* passing GLAD the function to load the address of the
	* OpenGL function pointers which is OS-specific. GLFW
	* gives us "glfwGetProcAddress" that defines the correct
	* function based on which OS we're compiling for.
	*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	

#pragma endregion

#pragma region INSTANTIATIONS
	/// Instantiation
#ifdef DEBUG	
	double currentFrame = glfwGetTime();
	double lastFrame = currentFrame;
	double deltaTime;
	double startFrame = currentFrame;

	double a = 0;
	double speed = 2.5;
#endif //!DEBUG
	//! TODO make lists able to carry multiple types of objects.
	//RenderingObjects<RegularPolygon> *polygons = new RenderingObjects<RegularPolygon>();
	RenderingObjects<RegularPolygon> objects = RenderingObjects<RegularPolygon>();
	
	//Note myNote(window, 0.5f, 0.3f, -0.3f, -0.2f, 1.5, GLFW_KEY_Y, XBOX::BUTTON_Y);
	Note myNote(window, -.3f, 0.f, 0.f, 0.f, 1.1, GLFW_KEY_Y, XBOX::BUTTON_Y);

	int bpm = std::stoi(argv[1]);
	double lengthInS = std::stod(argv[2], NULL);
	int offsetInMs = std::stoi(argv[3]);
	Conductor mainConductor(bpm, lengthInS, offsetInMs);
	mainConductor.startTimer();	
	
	objects.Add(myNote);

#pragma endregion


	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		
		/// inputs (button presses, mouse movements, etc.)
		/// ----------------------------------------------
		processInput(window);
#ifdef DEBUG
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		a += deltaTime * speed;
		if (a > TAU) a -= TAU;

		//myNote.x = cos(a) * 0.8f;
		myNote.Setup();
#endif //!DEBUG
		/// rendering commands (drawing new shapes and such)
		/// ------------------------------------------------
		glClearColor(0.08f, 0.04f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myNote.Update();
		for (unsigned int i = 0; i < objects.GetSize(); i++) {
			objects.DrawShape(i);
		}


		/// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		/// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

	    	std::cout << "\n\nStart time: " << std::chrono::system_clock::to_time_t((std::chrono::system_clock::time_point&)mainConductor.startTime);
	    	mainConductor.refreshMembers();
	    	std::cout << "\nCurr time: " << std::chrono::system_clock::to_time_t((std::chrono::system_clock::time_point&)mainConductor.currTime);
	    	std::cout << "\nCurr beat: " << mainConductor.currBeat;
		std::cout << "\nBeats since last refresh: " << mainConductor.numBeatsSinceRefresh;
		myNote.MoveByBeats(window, mainConductor.numBeatsSinceRefresh); 
		mainConductor.beatSinceRefresh = mainConductor.currBeat;
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif //!_WIN32
		

	}

	glfwTerminate(); // Properly cleans and deletes all resources that were allocated.
	return 0;
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
