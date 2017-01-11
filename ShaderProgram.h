#pragma once
#include "Shader.h"
#include <vector>
using namespace std;

class ShaderProgram
{
private:
	vector<Shader*> shaders;
	GLuint shaderProgram;
	static const int infoLen = 512;
	static GLchar infoLog[infoLen];
	bool compiled;
public:
	void add(Shader*);
	void compile();
	void run();
	void success(GLuint program);
	GLuint getProgram();
	ShaderProgram();
	~ShaderProgram();
};

