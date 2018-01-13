#include "HeaderFiles/VariableObjects/Vector3.h"

#ifndef CHOOSE
#define CHOOSE(i,x,y,z) (i == 1? x : i == 2 ? y : z)
#endif // CHOOSE

Vector3::Vector3(float x_, float y_, float z_) {
	SetPoints(x_, y_, z_);
}
Vector3::Vector3(float xyz[3]) {
	SetPoints(xyz);
}
void Vector3::SetPoints(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}
void Vector3::SetPoints(float xyz[3]) {
	for (int i = 0; i < sizeof(xyz); i++)
		CHOOSE(i, x, y, z) = xyz[i];
}