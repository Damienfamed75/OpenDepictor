#pragma once
#ifndef SHADERS_H
#define SHADERS_H
const GLchar* VertexShader = {
	"#version 400\n"\

	"layout(location=0) in vec4 in_Position;\n"\
	"layout(location=1) in vec4 in_Color;\n"\
	"out vec4 ex_Color;\n"\

	"void main(void)\n"\
	"{\n"\
	"  gl_Position = in_Position;\n"\
	"  ex_Color = in_Color;\n"\
	"}\n"
};
const GLchar* FragmentShader =
{
	"#version 400\n"\

	"in vec4 ex_Color;\n"\
	"out vec4 out_Color;\n"\

	"void main(void)\n"\
	"{\n"\
	"  out_Color = ex_Color;\n"\
	"}\n"
};
const GLchar* UniformFragmentShader =
{
	"#version 150 core\n"\

	"uniform vec3 triangColor;\n"\
	
	"out vec4 outColor\n"\
	
	"void main()\n"\
	"{\n"\
	"	outColor = vec4(triangleColor, 1.0);\n"\
	"}\n"
};
#endif