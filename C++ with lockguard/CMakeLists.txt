cmake_minimum_required(VERSION 3.10)


project(philosopher)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)
add_executable(philosopher main.cpp philosopher.cpp)
target_link_libraries(philosopher PRIVATE Threads::Threads)
