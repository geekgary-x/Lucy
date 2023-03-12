#include <gtest/gtest.h>
#include "Index.h"

TEST(LucyTestVulkan, Instance)
{
	EXPECT_NO_THROW(LucyTest::Vulkan::VulkanInstanceInit());
}


TEST(LucyTestVulkan, GraphicsDevice)
{
	EXPECT_NO_THROW(LucyTest::Vulkan::VulkanGraphicsDeviceInit());
}