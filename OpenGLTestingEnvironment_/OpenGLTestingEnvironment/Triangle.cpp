#include "Triangle.h"
#include <iostream>

using std::cout;
using std::endl;

Triangle::Triangle() {
	CreateVBO();
	CreateShaders();
	DestroyShaders();
	DestroyVBO();
}
Triangle::Triangle(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_) { // TODO REFACTOR
	Vertices[0]  = coord1_.x;
	Vertices[1]  = coord1_.y;
	Vertices[2]  = coord1_.z;
	Vertices[3]  = coord2_.x;
	Vertices[4]  = coord2_.y;
	Vertices[5]  = coord2_.z;
	Vertices[6]  = coord3_.x;
	Vertices[7]  = coord3_.y;
	Vertices[8]  = coord3_.z;
	CreateVBO();
	CreateShaders();
	DestroyShaders();
	DestroyVBO();
}
void Triangle::CreateVBO() {
	GLenum ErrorCheckValue = glGetError();

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
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
void Triangle::DestroyShaders() {
	GLenum ErrorCheckValue = glGetError();

	glUseProgram(0);

	glDetachShader(shaderProgram, vertexShaderId);
	glDetachShader(shaderProgram, fragmentShaderId);

	glDeleteShader(fragmentShaderId);
	glDeleteShader(vertexShaderId);

	glDeleteProgram(shaderProgram);
}
void Triangle::UpdatePos(Vector3 coord1_, Vector3 coord2_, Vector3 coord3_) { // TODO REFACTOR
	Vertices[0] = coord1_.x;
	Vertices[1] = coord1_.y;
	Vertices[2] = coord1_.z;
	Vertices[3] = coord2_.x;
	Vertices[4] = coord2_.y;
	Vertices[5] = coord2_.z;
	Vertices[6] = coord3_.x;
	Vertices[7] = coord3_.y;
	Vertices[8] = coord3_.z;
}
void Triangle::UpdateColor(Color col1_, Color col2_, Color col3_) { // TODO REFACTOR
	Colors[0] = col1_.r;
	Colors[1] = col1_.g;
	Colors[2] = col1_.b;
	Colors[3] = col1_.a;
	Colors[4] = col2_.r;
	Colors[5] = col2_.g;
	Colors[6] = col2_.b;
	Colors[7] = col2_.a;
	Colors[8] = col3_.r;
	Colors[9] = col3_.g;
	Colors[10] = col3_.b;
	Colors[11] = col3_.a;
}
void Triangle::CleanUp() {
	DestroyShaders();
	DestroyVBO();
}
void Triangle::Move(float x, float y) { // TODO REFACTOR
	Vertices[0] += x;
	Vertices[4] += x;
	Vertices[8] += x;
	Vertices[1] += y;
	Vertices[5] += y;
	Vertices[9] += y;
}
void Triangle::MoveTo(float x, float y) {
	return;
}
void Triangle::Translate(float x, float y, float animSpeed) {
	return;
}
void Triangle::TransferTo(float x, float y, float animSpeed) {
	return;
}
void Triangle::Draw() {
	CreateShaders();
	CreateVBO();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	CleanUp();
}