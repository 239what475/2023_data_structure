cmake_minimum_required(VERSION 3.23)
project(stack)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

aux_source_directory(src SRC)

add_library(${PROJECT_NAME} ${SRC})
