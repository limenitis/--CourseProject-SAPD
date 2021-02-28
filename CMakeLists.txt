cmake_minimum_required(VERSION 3.0)

project(CourseProjectSAPD-cmake VERSION 0.0.0.0)

aux_source_directory(src SOURCES)
add_executable(main ${SOURCES})

include_directories(include)

