#include "Triangle.h"

void Triangle::init()
{
	 
	glGenBuffers(1, &vertexBuf);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuf);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*COORDS_COUNT * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &colorBuf);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuf);
	glBufferData(GL_ARRAY_BUFFER, colors.size()*COLOR_COUNT * sizeof(GLfloat), &colors[0], GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glBindBuffer(GL_ARRAY_BUFFER, vertexBuf);
	glVertexAttribPointer(0, COORDS_COUNT, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, colorBuf);
	glVertexAttribPointer(1, COLOR_COUNT, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	initialized = true;
}

Triangle::Triangle(vector<Point> vertices, vector<Color> colors)
{
	this->vertices = vertices;
	this->colors = colors;
	initialized = false;
}

Triangle::Triangle(Point a, Point b, Point c)
{
	vertices.push_back(a);
	vertices.push_back(b);
	vertices.push_back(c);
	colors.push_back(COLOR_DEFAULT);
	colors.push_back(COLOR_DEFAULT);
	colors.push_back(COLOR_DEFAULT);
	initialized = false;
}

void Triangle::setColor(Color color)
{
	for (int i = 0; i < colors.size(); i++)
		colors[i] = color;
}

void Triangle::setColorA(Color color)
{
	colors[0] = color;
}

void Triangle::setColorB(Color color)
{
	colors[1] = color;
}

void Triangle::setColorC(Color color)
{
	colors[2] = color;
}

Point Triangle::getA()
{
	return vertices[0];
}

Point Triangle::getB()
{
	return vertices[1];
}

Point Triangle::getC()
{
	return vertices[2];
}

void Triangle::draw()
{
	if (!initialized)
		init();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLE_FAN, 0, TRIANGLE_VERTEXES);
	glBindVertexArray(0);
}

void Triangle::rotate(double angle, double t)
{
	GLfloat ab = sqrt(pow(vertices[1].y - vertices[0].y, 2) + pow(vertices[1].x - vertices[0].x, 2));
	vertices[1] = vertices[2];
	vertices[2].x = vertices[0].x + ab*cos(angle*t);
	vertices[2].y = vertices[0].y + ab*sin(angle*t);
	init();
}

Triangle::~Triangle()
{
}
