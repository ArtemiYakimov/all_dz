cmake_minimum_required(VERSION 3.22.0)
project(ConsoleApplication1)

add_executable(ConsoleApplication1 ConsoleApplication1.cpp)

add_subdirectory(libpqxx-7.7.4)

target_compile_features(ConsoleApplication1 PRIVATE cxx_std_17)

target_link_libraries(ConsoleApplication1 PRIVATE pqxx)