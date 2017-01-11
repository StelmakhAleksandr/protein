#pragma once
#include <cmath>
#include "Triangle.h"

#define PI 3.1415

class Circle
{
private:
	vector<Triangle*> triangles;
	Point o;
	GLfloat radius;

public:
	Circle(int countTriangles, Point point, GLfloat radius);
	void setColor(Color);
	void draw();
	void rotate(GLfloat time);
	~Circle();
};

