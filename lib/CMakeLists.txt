add_library(video video.cpp)
target_include_directories(video PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(video PROPERTIES CXX_STANDARD 17)
