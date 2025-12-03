cmake_minimum_required(VERSION 3.10)

project(TwixT)
include_directories(${CMAKE_SOURCE_DIR})

set(SOURCES

main.c
grid.c
io_utils.c
grid_logic.c
links.c
win_logic.c

)

add_executable(twikc ${SOURCES})
