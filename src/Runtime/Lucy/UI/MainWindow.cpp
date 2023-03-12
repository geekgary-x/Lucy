#include "MainWindow.h"
#include <iostream>
#include <GLFW/glfw3.h>
namespace Lucy
{
	void MainWindow::loop()
	{
		while (!glfwWindowShouldClose(m_GLFWwindow))
		{
			glfwPollEvents();
		}
	}

	MainWindow::MainWindow()
	{
		std::cout << "Lucy: Hello world!" << std::endl;
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_GLFWwindow = glfwCreateWindow(800, 600, "Lucy", nullptr, nullptr);
	}


	MainWindow::~MainWindow()
	{
		std::cout << "Lucy: Bye!" << std::endl;
		glfwDestroyWindow(m_GLFWwindow);
		glfwTerminate();
	}

}