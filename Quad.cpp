#include "Quad.h"

Quad::Quad(Point a, Point b, Point c, Point d)
{
	first = new Triangle(a, b, c);
	second = new Triangle(a, d, c);
}

Quad::~Quad()
{
}

void Quad::setColor(Color color)
{
	first->setColor(color);
	second->setColor(color);
}

void Quad::setColorA(Color color)
{
	first->setColorA(color);
	second->setColorA(color);
}

void Quad::setColorB(Color color)
{
	first->setColorB(color);
}

void Quad::setColorC(Color color)
{
	first->setColorC(color);
	second->setColorC(color);
}

void Quad::setColorD(Color color)
{
	second->setColorB(color);
}

void Quad::draw()
{
	first->draw();
	second->draw();
}
