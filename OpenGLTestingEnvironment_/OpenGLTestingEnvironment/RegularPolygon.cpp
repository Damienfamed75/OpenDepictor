#include "RegularPolygon.h"
#include <iostream>

using std::cout;
using std::endl;

RegularPolygon::RegularPolygon(GLfloat x_, GLfloat y_, GLfloat z_, GLfloat r_, GLint numOfSides_) {
	x = x_;
	y = y_;
	z = z_;
	r = r_;
	numOfSides = numOfSides_;
	numOfVertices = numOfSides + 2;
	
	polygonVerticesX   = new GLfloat[numOfVertices];
	polygonVerticesY   = new GLfloat[numOfVertices];
	polygonVerticesZ   = new GLfloat[numOfVertices];
	//allPolygonVertices = new GLfloat[(numOfVertices) * 3];

	Setup();
	CreateVBO();
	CreateShaders();
	DestroyShaders();
	DestroyVBO();
	cout << "Circle Successfully Created!" << endl;
}

void RegularPolygon::Setup() {
	polygonVerticesX[0] = x;
	polygonVerticesY[0] = y;
	polygonVerticesZ[0] = z;

	for (int i = 1; i < numOfVertices; i++) {
		polygonVerticesX[i] = x + (r * cos(i * doublePi / numOfSides));
		polygonVerticesY[i] = y + (r * sin(i * doublePi / numOfSides));
		polygonVerticesZ[i] = z;
	}
	for (int i = 0; i < numOfVertices; i++) {
		allPolygonVertices[i * 3]	    = polygonVerticesX[i];
		allPolygonVertices[(i * 3) + 1] = polygonVerticesY[i];
		allPolygonVertices[(i * 3) + 2] = polygonVerticesZ[i];
	}

	cout << "Setup() complete..." << endl;
}

void RegularPolygon::CreateVBO() {
	GLenum ErrorCheckValue = glGetError();
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(allPolygonVertices), allPolygonVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}

void RegularPolygon::DestroyVBO() {
	GLenum ErrorCheckValue = glGetError();
	
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &colorBuffer);
	glDeleteBuffers(1, &VAO);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);
}

void RegularPolygon::CreateShaders() {

	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &VertexShader, NULL);
	glCompileShader(vertexShaderId);

	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &FragmentShader, NULL);
	glCompileShader(fragmentShaderId);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShaderId);
	glAttachShader(shaderProgram, fragmentShaderId);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
}

void RegularPolygon::DestroyShaders() {
	GLenum ErrorCheckValue = glGetError();

	glUseProgram(0);

	glDetachShader(shaderProgram, vertexShaderId);
	glDetachShader(shaderProgram, fragmentShaderId);

	glDeleteShader(fragmentShaderId);
	glDeleteShader(vertexShaderId);

	glDeleteProgram(shaderProgram);
}

void RegularPolygon::CleanUp() {
	DestroyShaders();
	DestroyVBO();
}

void RegularPolygon::ColorTestChange() {
	for (int i = 0; i < 64; i++) {
		Colors[i * 4] = 0.40f;
		Colors[(i * 4) + 1] = 0.32f;
		Colors[(i * 4) + 2] = 0.75f;
	}
}

void RegularPolygon::Draw() {
	CreateShaders();
	CreateVBO();
	glDrawArrays(GL_TRIANGLE_FAN, 0, numOfVertices);
	CleanUp();
}