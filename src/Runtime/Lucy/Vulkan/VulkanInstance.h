#pragma once
#include <stdint.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
namespace Lucy
{
	class VulkanInstance
	{
	public:
		friend boost::shared_ptr<VulkanInstance> boost::make_shared<VulkanInstance>();
	public:
		static boost::shared_ptr<VulkanInstance> Create();
	private:
		VulkanInstance();
	};
}