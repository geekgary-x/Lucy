#include "VulkanInstance.h"
#include <Lucy/Vulkan/utils/utils-raii.hpp>
namespace Lucy
{
    VulkanInstance::VulkanInstance()
	{
        // the very beginning: instantiate a context
        m_RAIIContext = boost::make_shared<vk::raii::Context>();

        // initialize the vk::ApplicationInfo structure
        vk::ApplicationInfo applicationInfo("Lucy", 1, "LucyRenderer", 1, VK_API_VERSION_1_1);

        // initialize the vk::InstanceCreateInfo
        vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);
        auto extensions = getRequiredExtensions();
        instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        instanceCreateInfo.ppEnabledExtensionNames = extensions.data();
        for (size_t i = 0; i < extensions.size(); i++)
        {
            std::cout << extensions[i] << std::endl;
        }
        // create an Instance
        m_RAIIInstance = boost::make_shared<vk::raii::Instance>(*m_RAIIContext, instanceCreateInfo);
	}

    std::vector<const char*> VulkanInstance::getRequiredExtensions()
    {
        glfwInit();
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        return extensions;
    }
}