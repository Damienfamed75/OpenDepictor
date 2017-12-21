#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Triangle.h"
#include "Shaders.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices[] = {
	-1.0f, 0.0f, 0.0f,
	 1.0f, 0.0f, 0.0f,
	 0.0f,  1.0f, 0.0f
}; // triangle vertices
float othervert[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 0.0f, 0.0f
};
/*
float newvert[] = {
	-0.5f, -0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f
};
const char *vertexShaderSource = 	"#version 330 core\n"
									"layout (location = 0) in vec3 aPos;\n"
									"void main()\n"
									"{\n"
									"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
									"}\0";

const char *fragmentShaderSource =	"#version 330 core\n"
									"out vec4 FragColor;\n"
									"void main()\n"
									"{\n"
									"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
									"}\n\0";
*/

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
	Vector3 c1 = Vector3(-1.0f, 0.0f, 0.0f);
	Vector3 c2 = Vector3(-0.5f, 1.0f, 0.0f);
	Vector3 c3 = Vector3(0.0f, 0.0f, 0.0f);
	/*Triangle *firstTriangle = new Triangle(
		Vector3(-1.0f, 0.0f, 0.0f),
		Vector3(-0.5f, 1.0f, 0.0f),
		Vector3( 0.0f, 0.0f, 0.0f)
	);*/
	Triangle *firstTriangle = new Triangle(c1, c2, c3);

	/*
	unsigned int VBO; // Vertex Buffer Object
	unsigned int VAO; // Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(othervert), othervert, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(othervert), othervert, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);*/
	
	float j = 0.005f;
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

		// animation testing
		firstTriangle->UpdatePos(
			Vector3(c1.x += j, c1.y += j, c1.z += j),
			Vector3(c2.x -= j, c2.y -= j, c2.z -= j),
			Vector3(c3.x += j, c3.y += j, c3.z += j)
		);

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