cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_library(entity include/entity.hpp src/entity.cpp)
target_include_directories(entity PUBLIC include)

set(SOURCE_FILES main.cpp)
add_executable(lab_generation ${SOURCE_FILES})
target_link_libraries(lab_generation entity)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/labs.txt ${CMAKE_CURRENT_BINARY_DIR}/labs.txt)