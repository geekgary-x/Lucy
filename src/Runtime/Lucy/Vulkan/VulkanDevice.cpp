#include "VulkanDevice.h"
#include <Lucy/Vulkan/utils/utils-raii.hpp>
#include <Lucy/Vulkan/VulkanInstance.h>
#include <boost/assert.hpp>
#include <boost/limits.hpp>
namespace Lucy
{
	GraphicsDevice::GraphicsDevice()
	{
		auto vkInstance = ::Lucy::Singleton<VulkanInstance>::getInstance();
		auto physicalDevices = vk::raii::PhysicalDevices(*vkInstance->m_RAIIInstance);
		int graphicsPyhsicalDeviceIndex = INT_MAX;
		for (size_t i = 0; i < physicalDevices.size(); i++)
		{
			auto&& pd = physicalDevices[i];
			// find the index of the first queue family that supports graphics
			uint32_t graphicsQueueFamilyIndex = vk::su::findGraphicsQueueFamilyIndex(pd.getQueueFamilyProperties());
			if (graphicsQueueFamilyIndex != pd.getQueueFamilyProperties().size())
			{
				graphicsPyhsicalDeviceIndex = i;
				break;
			}
		}

		BOOST_ASSERT_MSG(graphicsPyhsicalDeviceIndex != INT_MAX, "Not find graphics pyhsical device!");

		auto graphicsPyhsicalDevice = physicalDevices[graphicsPyhsicalDeviceIndex];

		// find the index of the first queue family that supports graphics
		uint32_t graphicsQueueFamilyIndex = vk::su::findGraphicsQueueFamilyIndex(graphicsPyhsicalDevice.getQueueFamilyProperties());
		// create a Device
		float                     queuePriority = 0.0f;
		vk::DeviceQueueCreateInfo deviceQueueCreateInfo({}, graphicsQueueFamilyIndex, 1, &queuePriority);
		vk::DeviceCreateInfo      deviceCreateInfo({}, deviceQueueCreateInfo);
		m_RAIIDevice = boost::make_shared<vk::raii::Device>(graphicsPyhsicalDevice, deviceCreateInfo);
	}
}