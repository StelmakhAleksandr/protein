#pragma once
#include "Application.h"

#define COLOR_COUNT 4

#define COLOR_RED Color(1.0, 0.0, 0.0)
#define COLOR_GREEN Color(0.0, 1.0, 0.0) 
#define COLOR_BLUE Color(0.0, 0.0, 1.0)
#define COLOR_YELLOW Color(1.0, 1.0, 0.0)
#define COLOR_WHITE Color(1.0, 1.0, 1.0)
#define COLOR_BLACK Color(0.0, 0.0, 0.0)
#define COLOR_DEFAULT Color::DEFAULT

#define COLOR_REDA Color(COLOR_RED).setAlpha
#define COLOR_GREENA Color(COLOR_GREEN).setAlpha
#define COLOR_BLUEA Color(COLOR_BLUE).setAlpha
#define COLOR_YELLOWA Color(COLOR_YELLOW).setAlpha
#define COLOR_WHITEA Color(COLOR_WHITE).setAlpha
#define COLOR_BLACKA Color(COLOR_BLACK).setAlpha
#define COLOR_DEFAULTA Color(COLOR_DEFAULT).setAlpha


class Color
{
public:
	GLfloat red;
	GLfloat green;
	GLfloat blue;
	GLfloat alpha;

	Color(GLfloat, GLfloat, GLfloat, GLfloat alpha = 1.0);
	Color();
	Color setAlpha(GLfloat alpha);
	static Color DEFAULT;
	~Color();
};

