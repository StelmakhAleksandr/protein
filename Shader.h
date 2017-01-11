#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Application.h"
using namespace std;

class Shader
{
private:
	GLuint shader;
	const GLchar * shaderSource;
	bool error;
public:
	Shader(string,int,bool file = true);
	GLuint getShader();
	bool compile();
	~Shader();
};

