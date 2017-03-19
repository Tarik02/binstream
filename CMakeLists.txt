cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)

add_library(binstream STATIC src/binstream/binstream.cpp)
target_include_directories(binstream
	PRIVATE src
	PUBLIC include)
