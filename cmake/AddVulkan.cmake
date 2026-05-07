include_guard(GLOBAL)
find_package(Vulkan REQUIRED)

if(NOT TARGET Vulkan::Vulkan)
    message(FATAL_ERROR "Vulkan::Vulkan target not found. "
                        "A compatible version of CMake (>=3.7) is required.")
endif()

function(link_vulkan TARGET_NAME)
    if(NOT TARGET ${TARGET_NAME})
        message(FATAL_ERROR "link_vulkan: Target '${TARGET_NAME}' does not exist. "
                            "Please create the target before calling link_vulkan().")
    endif()

    target_link_libraries(${TARGET_NAME} PUBLIC Vulkan::Vulkan)
    message(VERBOSE "Vulkan linked to target '${TARGET_NAME}' "
                    "(include: ${Vulkan_INCLUDE_DIRS})")
endfunction()