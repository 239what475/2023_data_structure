cmake_minimum_required(VERSION 3.23)
project(practice)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

include_directories(
    list/include
    stack/include
    queue/include
    practice/include
)

aux_source_directory(practice_2_2 PRACTICE_2_2)
aux_source_directory(practice_2_3 PRACTICE_2_3)

set(CHAPTER_2 ${PRACTICE_2_2} ${PRACTICE_2_3})

aux_source_directory(practice_3_1 PRACTICE_3_1)
aux_source_directory(practice_3_2 PRACTICE_3_2)
aux_source_directory(practice_3_3 PRACTICE_3_3)

set(CHAPTER_3 ${PRACTICE_3_1} ${PRACTICE_3_2} ${PRACTICE_3_3})

add_library(${PROJECT_NAME} ${CHAPTER_2} ${CHAPTER_3})

add_subdirectory(${CMAKE_SOURCE_DIR}/list ${CMAKE_BINARY_DIR}/list)
target_link_libraries(${PROJECT_NAME} list)

add_subdirectory(${CMAKE_SOURCE_DIR}/stack ${CMAKE_BINARY_DIR}/stack)
target_link_libraries(${PROJECT_NAME} stack)

add_subdirectory(${CMAKE_SOURCE_DIR}/queue ${CMAKE_BINARY_DIR}/queue)
target_link_libraries(${PROJECT_NAME} queue)