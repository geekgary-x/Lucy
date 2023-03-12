#include <Lucy/Vulkan/VulkanDevice.h>
namespace LucyTest
{
	namespace Vulkan
	{
		int VulkanGraphicsDeviceInit()
		{
			auto vkGraphicsDevice = Lucy::Singleton<Lucy::GraphicsDevice>::getInstance();
			return vkGraphicsDevice != nullptr;
		}
	}
}