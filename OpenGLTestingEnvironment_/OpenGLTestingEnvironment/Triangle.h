#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Vector3.h"
/*
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f,  0.5f, 0.0f
}; // triangle vertices*/
//GLuint vertexShader, fragmentShader;

class Triangle {
public:
	Triangle(Vector3 *coord1_, Vector3 *coord2_, Vector3 *coord3_);
	Vector3 *coord1 = new Vector3(-0.5f, -0.5f, 0.0f);
	Vector3 *coord2 = new Vector3(0.5f, -0.5f, 0.0f);
	Vector3 *coord3 = new Vector3(0.0f, 0.5f, 0.0f);
	/*
	float *vertices[9] = {
		&coord1->x, &coord1->y, &coord1->z,
		&coord2->x, &coord2->y, &coord2->z,
		&coord3->x, &coord3->y, &coord3->z
	};
	*/
	float vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f,  0.5f, 0.0f
	}; // triangle vertices
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
	
	void BeginProgram();
	void Draw();
private:
	unsigned int VBO, VAO, /*vertexShader,*/
		/*fragmentShader,*/ shaderProgram, colorBuffer;
	GLuint vertexShaderId, fragmentShaderId;
	const GLchar* VertexShader = {
		"#version 400\n"\

		"layout(location=0) in vec4 in_Position;\n"\
		"layout(location=1) in vec4 in_Color;\n"\
		"out vec4 ex_Color;\n"\

		"void main(void)\n"\
		"{\n"\
		"  gl_Position = in_Position;\n"\
		"  ex_Color = in_Color;\n"\
		"}\n"
	};
	const GLchar* FragmentShader =
	{
		"#version 400\n"\

		"in vec4 ex_Color;\n"\
		"out vec4 out_Color;\n"\

		"void main(void)\n"\
		"{\n"\
		"  out_Color = ex_Color;\n"\
		"}\n"
	};
	//void PrepareObjects();
	void CreateVBO();
	void DestroyVBO();
	void BufferData();
	void CreateShaders();
	void DestroyShaders();
	//void SetTextureSettings();
	//void LoadShaders();
	//void LoadNewShader(const char*); //! TODO
	//void CreateProgram();
	//void UnloadShaders();
};