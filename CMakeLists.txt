cmake_minimum_required(VERSION 3.29)
project(go_with_the_flow_Ryan_B_Runo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(go_with_the_flow_Ryan_B_Runo
        HeatFlow.cpp
        HeatFlow.h
        main.cpp)
