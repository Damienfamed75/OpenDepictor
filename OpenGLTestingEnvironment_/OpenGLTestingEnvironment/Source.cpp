#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <math.h>
#include "Triangle.h"
#include "Shaders.h"
#include "BoolArray.h"
#include "RegularPolygon.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {

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
	/*
	glViewport(0.0f, 0.0f, SCR_WIDTH, SCR_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCR_WIDTH, 0, SCR_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

#pragma endregion

	/// Triangle
	Vector3 *k1 = new Vector3(-0.8f, 0.8f, 0.0f);
	Vector3 *k3 = new Vector3(-0.8f, 0.0f, 0.0f);
	Vector3 *k2 = new Vector3( 0.5f, 0.5f, 0.0f);
	Triangle *myTriangle = new Triangle(*k1, *k2, *k3);
	RegularPolygon *firstPolygon = new RegularPolygon(0.25f, 0.25f, 0.0f, 0.2f, 40);
	RegularPolygon *secondPolygon = new RegularPolygon(-0.3f, -0.25f, 0.0f, 0.35f, 8);
	secondPolygon->ColorTestChange(); // debugging for color change
	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		/// inputs
		/// ------
		processInput(window);
		
		/// rendering commands
		/// ------------------
		glClearColor(0.08f, 0.04f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myTriangle->Draw();
		firstPolygon->Draw();
		secondPolygon->Draw();
		/// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		/// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
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