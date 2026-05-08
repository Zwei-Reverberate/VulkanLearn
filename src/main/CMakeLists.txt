project(Main)

file(GLOB_RECURSE GRAPHIC_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME}  ${GRAPHIC_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PUBLIC ZWindow)

target_link_libraries(${PROJECT_NAME} PUBLIC Rhi)