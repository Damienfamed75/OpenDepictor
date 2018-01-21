#pragma once

#ifndef REGULARPOLYGON_H
	#include "RegularPolygon.h"
#endif // !REGULARPOLYGON_H









#ifndef NOTE_H
#define NOTE_H





const GLint noteNumOfSides = 36;
const GLfloat noteRadius = 0.15f;

class Note : public RegularPolygon {
public:
	//Note(GLfloat x_, GLfloat y_);
	Note(GLfloat x_, GLfloat y_);
	
	~Note();
	void Hit();
private:

};
#endif