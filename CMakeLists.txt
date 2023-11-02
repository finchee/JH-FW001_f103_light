cmake_minimum_required(VERSION 3.20)

project("JH-FW001_f103_light" C CXX ASM)

include(cmake/st-project.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties(${PROJECT_NAME})