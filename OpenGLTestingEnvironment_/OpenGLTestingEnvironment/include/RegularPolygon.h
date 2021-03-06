#pragma once

#ifndef __glad_h_
	#include <glad/glad.h>
#endif //!__glad_h_

#ifndef _glfw3_h_
	#include <GLFW/glfw3.h>
#endif //!_glfw3_h_

#ifndef _GLIBCXX_MATH_H
	#include <math.h>
#endif //!_GLIBCXX_MATH_H

#include "Texture.hpp"
#include "Shader.hpp"

#ifndef M_PI
	#define M_PI 3.14159265358979323846f
#endif // !M_PI

extern const GLchar* VertexShader;
extern const GLchar* FragmentShader;



#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H



class RegularPolygon {
public:
	GLfloat x = 0.0f, y = 0.0f, z = 0.0f, r = 1.0f, doublePi = 2.0f * M_PI;
	GLint numOfSides;
	int numOfVertices;
	
	GLfloat texCoords[8] = {
		1.f, 1.f,
		1.f, 0.f,
		0.f, 0.f,
		0.f, 1.f
	};
	GLfloat indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	GLfloat *polygonVerticesX;
	GLfloat *polygonVerticesY;
	GLfloat *polygonVerticesZ;
	GLfloat *allPolygonVertices;
	GLfloat *Colors;

	friend class Note;

	//Shader shader("../shaders/sprite.vs", "../shaders/sprite.frag");
	RegularPolygon() {}
	RegularPolygon(GLfloat x_, GLfloat y_, GLfloat z_, GLfloat r_, GLint numOfSides_);
	void Setup();
	void CreateVBO();
	void Draw();
	void Update();
	void DestroyVBO();
	void CreateShaders();
	void DestroyShaders();
	void CleanUp();
	void Rotate(float angle);
	void MoveTo(float x_, float y_, float z_);
	void Move(float x_, float y_, float z_);
	double *GetSpeedTo(float x_, float y_, float z_, double time);
	void Translate(float x_, float y_, float z_, double time);
	void TranslateTo(GLFWwindow *window, float x_, float y_, float z_, double time);
	void UpdateColor(float r, float g, float b, float a);
private:
	GLuint vertexShaderId, fragmentShaderId,
		colorBuffer, VAO, VBO, TBO, shaderProgram;
	GLdouble currentFrame, lastFrame, deltaTime, startFrame,
		velocityX, velocityY, velocityZ, initX, initY, initZ;
};

#endif // !REGULARPOLYGON_H