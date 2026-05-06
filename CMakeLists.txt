cmake_minimum_required(VERSION 3.21)
project(VulkanLearn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(src/main)
add_subdirectory(src/zwindow)
add_subdirectory(src/rhi)
add_subdirectory(src/render)