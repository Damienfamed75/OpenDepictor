#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

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
	
	GLfloat *polygonVerticesX;
	GLfloat *polygonVerticesY;
	GLfloat *polygonVerticesZ;
	GLfloat *allPolygonVertices;
	GLfloat *Colors;
	
	RegularPolygon(GLfloat x_, GLfloat y_, GLfloat z_, GLfloat r_, GLint numOfSides_);

	void Setup();
	void CreateVBO();
	void Draw();
	void DestroyVBO();
	void CreateShaders();
	void DestroyShaders();
	void CleanUp();
	void Rotate(float angle);
	void UpdateColor(float r, float g, float b);
private:
	GLuint vertexShaderId, fragmentShaderId,
		colorBuffer, VAO, VBO, shaderProgram;
};

#endif // !REGULARPOLYGON_H