cmake_minimum_required(VERSION 3.4)
project(AlgoSpeedTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(AlgoSpeedTest ${SOURCES})