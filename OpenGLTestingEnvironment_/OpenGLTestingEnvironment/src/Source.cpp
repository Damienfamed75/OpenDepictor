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

//#ifndef CONTROLLERHANDLER_H
//	#include "../include/ControllerHandler.h"
//#endif //!CONTROLLERHANDLER_H

#define DEBUG


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;
const unsigned int JOY_SENSITIVITY = 12;


// TODO - ADD TEXT
// https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Text_Rendering_01
// https://www.freetype.org/download.html


int main(int argc, char** argv) {

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
	RegularPolygon selectionPoint(0.0f, 0.0f, 0.0f, 0.01f, 8);

	secondPolygon.UpdateColor(0.5f, 0.0f, 0.9f);
	firstPolygon.UpdateColor(0.9f, 0.0f, 0.2f);
	thirdPolygon.UpdateColor(0.3f, 0.8f, 0.1f);

	// deleting pointers
	delete(k1);
	delete(k2);
	delete(k3);

#pragma endregion


	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		
		/// inputs
		/// ------
		processInput(window);
		
		int joyCount, buttonCount, pointNumber = 3;
		
		const unsigned char *buttonAxes = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount); // NULL if controller is unplugged
		const float *joyAxes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &joyCount); // NULL if controller is unplugged
		
		// Make sure to check if the controller is present before checking input axes
		if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GLFW_TRUE) {
			if (buttonAxes[0] == GLFW_PRESS)
				pointNumber = 1;
			if (buttonAxes[1] == GLFW_PRESS)
				pointNumber = 2;
			if (buttonAxes[2] == GLFW_PRESS)
				pointNumber = 0;
		}
		
		


		/// rendering commands (drawing new shapes and such)
		/// ------------------------------------------------
		glClearColor(0.08f, 0.04f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myTriangle.Draw();

		if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GLFW_TRUE) {
			if (pointNumber != 3) {

#ifdef _WIN32
				myTriangle.Vertices[(pointNumber * 3)] += (joyAxes[0] * 0.01f); // adds to joystick's X-axis
				myTriangle.Vertices[(pointNumber * 3) + 1] += (joyAxes[1] * 0.01f); // adds to joystick's Y-axis
#else
				myTriangle.Vertices[(pointNumber * 3)] += 
					((joyAxes[0] > 0.12f ? joyAxes[0] : joyAxes[0] < -0.12f ? joyAxes[0] : 0) * 0.01f);
				myTriangle.Vertices[(pointNumber * 3) + 1] += 
					((joyAxes[1] > 0.12f ? joyAxes[1] : joyAxes[1] < -0.12f ? joyAxes[1] : 0) * -0.01f); // Unix controller's Y-axis is backwards
#endif // Compensation for Unix's lack of a deadzone

				selectionPoint.MoveTo(myTriangle.Vertices[(pointNumber * 3)], myTriangle.Vertices[(pointNumber * 3) + 1], selectionPoint.z);
				selectionPoint.Draw();
			}
		}

		firstPolygon.Draw();
		secondPolygon.Draw();
		thirdPolygon.Draw();

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

	/// Input testing

	/// Xbox controller Layout (Buttons)
	// 0: A			7: Start
	// 1: B			8: LJoyButton	
	// 2: X			9: RJoyButton
	// 3: Y		   10: D-Pad Up
	// 4: LBumper  11: D-Pad Right
	// 5: RBumper  12: D-Pad Down
	// 6: Back	   13: D-Pad Left

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}