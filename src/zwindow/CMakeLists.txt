project(ZWindow)

file(GLOB_RECURSE ZWINDOW_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(${PROJECT_NAME} STATIC ${ZWINDOW_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

include(${CMAKE_SOURCE_DIR}/cmake/AddQt.cmake)
link_qt_to_target(${PROJECT_NAME})