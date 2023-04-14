cmake_minimum_required(VERSION 3.23)
project (TWL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TextureHolder.h TextureHolder.cpp Engine.h Engine.cpp Input.cpp Update.cpp Draw.cpp PlayableCharacter.h PlayableCharacter.cpp Thomas.h Thomas.cpp Bob.h Bob.cpp LevelManager.h LevelManager.cpp LoadLevel.cpp DetectCollisions.cpp SoundManager.h SoundManager.cpp PopulateEmitters.cpp HUD.h HUD.cpp Particle.h Particle.cpp ParticleSystem.h ParticleSystem.cpp)
add_executable(TWL ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(TWL sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
