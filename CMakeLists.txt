cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(TestOS VERSION 0.1 LANGUAGES ASM C CXX)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(boot)
