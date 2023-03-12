#include "MainWindow.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <Lucy/Vulkan/VulkanInstance.h>
#include <Lucy/Vulkan/utils/utils-raii.hpp>	
namespace Lucy
{
	void MainWindow::loop()
	{
		while (!glfwWindowShouldClose(m_surface->window.handle))
		{
			glfwPollEvents();
		}
	}

	MainWindow::MainWindow()
	{
		std::cout << "Lucy: Hello world!" << std::endl;
		auto&& vkInstance = Singleton<VulkanInstance>::getInstance();
		m_surface = boost::make_shared<vk::raii::su::SurfaceData>(*vkInstance->m_RAIIInstance, "Lucy", vk::Extent2D(800, 720));
	}


	MainWindow::~MainWindow()
	{
		std::cout << "Lucy: Bye!" << std::endl;
	}

}