include_guard(GLOBAL)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)
message(STATUS "Found Qt${QT_VERSION_MAJOR} (Core, Gui, Widgets) - ready to link")

function(link_qt_to_target TARGET_NAME)
    if(NOT TARGET ${TARGET_NAME})
        message(FATAL_ERROR "Cannot link Qt: target '${TARGET_NAME}' does not exist.")
    endif()

    set_target_properties(${TARGET_NAME} PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
    )

    target_link_libraries(${TARGET_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
    )

    if(WIN32)
        set_target_properties(${TARGET_NAME} PROPERTIES
            WIN32_EXECUTABLE ON
        )
    endif()
endfunction()