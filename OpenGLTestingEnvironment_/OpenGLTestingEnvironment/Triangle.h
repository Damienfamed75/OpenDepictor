#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Vector3.h"

extern const GLchar* VertexShader;
extern const GLchar* FragmentShader;

class Triangle {
public:
	Vector3 coord1 = Vector3(-0.8f, -0.8f,  0.0f);
	Vector3 coord2 = Vector3( 0.0f,  0.8f,  0.0f);
	Vector3 coord3 = Vector3( 0.8f, -0.8f,  0.0f);
	Triangle(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
	/*
	GLfloat Vertices[12] = {
		-0.8f, -0.8f, 0.0f, 1.0f,
		0.0f,  0.8f, 0.0f, 1.0f,
		0.8f, -0.8f, 0.0f, 1.0f
	};*/
	GLfloat Vertices[12] = {
		coord1.x, coord1.y, coord1.z, coord1.w,
		coord2.x, coord2.y, coord2.z, coord2.w,
		coord3.x, coord3.y, coord3.z, coord3.w
	};
	GLfloat Colors[12] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f
	};
	Triangle();
	int Usage = GL_STATIC_DRAW;
	int Index = 0;
	int Size = 3;
	int Target = GL_ARRAY_BUFFER;
	/*float *vertices[9] = {
		&coord1.x, &coord1.y, &coord1.z,
		&coord2.x, &coord2.y, &coord2.z,
		&coord3.x, &coord3.y, &coord3.z
	};*/
	void CreateVBO();
	void DestroyVBO();
	void CreateShaders();
	void DestroyShaders();
	void UpdatePos(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
private:
	GLuint vertexShaderId, fragmentShaderId,
		colorBuffer, VAO, VBO, shaderProgram;
};