cmake_minimum_required(VERSION 3.23)
project(2023_data_struct)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

include_directories(
    list/out
)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(list)
target_link_libraries(${PROJECT_NAME} list)