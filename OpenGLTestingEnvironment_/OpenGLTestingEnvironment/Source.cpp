#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Triangle.h"
#include "Shaders.h"
#include "BoolArray.h"

float GetVal(float *v, float j, bool *t);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
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
	glfwMakeContextCurrent(window);
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

	/// Triangle
	Color cl1 = Color(1.0f, 0.0f, 0.0f, 1.0f);
	Color cl2 = Color(0.0f, 1.0f, 0.0f, 1.0f);
	Color cl3 = Color(0.0f, 0.0f, 1.0f, 1.0f);
	Vector3 c1 =  Vector3(-1.0f, 0.0f, 0.0f);
	Vector3 c2 =  Vector3(-0.5f, 1.0f, 0.0f);
	Vector3 c3 =  Vector3(0.0f, 0.0f, 0.0f);
	BoolArray blArr = BoolArray();
	Triangle *firstTriangle = new Triangle();
	
	float j = 0.004f;
	float animSpeed = 0.004f;
	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		/// inputs
		/// ------
		processInput(window);
		
		/// rendering commands here
		firstTriangle->CreateShaders();
		firstTriangle->CreateVBO();
		glClearColor(0.3f, 0.2f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		firstTriangle->CleanUp();

		// animation testing
		
		firstTriangle->UpdatePos(
			Vector3(GetVal(&c1.x, animSpeed, &blArr.a1), GetVal(&c1.y, animSpeed, &blArr.a2), c1.z),
			Vector3(GetVal(&c2.x, animSpeed, &blArr.a3), GetVal(&c2.y, animSpeed, &blArr.a4), c2.z),
			Vector3(GetVal(&c3.x, animSpeed, &blArr.a5), GetVal(&c3.y, animSpeed, &blArr.a6), c3.z)
		);
		/*
		// color animation testing
		firstTriangle->UpdateColor(
			Color(GetVal(&cl1.r, j, &blArr.a1),GetVal(&cl1.g, j, &blArr.a2),GetVal(&cl1.b, j, &blArr.a3), cl1.a),
			Color(GetVal(&cl2.r, j, &blArr.a4), GetVal(&cl2.g, j, &blArr.a5), GetVal(&cl2.b, j, &blArr.a6), cl2.a),
			Color(GetVal(&cl3.r, j, &blArr.a7), GetVal(&cl3.g, j, &blArr.a8), GetVal(&cl3.b, j, &blArr.a9), cl3.a)
		);
		//*/
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


int IsNeg(float *v_) {
	if (*v_ < -1.0)
		return 1;
	else if (*v_ > 1)
		return 0;
	return 2;
}
float GetVal(float *v, float j, bool *t) {
	
	if (*t == true) {
		*v += j;
	} else if (*t == false) {
		*v -= j;
	}
	
	if (IsNeg(v) == 0) {
		*t = false;
	} else if (IsNeg(v) == 1) {
		*t = true;
	}

	return *v;
}