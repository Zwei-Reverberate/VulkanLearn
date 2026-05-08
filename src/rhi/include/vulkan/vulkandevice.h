#pragma once
#include <base/device.h>
#include <vulkan/vulkan.h>
#include <vk_mem_alloc.h>
#include <vector>

namespace rhi::vk
{
	class VulkanDevice final : public rhi::Device
	{

	private:
		void initVulkan();

		void createInstance();

	private:
		VkInstance m_instance;
	};
}