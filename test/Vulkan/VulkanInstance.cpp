#include <Lucy/Vulkan/VulkanInstance.h>
namespace LucyTest
{
	namespace Vulkan
	{
		int VulkanInstanceInit()
		{
			auto vulkanInstance = Lucy::Singleton<Lucy::VulkanInstance>::getInstance();
			return vulkanInstance != nullptr;
		}
	}
}