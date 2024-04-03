cmake_minimum_required(VERSION 3.22.0)
project(racing_exe)
add_executable(racing_exe main.cpp)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(my_lib SHARED
	"race.h" "race.cpp"
	"earthair.cpp" "earthair.h"
	"boots.h" "boots.cpp"
	"camel.h" "camel.cpp"
	"centaur.h" "centaur.cpp"
	"camel is fast.h" "camel is fast.cpp"
 "broomstick.h" "broomstick.cpp" "magic carpet.cpp" "magic carpet.h" "eagle.h" "eagle.cpp")
target_link_libraries(racing_exe my_lib)