#pragma once
#include "Point.h"
#include "Color.h"
#include <vector>
using namespace std;

#define TRIANGLE_VERTEXES 3
class Triangle
{
private:
	vector<Point> vertices;
	vector<Color> colors;
	vector<Color> times;
	GLuint vertexBuf;
	GLuint colorBuf;
	GLuint timeBuffer;
	GLuint VAO;
	void init();
	bool initialized;
public:
	Triangle(vector<Point> vertices, vector<Color> colors);
	Triangle(Point a, Point b, Point c);
	void setColor(Color color);
	void setColorA(Color color);
	void setColorB(Color color);
	void setColorC(Color color);
	Point getA();
	Point getB();
	Point getC();
	void rotate(double angle, double t);
	void draw();
	~Triangle();
};

