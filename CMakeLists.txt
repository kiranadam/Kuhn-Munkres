cmake_minimum_required(VERSION 2.8) 
project(Hungarian)
#find_package(OpenCV REQUIRED)
set(NAME_SRC
    src/hungarian.cpp
    src/test.cpp
)

set(NAME_HEADERS       
    include/hungarian.hpp
)

# add a compiler flag for the C++2011 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 ")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_directories(${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable(hungarian ${NAME_SRC} ${NAME_HEADERS})

target_link_libraries(Hungarian)
