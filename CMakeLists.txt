cmake_minimum_required(VERSION 3.16)
project(PROJECT_NAME)

include_directories(src)
aux_source_directory(src SRC)

add_compile_options(-std=c++2a -g)
add_executable(main ${SRC})