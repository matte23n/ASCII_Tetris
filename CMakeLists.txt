cmake_minimum_required(VERSION 3.26)
project(Ascii_Tetris)

set(CMAKE_CXX_STANDARD 17)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Ascii_Tetris main.cpp
        Board.cpp
        Board.h
        Leaderboard.cpp
        Leaderboard.h
        shapes/Line.cpp
        shapes/Line.h
        shapes/Square.cpp
        shapes/Square.h
        Startup_page.cpp
        Startup_page.h
        Tetramino.cpp
        Tetramino.h
        Game.cpp
        Game.h
        GameInfo.cpp
        GameInfo.h
        shapes/TShape.cpp
        shapes/TShape.h)

target_link_libraries(Ascii_Tetris ${CURSES_LIBRARIES})
