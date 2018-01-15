#pragma once

#ifndef COLOR_H
#define COLOR_H

struct Color {
public:
	Color(float r_, float g_, float b_, float a_);
	float r, g, b, a;
};
#endif // !COLOR_H