cmake_minimum_required(VERSION 3.10)
project(Gobang CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(sfml CONFIG REQUIRED)

add_executable(Gobang src/game.cpp) 

target_link_libraries(Gobang PRIVATE fmt::fmt)