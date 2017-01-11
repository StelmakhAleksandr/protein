#include "Application.h"

Application* Application::application = nullptr;

Application::Application()
{
	running = false;
	glfwUsed = false;
	glewUsed = false;
}

bool Application::startGlfw()
{
	if (!glfwInit())
		return false;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwUsed = true;
	return true;
}

bool Application::startGlew()
{
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}
	glewUsed = true;
	return true;
}


int Application::getWidth()
{
	return screenWidth;
}

int Application::getHeight()
{
	return screenHeight;
}

void Application::run(GLint width, GLint height, const char *title)
{
	if (running)
		return;
	if (!startGlfw())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!window)
		exit(EXIT_FAILURE);
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	std::cout << "Application started with parameters " << screenWidth << "X" << screenHeight << std::endl;
	glfwMakeContextCurrent(window);
	if (!startGlew())
		exit(EXIT_FAILURE);
	glViewport(0, 0, screenWidth, screenHeight);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	running = true;
}

void Application::exit(int code)
{
	if(glfwUsed)
		glfwTerminate();
	std::cout << "Application exit with code " << code << std::endl;
	::exit(code);
}

Application * Application::getApplication()
{
	if (!application)
		application = new Application();
	return application;
}

GLFWwindow * Application::getWindow()
{
	return window;
}

Application::~Application()
{
}