#pragma once
#include <Lucy/Core/Singleton.hpp>

namespace vk
{
	namespace raii
	{
		struct Device;
	}

}

namespace Lucy
{
	class GraphicsDevice : public Singleton<GraphicsDevice>
	{
	public:
		friend boost::shared_ptr<GraphicsDevice> boost::make_shared<GraphicsDevice>();
	public:
		boost::shared_ptr<vk::raii::Device> m_RAIIDevice;
	private:
		GraphicsDevice();
	};
}