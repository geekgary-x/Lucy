#include "VulkanInstance.h"
#include <Lucy/Vulkan/utils/utils-raii.hpp>
namespace Lucy
{
    boost::shared_ptr<VulkanInstance> VulkanInstance::Create()
    {
        return boost::make_shared<VulkanInstance>();
    }
    VulkanInstance::VulkanInstance()
	{
        // the very beginning: instantiate a context
        m_RAIIContext = boost::make_shared<vk::raii::Context>();

        // initialize the vk::ApplicationInfo structure
        vk::ApplicationInfo applicationInfo("Lucy", 1, "LucyRenderer", 1, VK_API_VERSION_1_1);

        // initialize the vk::InstanceCreateInfo
        vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);

        // create an Instance
        m_RAIIInstance = boost::make_shared<vk::raii::Instance>(*m_RAIIContext, instanceCreateInfo);
	}
}