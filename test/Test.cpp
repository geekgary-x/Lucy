#include <gtest/gtest.h>
#include "Index.h"

TEST(LucyTestVulkan, VulkanInstanceInit)
{
	EXPECT_NO_THROW(LucyTest::Vulkan::VulkanInstanceInit);
}