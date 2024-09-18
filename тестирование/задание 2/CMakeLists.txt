cmake_minimum_required(VERSION 3.10)

project(TaskTwo)

add_subdirectory(catch2-devel)

add_executable(${PROJECT_NAME} ConsoleApplication2.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)