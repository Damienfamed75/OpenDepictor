#ifdef _WIN32
	#define APIENTRY __stdcall
#endif //!_WIN32

#ifndef __glad_h_
	#include <glad/glad.h>
#endif //!__glad_h_

#ifdef _WINDOWS_
	#error windows.h was included!
#endif //!_WINDOWS_

#ifndef _glfw3_h_
	#include <GLFW/glfw3.h>
#endif //!_glfw3_h_

#ifdef _WIN32
	#ifndef _STRING_
		#include <string>
	#endif //!_STRING_
#endif //!_WIN32

#ifdef _WIN32
	#ifndef _IOSTREAM_
		#include <iostream>
	#endif //!_IOSTREAM_
#else // !_WIN32
	#ifndef _GLIBCXX_IOSTREAM
		#include <iostream>
	#endif //!_GLIBCXX_IOSTREAM
#endif //!_WIN32

#ifndef _VECTOR_
	#include <vector>
#endif //!_VECTOR_

#ifndef TRIANGLE_H
	#include "../include/Triangle.h"
#endif //!TRIANGLE_H

#ifndef SHADERS_H
	#include "../include/VariableObjects/Shaders.h"
#endif //!SHADERS_H

#ifndef REGULARPOLYGON_H
	#include "../include/RegularPolygon.h"
#endif //!REGULARPOLYGON_H

#ifndef NOTE_H
	#include "../include/Note.h"
#endif //!NOTE_H

#ifndef DEBUGVERTEXCONTROLLER_H
	#include "../include/DebugVertexController.h"
#endif //!DEBUGVERTEXCONTROLLER_H

#ifndef RENDERINGOBJECTS_HPP
	#include "../include/VariableObjects/RenderingObjects.hpp"
#endif //!RENDERINGOBJECTS_HPP

#ifndef CONTROLS_H
	#include "../include/VariableObjects/Controls.h"
#endif //!CONTROLS_H

#ifndef DEBUGVERTEXCONTROLLER_H
	#include "../include/DebugVertexController.h"
#endif //!DEBUGVERTEXCONTROLLER_H

#ifndef CONDUCTOR_H
	#include "../include/Conductor.h"
#endif //!CONDUCTOR_H

#ifndef ERRORS_H
	#include "../include/Errors.h"
#endif //!ERRORS_H

#ifndef GLM_HPP
	#define GLM_HPP
	#include <glm/glm.hpp>
#endif //!GLM_HPP

#include <stdio.h>

#ifdef _WIN32
	#include <direct.h>
	#define GetCurrentDir _getcwd
#else
	#include <unistd.h>
	#define GetCurrentDir getcwd
#endif //!_WIN32

#ifndef SHADER_H
	#include "../include/Shader.hpp"
#endif //!SHADER_H

#ifndef STBI_INCLUDE_STB_IMAGE_H
	#define STB_IMAGE_STATIC
	#include "../include/stb_image.h"
#endif //!STBI_INCLUDE_STB_IMAGE_H