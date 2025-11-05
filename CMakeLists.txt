cmake_minimum_required(VERSION 3.10)
project(Gobang)
set(CMAKE_CXX_STANDARD 17)
find_package(SFML COMPONENTS Graphics Window Audio REQUIRED)
file(GLOB SRCS ./src/*.cpp)
add_executable(Gobang ${SRCS})
target_include_directories(Gobang PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Gobang PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::System
)
