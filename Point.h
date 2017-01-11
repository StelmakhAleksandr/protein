#pragma once
#include "Application.h"

#define COORDS_COUNT 3

struct Point
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	Point(GLfloat, GLfloat, GLfloat);
	Point();
	~Point();
};

