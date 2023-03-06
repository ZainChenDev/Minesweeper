cmake_minimum_required(VERSION 3.23)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Programs/Qt/6.2.4/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Concurrent
        REQUIRED)

add_executable(
        Minesweeper WIN32
        main.cpp
        sources/main_window.cpp
        sources/headers/main_window.h
        sources/main_window.ui
        res.qrc
        sources/block_board.cpp
        sources/headers/block_board.h
        sources/block_board.ui
        sources/block.cpp
        sources/headers/block.h
        sources/block.ui
        sources/headers/const.h
        sources/top_board.cpp
        sources/headers/top_board.h
        sources/top_board.ui
        sources/bottom_board.cpp
        sources/headers/bottom_board.h
        sources/bottom_board.ui
        sources/top_board.cpp
        sources/headers/top_board.h
        sources/top_board.ui
        sources/bottom_board.cpp
        sources/headers/bottom_board.h
        sources/bottom_board.ui
        sources/game_over_dialog.cpp
        sources/headers/game_over_dialog.h
        sources/game_over_dialog.ui
        sources/custom_dialog.cpp
        sources/headers/custom_dialog.h
        sources/custom_dialog.ui
        sources/about_dialog.cpp
        sources/headers/about_dialog.h
        sources/about_dialog.ui
        logo.rc)

target_link_libraries(Minesweeper
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Concurrent
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()