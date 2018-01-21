#ifndef DEBUGVERTEXCONTROLLER_H
	#include "../include/DebugVertexController.h"
#endif //!DEBUGVERTEXCONTROLLER_H

#ifndef _IOSTREAM_
	#include <iostream>
#endif //!_IOSTREAM_




int SWITCH_KEY = GLFW_KEY_F; // key binding for switching vertices.
int pntNumKey = 0; // vertex tracker
int switchKeyPreviousState = GLFW_RELEASE;
int switchKeyCurrentState;

//! TODO: add Deadzone modifier.

void DebugVertexController::controlTriangle(GLFWwindow *window, Triangle *triangle, RegularPolygon *selector, int joystick = 0) {
	/// argument checks
	/// ---------------
	if(window == NULL)
		throw std::invalid_argument("Window parameter equal to NULL");
	if(triangle == NULL)
		throw std::invalid_argument("Triangle parameter equal to NULL");
	if(selector == NULL)
		throw std::invalid_argument("RegularPolygon parameter equal to NULL");
		

	/// variables
	/// ---------
	int keyW = glfwGetKey(window, GLFW_KEY_W);
	int keyA = glfwGetKey(window, GLFW_KEY_A);
	int keyS = glfwGetKey(window, GLFW_KEY_S);
	int keyD = glfwGetKey(window, GLFW_KEY_D);
	int switchKey = glfwGetKey(window, SWITCH_KEY);
	switchKeyPreviousState = switchKeyCurrentState;
	switchKeyCurrentState = switchKey;


	/// joystick input (underrides keyboard input)
	/// ------------------------------------------
	if(glfwJoystickPresent(joystick) == GLFW_TRUE && 
		(keyW != GLFW_PRESS && keyA != GLFW_PRESS && keyS != GLFW_PRESS && keyD != GLFW_PRESS && switchKeyCurrentState != GLFW_PRESS)) {

		int joyCount, buttonCount, pointNumber = 3;
		const unsigned char *buttonAxes = glfwGetJoystickButtons(joystick, &buttonCount);
		const float *joyAxes = glfwGetJoystickAxes(joystick, &joyCount);

		// causes argument NULL pointer exception? I'm not sure why.
		//pointNumber = (buttonAxes[0] == GLFW_PRESS ? 1 : buttonAxes[1] == GLFW_PRESS ? 2 : 0);
		
		if (buttonAxes[0] == GLFW_PRESS)
			pointNumber = 1;
		if (buttonAxes[1] == GLFW_PRESS)
			pointNumber = 2;
		if (buttonAxes[2] == GLFW_PRESS)
			pointNumber = 0;

		//! optimized for xbox controllers
		if (pointNumber != 3) { // updating vertex coordinates.
#ifdef _WIN32
			triangle->Vertices[(pointNumber * 3)] += (joyAxes[0] * ((float)JOY_SENSITIVITY * JOY_MODIFIER));
			
			triangle->Vertices[(pointNumber * 3) + 1] += (joyAxes[1] * ((float)JOY_SENSITIVITY * JOY_MODIFIER));
#else //!_WIN32
			
			// Unix machines don't have a dead-zone.
			triangle->Vertices[(pointNumber * 3)] += 
				((joyAxes[0] > 0.12f ? joyAxes[0] : joyAxes[0] < -0.12f ? joyAxes[0] : 0) * ((float)JOY_SENSITIVITY *  JOY_MODIFIER));
			
			triangle->Vertices[(pointNumber * 3) + 1] += 
				((joyAxes[1] > 0.12f ? joyAxes[1] : joyAxes[1] < -0.12f ? joyAxes[1] : 0) * ((float)JOY_SENSITIVITY * -JOY_MODIFIER));
#endif // Compensation for Unix' lack of a deadzone.
			
			selector->MoveTo(triangle->Vertices[(pointNumber * 3)], triangle->Vertices[(pointNumber * 3) + 1], selector->z);
			selector->Draw();
		}

	}

	/// keyboard input (overrides controller input)
	/// -------------------------------------------
	if (switchKey == GLFW_PRESS && switchKey != switchKeyPreviousState) // switching vertices
		if (pntNumKey == 2)
			pntNumKey = 0;
		else pntNumKey++;


	// updating triangle vertex coordinates.
	if (keyW == GLFW_PRESS)
		triangle->Vertices[(pntNumKey * 3) + 1] += ((JOY_SENSITIVITY * JOY_MODIFIER));
	if (keyS == GLFW_PRESS)
		triangle->Vertices[(pntNumKey * 3) + 1] -= ((JOY_SENSITIVITY * JOY_MODIFIER));
	if (keyD == GLFW_PRESS)
		triangle->Vertices[(pntNumKey * 3)] += ((JOY_SENSITIVITY * JOY_MODIFIER));
	if (keyA == GLFW_PRESS)
		triangle->Vertices[(pntNumKey * 3)] -= ((JOY_SENSITIVITY * JOY_MODIFIER));

	// only if a key is pressed then it'll draw a circle.
	if (keyW == GLFW_PRESS || keyA == GLFW_PRESS || keyS == GLFW_PRESS || keyD == GLFW_PRESS || switchKeyCurrentState == GLFW_PRESS) {
		selector->MoveTo(triangle->Vertices[(pntNumKey * 3)], triangle->Vertices[(pntNumKey * 3) + 1], selector->z);
		selector->Draw();
	}
	
}