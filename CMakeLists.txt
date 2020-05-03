cmake_minimum_required(VERSION 3.15)
project(astar_speed_planning)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(astar_speed_planning src/astar_main.cpp src/node.cpp src/node_util.cpp)
add_executable(hybrid_astar_speed_planning src/hastar_main.cpp src/base_node.cpp src/hastar_node.cpp src/node_util.cpp)
