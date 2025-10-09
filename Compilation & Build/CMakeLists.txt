# Minimum CMake version required
cmake_minimum_required(VERSION 4.1)

# Project name
project(firstcmakeproject VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(a 
    CompilationProcess.cpp 
    math_utils.cpp
)

#mkdir build
#cd build
#cmake ..
#./Debug/a.exe