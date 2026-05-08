#include <vulkan/vulkandevice.h>
#include <base/constdefines.h>

void rhi::vk::VulkanDevice::initVulkan()
{
	createInstance();
}

void rhi::vk::VulkanDevice::createInstance()
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = APP_NAME;
	appInfo.pEngineName = APP_NAME;
	appInfo.apiVersion = VK_API_VERSION_1_3;
	appInfo.applicationVersion = VK_MAKE_API_VERSION(0, APP_MAJOR_VERSION, APP_MINOR_VERSION, APP_PATCH_VERSION);
	appInfo.engineVersion = appInfo.applicationVersion;
}