cmake_minimum_required(VERSION 3.1...3.16)

project(kvstore VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_executable("$(PROJECT_NAME)" kvstore_server.cpp)

