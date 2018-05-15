set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-T${CMAKE_CURRENT_SOURCE_DIR}/linker.ld")

add_executable(kernel.bin boot.S init.c test_lambda.cpp)

target_link_libraries(kernel.bin PUBLIC video)

set_target_properties(kernel.bin PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld)
set_target_properties(kernel.bin PROPERTIES CXX_STANDARD 17)
