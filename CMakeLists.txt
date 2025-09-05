cmake_minimum_required(VERSION 3.10)
project(MyProgram LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)



add_executable(main main.cpp)


add_executable(main02 main02.cpp List.cpp)


add_executable(main03 main03.cpp TList.cpp)