cmake_minimum_required(VERSION 3.23)
project(PongLabs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Paddle.h Paddle.cpp Ball.h Ball.cpp PowerUp.h PowerUp.cpp)
add_executable(PongLabs ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(PongLabs sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
