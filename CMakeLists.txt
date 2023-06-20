cmake_minimum_required(VERSION 2.10)

project(csetting)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(csetting SHARED "setting.c")

add_executable(csetting_example "test.cc")

target_link_libraries(csetting_example csetting)