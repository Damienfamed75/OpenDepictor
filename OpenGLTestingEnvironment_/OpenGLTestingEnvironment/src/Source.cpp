#include "../include/Source.h"

#include "../include/Texture.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;
const GLint JOY_SENSITIVITY = 12;
const GLfloat JOY_MODIFIER = 0.001f;
Conductor mainConductor;
double deltaTime;


// TODO - ADD TEXT
// https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Text_Rendering_01
// https://www.freetype.org/download.html

// TODO - ADD BEATMAP LANGUAGE
// Making lua scripts or txt files to create beatmaps

int main(int argc, char** argv) {
	if (argc < 4) {
		std::cout << "Not enough arguments supplied.";
		return IdolScheme_ErrorCodes::NOT_ENOUGH_ARGS_ERROR;
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
	/// ------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

#pragma endregion

#pragma region INSTANTIATIONS
	/// Instantiation
	/// -------------
	RenderingObjects<RegularPolygon> objects = RenderingObjects<RegularPolygon>(); // This should be something more versatile.
	Note myNote(window, -.3f, 0.f, 0.f, 0.f, 1.1, GLFW_KEY_Y, XBOX::BUTTON_Y);
	
	//std::cout << ResourceManager::GetTexture("testimg").height << std::endl;
	double currentFrame = glfwGetTime();
	double lastFrame = currentFrame;

	int bpm = std::stoi(argv[1]);
	double lengthInS = std::stod(argv[2], NULL);
	int offsetInMs = std::stoi(argv[3]);
	
	mainConductor = Conductor(bpm, lengthInS, offsetInMs);
	mainConductor.startTimer();
	
	objects.Add(myNote);

	//////////////////////////////////////////////////////
	////// CONSTRUCTION ZONE
	//////////////////////////////////////////////////////

	char buff[FILENAME_MAX];
	GetCurrentDir( buff, FILENAME_MAX );
	std::string current_working_dir(buff);
	std::cout << current_working_dir << std::endl;



	Shader myShader("../shaders/sprite.vs","../shaders/sprite.frag");
		// "/code/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/sprite.frag");
	float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
		 0.0f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f
    
	};
	
	float testvertices[] = {
		0.5f, 0.5f, 0.f,  1.f, 0.f, 0.f,
		0.5f, -0.5f, 0.f, 0.f, 1.f, 0.f,
	   -0.5f, -0.5f, 0.f, 0.f, 0.f, 1.f,
	   -0.5f, 0.5f, 0.f,  1.f, 1.f, 0.f
	};
	
	float texCoords[] = {
		1.f, 1.f,
		1.f, 0.f,
		0.f, 0.f,
		0.f, 1.f
	};
	unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
	unsigned int VBO, VAO, EBO, TBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
	//glGenBuffers(1, &TBO);
	
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_TEXTURE_BUFFER, TBO);
	//glBufferData(GL_TEXTURE_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW); // It works but I don't know why

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(2);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

	unsigned int ID;

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	//stbi_set_flip_vertically_on_load(true);

	unsigned char *data = stbi_load("../textures/testimg.png", &width, &height, &nrChannels, 0);
	if(data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);


	//Texture texture("../textures/wall.jpg");

	//////////////////////////////////////////////////////
	////// CONSTRUCTION ZONE
	//////////////////////////////////////////////////////

#pragma endregion


	/// Render Loop
	/* Keeps glfw running and refreshing until the window
	 * is told to stop explicitly by the user or other means.
	 */
	while (!glfwWindowShouldClose(window)) {
		
		/// inputs (button presses, mouse movements, etc.)
		/// ----------------------------------------------
		processInput(window);

		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		/// rendering commands (drawing new shapes and such)
		/// ------------------------------------------------
		glClearColor(0.08f, 0.04f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//! Must be before Note Update
		mainConductor.refreshMembers();
		
		myNote.Update(); //NOTE OBJECT IS CAUSING LEAKAGE WHEN USING NEW SHADER OBJ
		
		myShader.use();
		
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, 0);
		for (unsigned int i = 0; i < objects.GetSize(); i++)
			objects.DrawShape(i);

		
		//glDeleteVertexArrays(1, &VAO);
   	 	//glDeleteBuffers(1, &VBO);
  	  	//glDeleteBuffers(1, &EBO);
		
		/// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		/// -------------------------------------------------------------------------------
		mainConductor.beatSinceRefresh = mainConductor.currBeat;
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
