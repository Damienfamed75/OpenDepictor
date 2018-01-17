#include "../include/DebugVertexController.h"

#include <iostream>

const int SWITCH_KEY = GLFW_KEY_F;
int switchKeyPreviousState = GLFW_RELEASE;
int switchKeyCurrentState;
int pntNumKey = 0;


void DebugVertexController::controlTriangle(GLFWwindow *window, Triangle *triangle, RegularPolygon *selector, int joystick) {
	// variables
	// ---------
	
	int keyW = glfwGetKey(window, GLFW_KEY_W);
	int keyA = glfwGetKey(window, GLFW_KEY_A);
	int keyS = glfwGetKey(window, GLFW_KEY_S);
	int keyD = glfwGetKey(window, GLFW_KEY_D);
	int switchKey = glfwGetKey(window, SWITCH_KEY);
	switchKeyPreviousState = switchKeyCurrentState;
	switchKeyCurrentState = switchKey;


	// joystick input (underrides keyboard input)
	// ------------------------------------------
	if(glfwJoystickPresent(joystick) == GLFW_TRUE && 
		(keyW != GLFW_PRESS && keyA != GLFW_PRESS && keyS != GLFW_PRESS && keyD != GLFW_PRESS && switchKeyCurrentState != GLFW_PRESS)) {

		int joyCount, buttonCount, pointNumber = 3;
		const unsigned char *buttonAxes = glfwGetJoystickButtons(joystick, &buttonCount);
		const float *joyAxes = glfwGetJoystickAxes(joystick, &joyCount);
	
		if (buttonAxes[0] == GLFW_PRESS)
			pointNumber = 1;
		if (buttonAxes[1] == GLFW_PRESS)
			pointNumber = 2;
		if (buttonAxes[2] == GLFW_PRESS)
			pointNumber = 0;

		if (pointNumber != 3) {
#ifdef _WIN32
			triangle->Vertices[(pointNumber * 3)] += (joyAxes[0] * ((float)JOY_SENSITIVITY * JOY_MODIFIER));
			
			triangle->Vertices[(pointNumber * 3) + 1] += (joyAxes[1] * ((float)JOY_SENSITIVITY * JOY_MODIFIER));
#else //!_WIN32
			
			triangle->Vertices[(pointNumber * 3)] += 
				((joyAxes[0] > 0.12f ? joyAxes[0] : joyAxes[0] < -0.12f ? joyAxes[0] : 0) * ((float)JOY_SENSITIVITY *  JOY_MODIFIER));
			
			triangle->Vertices[(pointNumber * 3) + 1] += 
				((joyAxes[1] > 0.12f ? joyAxes[1] : joyAxes[1] < -0.12f ? joyAxes[1] : 0) * ((float)JOY_SENSITIVITY * -JOY_MODIFIER));
#endif // Compensation for Unix' lack of a deadzone.
			
			selector->MoveTo(triangle->Vertices[(pointNumber * 3)], triangle->Vertices[(pointNumber * 3) + 1], selector->z);
			selector->Draw();
		}

	}

	// keyboard input (overrides controller input)
	// -------------------------------------------
	if (switchKey == GLFW_PRESS && switchKey != switchKeyPreviousState) // switching vertices
		if (pntNumKey == 2)
			pntNumKey = 0;
		else pntNumKey++;

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