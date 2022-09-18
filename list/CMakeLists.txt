cmake_minimum_required(VERSION 3.23)
project(list)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/out ${CMAKE_CURRENT_SOURCE_DIR}/base_list
  ${CMAKE_CURRENT_SOURCE_DIR}/sequence_list
  ${CMAKE_CURRENT_SOURCE_DIR}/linked_list)

aux_source_directory(src/data_struct_test DATA_STRUCT_TEST)
aux_source_directory(src/practice_2_2 PRACTICE_2_2)
aux_source_directory(src/practice_2_3 PRACTICE_2_3)

add_library(${PROJECT_NAME} ${PRACTICE_2_2} ${PRACTICE_2_3} ${DATA_STRUCT_TEST})
