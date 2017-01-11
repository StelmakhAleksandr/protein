#include "Shader.h"

bool Shader::compile()
{
	if (error)
		return false;
	glCompileShader(shader);
	return true;
}

Shader::Shader(string shaderPathOrCode, int type, bool file)
{

	if(file)
	{
		ifstream shaderFile;
		shaderFile.exceptions(ifstream::badbit);
		try
		{
			shaderFile.open(shaderPathOrCode);
			stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();
			shaderPathOrCode = shaderStream.str();
		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
			error = true;
			return;
		}
	}
	error = false;
	shaderSource = shaderPathOrCode.c_str();
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderSource, NULL);
	
}


GLuint Shader::getShader()
{
	return shader;
}

Shader::~Shader()
{
	glDeleteShader(shader);
}
