#include "Triangle.h"
//#include "Shaders.h"
#include <iostream>

using std::cout;
using std::endl;

Triangle::Triangle() {
	cout << "Creating Triangle(def)..." << endl;
	CreateVBO();
	CreateShaders();
	DestroyShaders();
	//DestroyVBO();
	//PrepareObjects();
	//BufferData();
	//LoadShaders();
	//CreateProgram();
	//UnloadShaders();
	//SetTextureSettings();
	cout << "Triangle(def) Successfully Created!" << endl;
}
Triangle::Triangle(Vector3 *coord1_, Vector3 *coord2_, Vector3 *coord3_) {
	cout << "Creating Triangle(cust)..." << endl;
	coord1 = coord1_;
	coord2 = coord2_;
	coord3 = coord3_;
	//PrepareObjects();
	//BufferData();
	//LoadShaders();
	//CreateProgram();
	//UnloadShaders();
	//SetTextureSettings();
	cout << "Triangle(cust) Successfully Created!" << endl;
}
void Triangle::CreateVBO() {
	GLfloat Vertices[] = {
		-0.8f, -0.8f, 0.0f, 1.0f,
		0.0f,  0.8f, 0.0f, 1.0f,
		0.8f, -0.8f, 0.0f, 1.0f
	};

	GLfloat Colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f
	};

	GLenum ErrorCheckValue = glGetError();

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}
void Triangle::DestroyVBO() {
	GLenum ErrorCheckValue = glGetError();

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &colorBuffer);
	glDeleteBuffers(1, &VAO);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);
}
void Triangle::CreateShaders() {
	GLenum ErrorCheckValue = glGetError();

	shaderProgram = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &VertexShader, NULL);
	glCompileShader(vertexShaderId);

	shaderProgram = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &FragmentShader, NULL);
	glCompileShader(fragmentShaderId);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShaderId);
	glAttachShader(shaderProgram, fragmentShaderId);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
}
void Triangle::DestroyShaders() {
	GLenum ErrorCheckValue = glGetError();

	glUseProgram(0);

	glDetachShader(shaderProgram, vertexShaderId);
	glDetachShader(shaderProgram, fragmentShaderId);

	glDeleteShader(fragmentShaderId);
	glDeleteShader(vertexShaderId);

	glDeleteProgram(shaderProgram);
}
/*
void Triangle::PrepareObjects() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(Target, VBO);
	cout << "(Triangle) Objects Prepared..." << endl;
}*/
void Triangle::BufferData() {
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	cout << "(Triangle) Data Buffered..." << endl;
}
/*
void Triangle::LoadShaders() {
	cout << "(Triangle) Compiling Shaders..." << endl;
	vertexShader   = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexShader,   1, &vertexShaderSource,   NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	cout << "(Triangle) Successfully Compiled Shaders..." << endl;
}
void Triangle::CreateProgram() {
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	cout << "(Triangle) Successfully Created Triangle Program..." << endl;
}
void Triangle::UnloadShaders() {
	glDeleteShader(vertexShader);
	cout << "(Triangle) Unloaded Vertex Shader..." << endl;
	glDeleteShader(fragmentShader);
	cout << "(Triangle) Unloaded Fragment Shader..." << endl;
}
void Triangle::SetTextureSettings() {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
*/
void Triangle::BeginProgram() {
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	cout << "(Triangle) Began Triangles Program" << endl;
}
void Triangle::Draw() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
	cout << "(Triangle) Drawing Arrays from Triangles Class" << endl;
}