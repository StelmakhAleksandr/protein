#include "ShaderProgram.h"

GLchar ShaderProgram::infoLog[infoLen] = {};

void ShaderProgram::add(Shader *shader)
{
	shaders.push_back(shader);
}

void ShaderProgram::compile()
{
	for (vector<Shader*>::iterator shaderIt = shaders.begin(); shaderIt != shaders.end(); shaderIt++)
	{
		Shader *shader = *shaderIt;
		if (!shader->compile())
			continue;
		success(shader->getShader());
		glAttachShader(shaderProgram, shader->getShader());
	}
	glLinkProgram(shaderProgram);
	success(shaderProgram);
	compiled = true;
}

void ShaderProgram::run()
{
	if (!compiled)
		compile();
	glUseProgram(shaderProgram);
}

void ShaderProgram::success(GLuint program)
{
	GLint result;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(program, infoLen, NULL, infoLog);
		cout << "ERROR PROGRAM:" << endl << infoLog << endl;
	}
}

GLuint ShaderProgram::getProgram()
{
	return shaderProgram;
}

ShaderProgram::ShaderProgram()
{
	compiled = false;
	shaderProgram = glCreateProgram();
}


ShaderProgram::~ShaderProgram()
{
}
