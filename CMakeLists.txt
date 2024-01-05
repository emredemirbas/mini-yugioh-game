cmake_minimum_required(VERSION 3.26)
project(MiniYuGiOhGame)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")

set(SOURCES
        src/main.cpp
        src/Card.cpp
        src/Player.cpp
        src/Deck.cpp
        src/MonsterCard.cpp
        src/PlayingField.cpp
        src/SpellCard.cpp
        src/TrapCard.cpp
        src/YugiMuto.cpp
        src/SetoKaiba.cpp
        src/GUIGameWindow.cpp
        src/GUIPlayerPanel.cpp
        src/GUILifeBar.cpp
        src/GUIHand.cpp
        src/GUIPlayingField.cpp
        src/GUIGraveyard.cpp
        src/GUIWindow.cpp
        src/GUIWindowElement.cpp
        src/GUICardInfoPanel.cpp
        src/GUIMainMenuWindow.cpp
        src/GameManager.cpp
        src/GUIPhaseText.cpp
        src/GUIGameState.cpp
        src/GUIPauseMenu.cpp
        src/GUISettings.cpp
)

set(HEADERS
        include/Card.h
        include/Player.h
        include/Deck.h
        include/MonsterCard.h
        include/SpellCard.h
        include/PlayingField.h
        include/TrapCard.h
        include/YugiMuto.h
        include/SetoKaiba.h
        include/GUIGameWindow.h
        include/GUIPlayerPanel.h
        include/GUILifeBar.h
        include/GUIHand.h
        include/GUIPlayingField.h
        include/GUIGraveyard.h
        include/GUIWindow.h
        include/GUIWindowElement.h
        include/GUICardInfoPanel.h
        include/GUIMainMenuWindow.h
        include/GameManager.h
        include/GUIPhaseText.h
        include/GUIGameState.h
        include/GUIPauseMenu.h
        include/GUISettings.h
)

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(MiniYuGiOhGame ${SOURCES} ${HEADERS})

target_include_directories(MiniYuGiOhGame PRIVATE include src textures)
target_link_libraries(MiniYuGiOhGame sfml-graphics sfml-audio -static-libgcc -static-libstdc++)