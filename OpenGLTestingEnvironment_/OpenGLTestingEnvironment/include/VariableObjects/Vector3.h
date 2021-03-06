#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H



struct Vector3 {
public:
	Vector3(float x_, float y_, float z_);
	Vector3(float xyz[3]);
	void SetPoints(float x_, float y_, float z_);
	void SetPoints(float xyz[3]);
	float x, y, z;
};
#endif // !VECTOR3_H