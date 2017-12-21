#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Vector3.h"
#include "Color.h"

extern const GLchar* VertexShader;
extern const GLchar* FragmentShader;

class Triangle {
public:
	Vector3 coord1 = Vector3(-0.8f, -0.8f,  0.0f);
	Vector3 coord2 = Vector3( 0.0f,  0.8f,  0.0f);
	Vector3 coord3 = Vector3( 0.8f, -0.8f,  0.0f);
	Triangle();
	Triangle(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
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
	void CreateVBO();
	void DestroyVBO();
	void CreateShaders();
	void DestroyShaders();
	void UpdatePos(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
	void UpdateColor(Color col1_, Color col2_, Color col3_);
private:
	GLuint vertexShaderId, fragmentShaderId,
		colorBuffer, VAO, VBO, shaderProgram;
};