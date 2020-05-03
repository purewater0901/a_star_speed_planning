cmake_minimum_required(VERSION 3.15)
project(astar_speed_planning)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(astar_lib src/base_node.cpp src/node_util.cpp src/astar_node.cpp src/hastar_node.cpp)

add_executable(astar_speed_planning src/astar_main.cpp)
target_link_libraries(astar_speed_planning astar_lib)

add_executable(hybrid_astar_speed_planning src/hastar_main.cpp)
target_link_libraries(hybrid_astar_speed_planning astar_lib)
