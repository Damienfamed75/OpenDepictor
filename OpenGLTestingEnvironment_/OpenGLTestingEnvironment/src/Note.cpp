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

#include "../include/Conductor.h"

extern Conductor mainConductor;

Note::Note(GLFWwindow *window_, GLfloat xInit, GLfloat yInit, GLfloat xFinal, GLfloat yFinal, GLdouble time_, int key, int button)
	: RegularPolygon(x = (xInit), y = (yInit), 0.f, noteRadius, noteNumOfSides),
	shadow(new RegularPolygon(xFinal, yFinal, 0.f, noteRadius, noteNumOfSides)),
	window(*window_), key_code(key), button_code(button), time(time_) {
	x = -1.0;
	shadow->UpdateColor((NOTECOL_R - 0.3f), (NOTECOL_G - 0.3f), (NOTECOL_B - 0.3f), 1.f);
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
	Setup();

	bool noteHit = Hit();
	if (noteHit) {
		this->UpdateColor(1.0f, 0.f, 0.f, 1.0f);
	} else {
		this->UpdateColor(NOTECOL_R, NOTECOL_G, NOTECOL_B, 1.0f);
	}
	shadow->Draw();
	MoveByBeats(&window, ::mainConductor.numBeatsSinceRefresh);	
}

void Note::MoveByBeats(GLFWwindow *window, float beats) {
	if(x > 0.0)
		x = -1.0;
	else
		x += beats;
}
