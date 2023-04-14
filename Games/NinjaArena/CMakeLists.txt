cmake_minimum_required(VERSION 3.23)
project(NinjaArena)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Player.h Player.cpp NinjaArena.h CreateBackground.cpp TextureHolder.h TextureHolder.cpp Enemy.h Enemy.cpp CreateHorde.cpp Bullet.h Bullet.cpp Pickup.h Pickup.cpp EnemyPickup.h EnemyPickup.cpp)
add_executable(NinjaArena ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(NinjaArena sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
