#include "Application.h"
#include "Triangle.h"
#include "Quad.h"
#include "ShaderProgram.h"
#include "Quad.h"
#include "Circle.h"
#include <ctime>


int main()
{
	srand(time(NULL));
	Application *app = Application::getApplication();
	app->run(1024, 1024, "TEST");

	Shader *vertexShader = new Shader("vertex.vs", GL_VERTEX_SHADER);
	Shader *fragmentShader = new Shader("fragment.vs", GL_FRAGMENT_SHADER);
	ShaderProgram* program = new ShaderProgram();
	program->add(vertexShader);
	program->add(fragmentShader);
	program->compile();

	//circle start
	Circle *circle = new Circle(1000, Point(-0.25f, 0.25f, 0.0f), 0.3);
	circle->setColor(COLOR_BLUE);
	Triangle *triangle = new Triangle(Point(0.0f, 0.0f, 0.0f), Point(0.25f, 0.0f, 0.0f), Point(0.0f,-0.25f,0.0f));
	triangle->setColor(COLOR_BLUE);
	//circle end
	
	while (!glfwWindowShouldClose(app->getWindow()))
	{
		glfwPollEvents();
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//matrix
		//matrix end

		//render begin
		program->run();
		glm::mat4 transform;
		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, (GLfloat)glfwGetTime()* +0.5f, glm::vec3(0.0f, 0.0f, 1.0f));

		GLint transformlocation = glGetUniformLocation(program->getProgram(), "transform");
		glUniformMatrix4fv(transformlocation, 1, GL_FALSE, glm::value_ptr(transform));

		GLfloat timeValue = glfwGetTime();
		//circle->rotate(0.2);
		circle->draw();	
		//triangle->rotate(25,timeValue);
		//triangle->draw();
		//render end;
		glfwSwapBuffers(app->getWindow());
	}
	app->exit();
	return EXIT_SUCCESS;
}