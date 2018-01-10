#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Triangle.h"
#include "Shaders.h"
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

#pragma endregion

	/// Instantiation
	Vector3 *k1 = new Vector3(-0.8f, 0.8f, 0.0f);
	Vector3 *k3 = new Vector3(-0.8f, 0.0f, 0.0f);
	Vector3 *k2 = new Vector3( 0.5f, 0.5f, 0.0f);
	
	Triangle myTriangle(*k1, *k2, *k3);
	RegularPolygon firstPolygon(0.25f, 0.25f, 0.0f, 0.2f, 40);
	RegularPolygon secondPolygon(-0.3f, -0.25f, 0.0f, 0.35f, 8);
	secondPolygon.ColorChange(0.5f, 0.0f, 0.9f); // debugging for color change
	
	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		/// inputs
		/// ------
		processInput(window);

		int count;
		int buttonCount;
		int pointNumber = 3;
		const unsigned char *buttonAxes = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
		const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);
		if (buttonAxes[0] == GLFW_PRESS)
			pointNumber = 1;
		if (buttonAxes[1] == GLFW_PRESS)
			pointNumber = 2;
		if (buttonAxes[2] == GLFW_PRESS)
			pointNumber = 0;
		
		/// rendering commands
		/// ------------------
		glClearColor(0.08f, 0.04f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myTriangle.Draw();
		firstPolygon.Draw();
		secondPolygon.Draw();

		if (pointNumber != 3) {
			myTriangle.Vertices[(pointNumber * 3)] += (axes[0] * 0.01);
			myTriangle.Vertices[(pointNumber * 3) + 1] += (axes[1] * 0.01);
			RegularPolygon selectionPoint(myTriangle.Vertices[(pointNumber * 3)], myTriangle.Vertices[(pointNumber * 3) + 1], 0.0f, 0.01f, 8);
			selectionPoint.Draw();
		}

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

	/// Xbox controller Layout
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