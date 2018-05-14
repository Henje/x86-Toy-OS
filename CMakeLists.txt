cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(TestOS VERSION 0.1 LANGUAGES ASM C CXX)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-T${CMAKE_SOURCE_DIR}/src/linker.ld")

add_subdirectory(lib)

add_executable(kernel.bin src/boot.S src/init.c src/test_lambda.cpp)
set_target_properties(kernel.bin PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/src/linker.ld)
set_target_properties(kernel.bin PROPERTIES CXX_STANDARD 17)
target_link_libraries(kernel.bin PUBLIC video)
