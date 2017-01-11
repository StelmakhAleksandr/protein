#pragma once
#include <iostream>
#define GLEW_STATIC
#include <glm/glm.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Application
{
private:
	GLFWwindow *window;
	int screenWidth;
	int screenHeight;
	bool running;
	bool glfwUsed;
	bool glewUsed;
	Application();
	bool startGlfw();
	bool startGlew();
	static Application *application;
public:
	int getWidth();
	int getHeight();
	void run(GLint,GLint,const char*);
	void exit(int code=EXIT_SUCCESS);
	static Application *getApplication();
	GLFWwindow *getWindow();
	~Application();
};

