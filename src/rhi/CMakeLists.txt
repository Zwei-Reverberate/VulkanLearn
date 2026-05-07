project(Rhi)

file(GLOB_RECURSE GRAPHIC_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(${PROJECT_NAME} STATIC ${GRAPHIC_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

include(${CMAKE_SOURCE_DIR}/cmake/AddVulkan.cmake)
link_vulkan(${PROJECT_NAME})

include(${CMAKE_SOURCE_DIR}/cmake/AddVMA.cmake)
link_vma_to_target(${PROJECT_NAME})