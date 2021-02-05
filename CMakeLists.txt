# Get the problem name from the current directory
get_filename_component(problem ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required (VERSION 3.5)

# Name the project after the problem
project(${problem} CXX)

# Add all cpp and h files
file(GLOB SRC_FILES
    "*.h"
    "*.cpp"
)

add_library(keyval STATIC include/keyval.cpp include/)
target_include_directories(keyval PUBLIC ${include})
target_compile_features(keyval PUBLIC cxx_std_17)

# Enable C++17 features on gcc/clang
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++17 --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_STANDARD 17)
endif()

set(CMAKE_BUILD_TYPE Debug)

add_executable(${problem} ${SRC_FILES})
target_link_libraries(${problem} PUBLIC keyval)
