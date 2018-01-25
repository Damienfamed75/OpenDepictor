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

#ifndef _GLIBCXX_IOSTREAM
	#include <iostream>
#endif //!_GLIBCXX_IOSTREAM

#include "../include/DebugVertexController.h"
/*
#ifndef CONDUCTOR_CPP
#include "Conductor.cpp"
#define CONDUCTOR_CPP
#endif
*/
#define DEBUG

#define NOT_ENOUGH_ARGS_ERROR 1

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;
const GLint JOY_SENSITIVITY = 12;
const GLfloat JOY_MODIFIER = 0.001f;


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
	Vector3 *k1 = new Vector3(-0.8f, 0.8f, 0.0f);
	Vector3 *k3 = new Vector3(-0.8f, 0.0f, 0.0f);
	Vector3 *k2 = new Vector3( 0.5f, 0.5f, 0.0f);
	
	Triangle myTriangle(*k1, *k2, *k3);
	RegularPolygon firstPolygon(0.25f, 0.25f, 0.0f, 0.2f, 40);
	RegularPolygon secondPolygon(-0.3f, -0.25f, 0.0f, 0.35f, 8);
	RegularPolygon thirdPolygon(0.7f, -0.4f, 0.0f, 0.2f, 4);
	RegularPolygon selector(0.0f, 0.0f, 0.0f, 0.01f, 8);

	secondPolygon.UpdateColor(0.5f, 0.0f, 0.9f);
	firstPolygon.UpdateColor(0.9f, 0.0f, 0.2f);
	thirdPolygon.UpdateColor(0.3f, 0.8f, 0.1f);

	int bpm = std::stoi(argv[1]);
	double lengthInS = std::stod(argv[2], NULL);
	int offsetInMs = std::stoi(argv[3]);
	Conductor mainConductor(bpm, lengthInS, offsetInMs);

	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		
		/// inputs (button presses, mouse movements, etc.)
		/// ----------------------------------------------
		processInput(window);

		/// rendering commands (drawing new shapes and such)
		/// ------------------------------------------------
		glClearColor(0.08f, 0.04f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myTriangle.Draw();

		DebugVertexController::controlTriangle(window, &myTriangle, &selector, GLFW_JOYSTICK_1);

		firstPolygon.Draw();
		secondPolygon.Draw();
		thirdPolygon.Draw();

		/// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		/// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

	    	cout << "\n\nStart time: " << std::chrono::system_clock::to_time_t(mainConductor.startTime);
	    	mainConductor.refreshMembers();
	    	cout << "\nCurr time: " << std::chrono::system_clock::to_time_t(mainConductor.currTime);
	    	cout << "\nCurr beat: " << mainConductor.calcCurrentBeat(); 

	}

	glfwTerminate(); // Properly cleans and deletes all resources that were allocated.
	return 0;
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	/// Input testing
	/// -------------

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
