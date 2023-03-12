#pragma once
#include <stdint.h>
#include <Lucy/Core/Singleton.hpp>
namespace vk::raii
{
	class Instance;
	class Context;
}

namespace Lucy
{
	class Mainwindow;
	class VulkanInstance : public Singleton<VulkanInstance>
	{
	public:
		friend boost::shared_ptr<VulkanInstance> boost::make_shared<VulkanInstance>();
		friend class MainWindow;
	public:
		VulkanInstance();
		std::vector<const char*> getRequiredExtensions();
	private:
		boost::shared_ptr<vk::raii::Instance> m_RAIIInstance;
		boost::shared_ptr<vk::raii::Context> m_RAIIContext;
	};
}