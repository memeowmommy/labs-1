cmake_minimum_required(VERSION 3.15) 

set(PROJECT_NAME test)				 		 
project("${PROJECT_NAME}")			 	


set(CMAKE_CXX_STANDARD 17)			 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")
include_directories("src/")

add_executable("${PROJECT_NAME}" 6.cpp
                                 inc/fufu.h
                                 src/fufu.cpp)	