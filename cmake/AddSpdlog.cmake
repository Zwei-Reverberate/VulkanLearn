include_guard(GLOBAL)

if(NOT DEFINED SPDLOG_SOURCE_DIR)
    set(SPDLOG_SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/spdlog" CACHE PATH "Path to spdlog source directory")
endif()

if(NOT EXISTS "${SPDLOG_SOURCE_DIR}/include/spdlog/spdlog.h")
    message(FATAL_ERROR "spdlog source not found at ${SPDLOG_SOURCE_DIR}! Please clone it into external/spdlog.")
endif()

if(NOT TARGET spdlog::spdlog)
    set(SPDLOG_MASTER_PROJECT OFF CACHE BOOL "" FORCE)
    set(SPDLOG_COMPILED_LIB OFF CACHE BOOL "" FORCE)
    
    add_subdirectory(${SPDLOG_SOURCE_DIR} ${CMAKE_BINARY_DIR}/spdlog EXCLUDE_FROM_ALL)

    if(NOT TARGET spdlog::spdlog_header_only)
        message(FATAL_ERROR "Target spdlog::spdlog_header_only not found after add_subdirectory. Check spdlog's CMakeLists.txt.")
    endif()
    if(NOT TARGET spdlog::spdlog)
        add_library(spdlog::spdlog ALIAS spdlog::spdlog_header_only)
    endif()

    message(STATUS "spdlog configured successfully from: ${SPDLOG_SOURCE_DIR}")
endif()

function(link_spdlog_to_target TARGET_NAME)
    if(NOT TARGET ${TARGET_NAME})
        message(FATAL_ERROR "Cannot link spdlog: target '${TARGET_NAME}' does not exist.")
    endif()
    target_link_libraries(${TARGET_NAME} PUBLIC spdlog::spdlog_header_only)
endfunction()