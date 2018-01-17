#pragma once

#ifndef __glad_h_
	#include <glad/glad.h>
#endif // !__glad_h_

#ifndef _glfw3_h_
	#include <GLFW/glfw3.h>
#endif //!_glfw3_h_

#ifndef TRIANGLE_H
	#include "Triangle.h"
#endif // !TRIANGLE_H

#ifndef REGULARPOLYGON_H
	#include "RegularPolygon.h"
#endif // !REGULARPOLYGON_H

extern const GLint JOY_SENSITIVITY;
extern const GLfloat JOY_MODIFIER;

#ifndef DEBUVERTEXCONTROLLER_H
#define DEBUGVERTEXCONTROLLER_H


class DebugVertexController {
public:
	static void controlTriangle(GLFWwindow *window, Triangle *triangle, RegularPolygon *selector, int joystick);
};

#endif // !DEBUVERTEXCONTROLLER_H