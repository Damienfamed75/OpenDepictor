#ifndef NOTE_H
	#include "../include/Note.h"
#endif //!NOTE_H

#ifdef _WIN32
	#ifndef _IOSTREAM_
		#include <iostream>
	#endif //!_IOSTREAM_
#else // !_WIN32
	#ifndef _GLIBCXX_IOSTREAM
		#include <iostream>
	#endif //!_GLIBCXX_IOSTREAM
#endif //!_WIN32








Note::Note(GLfloat x_, GLfloat y_) 
	: RegularPolygon(x = (x_), y = (y_), 0.f, noteRadius, noteNumOfSides) {
	
	
}

Note::~Note() {
	return;
}

void Note::Hit() {
	
}