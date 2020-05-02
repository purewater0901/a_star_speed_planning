cmake_minimum_required(VERSION 3.15)
project(astar_speed_planning)

set(CMAKE_CXX_STANDARD 14)

add_executable(astar_speed_planning main.cpp node.cpp node.h node_util.cpp node_util.h)