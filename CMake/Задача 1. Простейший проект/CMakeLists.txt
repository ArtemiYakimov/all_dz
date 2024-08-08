cmake_minimum_required(VERSION 3.22.0)
project(my_first_cmake_project)
add_executable(my_first_cmake_project my_first_cmake_program.cpp)

add_subdirectory(C:\libpqxx-master)

target_compile_features(MyProject1 PRIVATE cxx_std_17)

target_link_libraries(MyProject1 pqxx)