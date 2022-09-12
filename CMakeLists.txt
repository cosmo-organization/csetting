cmake_minimum_required(VERSION 2.10)

project(csetting)

add_library(csetting SHARED "setting.c")

add_executable(csetting_example "test.c")

target_link_libraries(csetting_example csetting)