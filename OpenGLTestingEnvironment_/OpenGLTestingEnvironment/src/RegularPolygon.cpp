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

#ifndef TAU
	#define TAU (M_PI * 2.0)
#endif //!TAU


using std::cout;
using std::endl;

int MOVE_KEY = GLFW_KEY_K;
int moveKeyPreviousState = GLFW_RELEASE;
int moveKeyCurrentState;

RegularPolygon::RegularPolygon(GLfloat x_, GLfloat y_, GLfloat z_, GLfloat r_, GLint numOfSides_) 
	: x(x_), y(y_), z(z_), r(r_), numOfSides(numOfSides_), numOfVertices(numOfSides + 2) {
	
	currentFrame = glfwGetTime();
	lastFrame = currentFrame;
	startFrame = -999; // find better way to do this.
	
	polygonVerticesX   = new GLfloat[numOfVertices];
	polygonVerticesY   = new GLfloat[numOfVertices];
	polygonVerticesZ   = new GLfloat[numOfVertices];
	allPolygonVertices = new GLfloat[(numOfVertices) * 3];
	Colors			   = new GLfloat[(numOfVertices) * 4];

	for (int i = 0; i < numOfVertices; i++) { // DEFAULT COLOR IS WHITE
		Colors[(i * 4)] = 1.0f;
		Colors[(i * 4) + 1] = 1.0f;
		Colors[(i * 4) + 2] = 1.0f;
		Colors[(i * 4) + 3] = 1.0f;
	}
	
	Setup();
}

void RegularPolygon::Setup() {
	polygonVerticesX[0] = x; // center coord x
	polygonVerticesY[0] = y; // center coord y
	polygonVerticesZ[0] = z; // center coord z

	for (int i = 1; i < numOfVertices; i++) {
		polygonVerticesX[i] = x + (r * cos(i * doublePi / numOfSides));
		polygonVerticesY[i] = y + (r * sin(i * doublePi / numOfSides));
		polygonVerticesZ[i] = z;
	}
	for (int i = 0; i < numOfVertices; i++) {
		allPolygonVertices[i * 3] = polygonVerticesX[i];
		allPolygonVertices[(i * 3) + 1] = polygonVerticesY[i];
		allPolygonVertices[(i * 3) + 2] = polygonVerticesZ[i];
	}
	shader.Compile(VertexShader, FragmentShader);
	shader.Use();
}

void RegularPolygon::CreateVBO() {
	GLenum ErrorCheckValue = glGetError();
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
	glBufferData(GL_ARRAY_BUFFER, 1024, allPolygonVertices, GL_STATIC_DRAW); // It works but I'd like it redone.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 1024, Colors, GL_STATIC_DRAW); // It works but I don't know why
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
/*
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
*/

void RegularPolygon::CleanUp() {
	//DestroyShaders();
	DestroyVBO();
}

void RegularPolygon::UpdateColor(float r, float g, float b, float a) {
	for (int i = 0; i < numOfVertices; i++) {
		Colors[i * 4]	    = r;
		Colors[(i * 4) + 1] = g;
		Colors[(i * 4) + 2] = b;
		Colors[(i * 4) + 3] = a;
	}
}

void RegularPolygon::Draw() {
	//shader.Compile(VertexShader,FragmentShader);
	//shader.Use();
	//CreateShaders();
	CreateVBO();
	glDrawArrays(GL_TRIANGLE_FAN, 0, numOfVertices);
	DestroyVBO();
	//CleanUp();
}

void RegularPolygon::Rotate(float angle) { // TODO FINISH
	for (int i = 1; i < numOfVertices; i++) {
		float xC = allPolygonVertices[i * 3];
		float yC = allPolygonVertices[(i * 3) + 1];
		float a = ((acos(xC)) / r);
		float xA = r * cos(a + angle);
		float yA = r * cos(a + angle);
		float xB = r * (((cos(a)) * (cos(angle))) - ((sin(a)) * (sin(angle))));
		float yB = r * (((sin(a)) * (cos(angle))) + ((cos(a)) * (sin(angle))));
		allPolygonVertices[i * 3] = xB * cos(angle) - yB * sin(angle);
		allPolygonVertices[(i * 3) + 1] = xB * sin(angle) + yB * cos(angle);
		//allPolygonVertices[i * 3] = ((xC * cos(angle)) - (yC * sin(angle)));
		//allPolygonVertices[(i * 3) + 1] = ((xC * sin(angle)) - (yC * cos(angle)));
	}
}

void RegularPolygon::MoveTo(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
	Setup();
}

void RegularPolygon::Move(float x_, float y_, float z_) {
	for (int i = 0; i < numOfVertices; i++) {
		allPolygonVertices[i * 3] += x_;
		allPolygonVertices[(i * 3) + 1] += y_;
		allPolygonVertices[(i * 3) + 2] += z_;
	}
}

void RegularPolygon::Translate(float x_, float y_, float z_, double time) {
	return;
}

///! TODO fix to make more predictable.
void RegularPolygon::TranslateTo(GLFWwindow *window, float x_, float y_, float z_, double time) {
	

	currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	
	int moveKey = glfwGetKey(window, MOVE_KEY);
	moveKeyPreviousState = moveKeyCurrentState;
	moveKeyCurrentState = moveKey;

	if (moveKey == GLFW_PRESS && moveKey != moveKeyPreviousState) {
		startFrame = glfwGetTime() + time;
		currentFrame = glfwGetTime();
		initX = x;
		initY = y;
		initZ = z;
	}

	if (startFrame != -999 && currentFrame < startFrame && ((x != x_) || (y != y_) || (z != z_))) {
		velocityX = deltaTime * ((x_ - initX) / time);
		velocityY = deltaTime * ((y_ - initY) / time);
		velocityZ = deltaTime * ((z_ - initZ) / time);
		
		x += velocityX;
		y += velocityY;
		z += velocityZ;

		Setup();
	}
}

void RegularPolygon::Update() {
	return;
}

double *RegularPolygon::GetSpeedTo(float x_, float y_, float z_, double time) {
	double resultX = ((x - x_) / time);
	double resultY = ((y - y_) / time);
	double resultZ = ((z - z_) / time);
	double *result[3] = { &resultX, &resultY, &resultZ };

	return *result;
}
