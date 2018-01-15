#pragma once

#ifndef __glad_h_
	#include <glad/glad.h>
#endif

#ifndef _glfw3_h_
	#include <GLFW/glfw3.h>
#endif

#ifndef VECTOR3_H
	#include "VariableObjects/Vector3.h"
#endif //!VECTOR3_H

#ifndef COLOR_H
	#include "VariableObjects/Color.h"
#endif //!COLOR_H

extern const GLchar* VertexShader;
extern const GLchar* FragmentShader;


#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle {
public:
	Vector3 coord1 = Vector3(-0.8f, -0.8f, 0.0f);
	Vector3 coord2 = Vector3(-0.8f, 0.8f, 0.0f);
	Vector3 coord3 = Vector3(0.8f, 0.8f, 0.0f);
	Triangle();
	Triangle(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
	GLfloat Vertices[12] = {
		-0.8f, -0.8f, 0.0f,
		-0.8f,  0.8f, 0.0f,
		0.8f,  0.8f, 0.0f,
		0.0f,  0.1f, 0.0f
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
	void Translate(float x, float y, float animSpeed);
	void TransferTo(float x, float y, float animSpeed);
	void UpdatePos(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_);
	void UpdateColor(Color col1_, Color col2_, Color col3_);
private:
	GLuint vertexShaderId, fragmentShaderId,
		colorBuffer, VAO, VBO, shaderProgram;
};

#endif // !TRIANGLE_H