#pragma once
#include "Triangle.h"
class Quad
{
private:
	Triangle *first;
	Triangle *second;
public:
	Quad(Point a, Point b, Point c, Point d);
	~Quad();
	void setColor(Color color);
	void setColorA(Color color);
	void setColorB(Color color);
	void setColorC(Color color);
	void setColorD(Color color);
	void draw();
};

