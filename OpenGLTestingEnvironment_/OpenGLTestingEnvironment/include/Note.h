#pragma once

#ifndef REGULARPOLYGON_H
	#include "RegularPolygon.h"
#endif // !REGULARPOLYGON_H



#ifndef NOTE_H
#define NOTE_H


const GLint noteNumOfSides = 36;
const GLfloat noteRadius = 0.15f;
const GLfloat NOTECOL_R = 0.5f;
const GLfloat NOTECOL_G = 0.4f;
const GLfloat NOTECOL_B = 1.f;

class Note : public RegularPolygon {
public:
	Note(GLFWwindow *window, GLfloat xInit, GLfloat yInit, GLfloat xFinal, GLfloat yFinal, GLdouble time_, int key, int button);
	~Note();

	void Update();
	bool Hit();
	/** Finding speed:
	 * Vav = ((x - xo)/(t - to));
	*/
private:
	GLFWwindow &window;
	RegularPolygon *shadow;
	double animTemp = 0, time;
	int key_code, button_code, keyPrevState = GLFW_RELEASE, keyCurrState,
		buttonPrevState = GLFW_RELEASE, buttonCurrState;
};
#endif