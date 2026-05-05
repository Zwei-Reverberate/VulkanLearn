include_guard(GLOBAL)

if(NOT DEFINED GLM_SOURCE_DIR)
    set(GLM_SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/glm" CACHE PATH
        "Path to GLM source directory")
endif()

if(NOT EXISTS "${GLM_SOURCE_DIR}/glm/glm.hpp")
    message(FATAL_ERROR
        "GLM source not found at ${GLM_SOURCE_DIR}! "
        "Please ensure the source tree is present (clone GLM into external/glm).")
endif()

if(NOT TARGET glm::glm)
    add_library(glm INTERFACE IMPORTED)
    target_include_directories(glm INTERFACE "${GLM_SOURCE_DIR}")
    add_library(glm::glm ALIAS glm)
    message(STATUS "GLM configured from: ${GLM_SOURCE_DIR}")
endif()

function(link_glm_to_target TARGET_NAME)
    if(NOT TARGET ${TARGET_NAME})
        message(FATAL_ERROR "Cannot link GLM: target '${TARGET_NAME}' does not exist.")
    endif()
    target_link_libraries(${TARGET_NAME} PUBLIC glm::glm)
endfunction()