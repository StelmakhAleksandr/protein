#include "Color.h"

Color Color::DEFAULT = COLOR_WHITE;

Color::Color(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha)
{
	this->red = r;
	this->green = g;
	this->blue = b;
	this->alpha = alpha;
}

Color::Color()
{
}

Color Color::setAlpha(GLfloat alpha)
{
	this->alpha = alpha;
	return *this;
}

Color::~Color()
{
}
