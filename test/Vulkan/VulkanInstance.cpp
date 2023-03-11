#include <Lucy/Vulkan/VulkanInstance.h>
namespace LucyTest
{
	namespace Vulkan
	{
		int VulkanInstanceInit()
		{
			auto vulkanInstance = Lucy::VulkanInstance::Create();
			return vulkanInstance != nullptr;
		}
	}
}