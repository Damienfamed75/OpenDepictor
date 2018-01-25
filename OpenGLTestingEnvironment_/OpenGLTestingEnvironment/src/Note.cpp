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








Note::Note(GLFWwindow *window_, GLfloat xInit, GLfloat yInit, GLfloat xFinal, GLfloat yFinal, GLdouble time_, int key, int button)
	: RegularPolygon(x = (xInit), y = (yInit), 0.f, noteRadius, noteNumOfSides),
	shadow(new RegularPolygon(xFinal, yFinal, 0.f, noteRadius, noteNumOfSides)),
	window(*window_), key_code(key), button_code(button), time(time_) {

	shadow->UpdateColor((NOTECOL_R - 0.3f), (NOTECOL_G - 0.3f), (NOTECOL_B - 0.3f), 0.5f);
	//this->TranslateTo(window, xFinal, yFinal, 0.f, time);
}

Note::~Note() {
	return;
}

bool Note::Hit() {
	int keyState = glfwGetKey(&window, key_code);
	keyPrevState = keyCurrState;
	keyCurrState = keyState;
	
	if (keyState == GLFW_PRESS && keyState != keyPrevState)
		return true;

	if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GLFW_TRUE) {
		int buttonCount;
		const unsigned char *buttonStates = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
		buttonPrevState = buttonCurrState;
		buttonCurrState = buttonStates[button_code];

		if (buttonStates[button_code] == GLFW_PRESS && buttonStates[button_code] != buttonPrevState)
			return true;
	}

	return false;
}
void Note::Update() {
	//!TODO - Fix the bug where you can slow down travel by pressing again mid-travel
	
	//this->TranslateTo(&window, shadow->x, shadow->y, shadow->z, time);
	
	bool noteHit = Hit();
	if (noteHit) {
		this->UpdateColor(1.0f, 0.f, 0.f, 1.0f);
		//! TODO note death animation
		//double timeEnd = glfwGetTime() + 1.0;
		//if(glfwGetTime() < timeEnd) {
			//animTemp += deltaTime * 0.6;
			//if (animTemp > (M_PI * 2.0)) animTemp -= (M_PI * 2.0);
			//this->r += sin(animTemp) * 0.3;
			//this->Setup();
			//this->Draw();
		//}
	} else {
		this->UpdateColor(NOTECOL_R, NOTECOL_G, NOTECOL_B, 1.0f);
	}
	shadow->Draw();
}