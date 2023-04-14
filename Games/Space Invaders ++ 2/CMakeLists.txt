cmake_minimum_required(VERSION 3.23)
project(Space_Invaders____2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        BitmapStore.cpp
        BitmapStore.h
        BlueprintObjectParser.cpp
        BlueprintObjectParser.h
        BulletSpawner.cpp
        BulletSpawner.h
        BulletUpdateComponent.cpp
        BulletUpdateComponent.h
        Button.cpp
        Button.h
        ColliderComponent.cpp
        ColliderComponent.h
        Component.cpp
        Component.h
        DevelopState.h
        GameEngine.cpp
        GameEngine.h
        GameInputHandler.cpp
        GameInputHandler.h
        GameObject.cpp
        GameObject.h
        GameObjectBlueprint.cpp
        GameObjectBlueprint.h
        GameObjectFactoryPlayMode.cpp
        GameObjectFactoryPlayMode.h
        GameObjectSharer.h
        GameOverInputHandler.cpp
        GameOverInputHandler.h
        GameOverUIPanel.cpp
        GameOverUIPanel.h
        GameScreen.cpp
        GameScreen.h
        GameUIPanel.cpp
        GameUIPanel.h
        GraphicsComponent.cpp
        GraphicsComponent.h
        InputHandler.cpp
        InputHandler.h
        InvaderUpdateComponent.cpp
        InvaderUpdateComponent.h
        LevelManager.cpp
        LevelManager.h
        ObjectTags.cpp
        ObjectTags.h
        PhysicsEnginePlayMode.cpp
        PhysicsEnginePlayMode.h
        PlayerUpdateComponent.cpp
        PlayerUpdateComponent.h
        PlayModeObjectLoader.cpp
        PlayModeObjectLoader.h
        RectColliderComponent.cpp
        RectColliderComponent.h
        Screen.cpp
        Screen.h
        ScreenManager.cpp
        ScreenManager.h
        ScreenManagerRemoteControl.cpp
        ScreenManagerRemoteControl.h
        SelectInputHandler.cpp
        SelectInputHandler.h
        SelectScreen.cpp
        SelectScreen.h
        SelectUIPanel.cpp
        SelectUIPanel.h
        SoundEngine.cpp
        SoundEngine.h
        "Space Invaders ++.cpp"
        StandardGraphicsComponent.cpp
        StandardGraphicsComponent.h
        TransformComponent.cpp
        TransformComponent.h
        UIPanel.cpp
        UIPanel.h
        UpdateComponent.cpp
        UpdateComponent.h
        WorldState.h ShieldUpdateComponent.h ShieldUpdateComponent.cpp UfoUpdateComponent.h UfoUpdateComponent.cpp)
add_executable(Space_Invaders____2 ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Space_Invaders____2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
