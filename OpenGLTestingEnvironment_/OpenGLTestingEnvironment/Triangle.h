#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Vector3.h"
#include "Color.h"

extern const GLchar* VertexShader;
extern const GLchar* FragmentShader;

class Triangle {
public:
	Vector3 coord1 = Vector3(-0.8f, -0.8f, 0.0f);
	Vector3 coord2 = Vector3(-0.8f,  0.8f, 0.0f);
	Vector3 coord3 = Vector3( 0.8f,  0.8f,  0.0f);
	Triangle();
	Triangle(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
	GLfloat Vertices[9] = {
		-0.8f, -0.8f, 0.0f,
		-0.8f, 0.8f, 0.0f, 
		0.8f, 0.8f, 0.0f
	};
	GLfloat Colors[16] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f
	};
	void CleanUp();
	void CreateVBO();
	void DestroyVBO();
	void Draw();
	void CreateShaders();
	void DestroyShaders();
	void Move(float x, float y);
	void MoveTo(float x, float y);
	void Transfer(float x, float y, float animSpeed);
	void TransferTo(float x, float y, float animSpeed);
	void UpdatePos(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
	void UpdateColor(Color col1_, Color col2_, Color col3_);
private:
	GLuint vertexShaderId, fragmentShaderId,
		colorBuffer, VAO, VBO, shaderProgram;
};