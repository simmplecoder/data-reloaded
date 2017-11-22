cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_library(entity include/entity.hpp src/entity.cpp)
target_include_directories(entity PUBLIC include)

add_library(id_generator include/id_generator.hpp src/id_generator.cpp)

set(SOURCE_FILES main.cpp include/algorithms.hpp include/random_selector.hpp include/random_int_generator.hpp)
add_executable(lab_generation ${SOURCE_FILES})
target_link_libraries(lab_generation entity id_generator)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/labs.txt ${CMAKE_CURRENT_BINARY_DIR}/labs.txt)