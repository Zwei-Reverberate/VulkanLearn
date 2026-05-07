include_guard(GLOBAL)

if(NOT TARGET Vulkan::Vulkan)
    message(FATAL_ERROR
        "Vulkan::Vulkan target not found. "
        "Please include AddVulkan.cmake (or call find_package(Vulkan)) before AddVMA.cmake."
    )
endif()

if(NOT DEFINED VMA_SOURCE_DIR)
    set(VMA_SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/vma" CACHE PATH
        "Path to VMA source directory")
endif()

if(NOT EXISTS "${VMA_SOURCE_DIR}/include/vk_mem_alloc.h")
    message(FATAL_ERROR
        "VMA source not found at ${VMA_SOURCE_DIR}! "
        "Please ensure the source tree is present (clone VMA into external/vma).")
endif()

if(NOT TARGET vma::vma)
    set(VMA_IMPL_FILE "${VMA_SOURCE_DIR}/src/VmaUsage.cpp")
    if(NOT EXISTS "${VMA_IMPL_FILE}")
        message(FATAL_ERROR
            "VmaUsage.cpp not found in ${VMA_SOURCE_DIR}/src/. "
            "Please check your VMA source tree.")
    endif()

    add_library(vma_obj STATIC "${VMA_IMPL_FILE}")
    target_include_directories(vma_obj PUBLIC "${VMA_SOURCE_DIR}/include")
    target_include_directories(vma_obj PRIVATE "${VMA_SOURCE_DIR}/src")

    target_link_libraries(vma_obj PRIVATE Vulkan::Vulkan)

    target_compile_definitions(vma_obj PRIVATE
        VMA_STATIC_VULKAN_FUNCTIONS=1
        $<$<CONFIG:Debug>:VMA_DEBUG_INITIALIZE_ALLOCATIONS=1>
        $<$<CONFIG:Debug>:VMA_DEBUG_MARGIN=16>
        $<$<CONFIG:Debug>:VMA_DEBUG_DETECT_CORRUPTION=1>
    )

    add_library(vma::vma ALIAS vma_obj)
    message(STATUS "VMA configured (using official VmaUsage.cpp) from: ${VMA_SOURCE_DIR}")
endif()

function(link_vma_to_target TARGET_NAME)
    if(NOT TARGET ${TARGET_NAME})
        message(FATAL_ERROR "Cannot link VMA: target '${TARGET_NAME}' does not exist.")
    endif()
    target_link_libraries(${TARGET_NAME} PUBLIC vma::vma)
endfunction()