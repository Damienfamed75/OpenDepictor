#include "../include/Note.h"
#include <iostream>

Note::Note(GLfloat x_, GLfloat y_) 
	: RegularPolygon(x = (x_), y = (y_), 0.f, noteRadius, noteNumOfSides) {
	
	
}

Note::~Note() {
	return;
}

void Note::Hit() {
	
}