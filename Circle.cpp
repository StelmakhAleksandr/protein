#include "Circle.h"



Circle::Circle(int countTriangles, Point o, GLfloat radius)
{
	this->o = o;
	this->radius = radius;
	double angle = 2 * PI / countTriangles;//v radianah

	Point b(o.x - radius, o.y, o.z);
	Color color;
	color.alpha = 0.5;
	for (int i = 0; i < countTriangles; i++)
	{
		color.red = (double)(rand()) / RAND_MAX;
		color.green = (double)(rand()) / RAND_MAX;
		color.blue = (double)(rand()) / RAND_MAX;
		Triangle *triangle = new Triangle(o, b, b);
		triangle->setColor(COLOR_RED);
		triangle->rotate(angle, i);
		triangles.push_back(triangle);
		b = triangle->getC();
	}

}

void Circle::setColor(Color color)
{
	for (vector<Triangle*>::iterator triangle = triangles.begin(); triangle != triangles.end(); triangle++)
	{
		(*triangle)->setColor(color);
	}
}

void Circle::draw()
{
	for (vector<Triangle*>::iterator triangle = triangles.begin(); triangle != triangles.end(); triangle++)
	{
		(*triangle)->draw();
	}
}

void Circle::rotate(GLfloat time)
{
	double angle = 2 * PI / triangles.size();
	for (int i = 0; i < triangles.size(); i++)
	{
		triangles[i]->rotate(angle,i);
	}
}

Circle::~Circle()
{
}
