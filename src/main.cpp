#include <iostream>
#include "GUIGameWindow.h"
#include "GUIMainMenuWindow.h"
#include "GUIGameState.h"
#include "GUISettings.h"
#include "SFML/Audio.hpp"

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920
#define WINDOW_TITLE "Mini YuGiOh! Game"

int main() {

    GUIGameState *guiGameState = new GUIGameState();
    GameManager *gameManager = new GameManager;
    sf::VideoMode videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::RenderWindow *window = new sf::RenderWindow(videoMode, WINDOW_TITLE, sf::Style::Default);
    window->setFramerateLimit(60);

    GUIGameWindow gameGUI = GUIGameWindow(window, gameManager, guiGameState);

    GUIMainMenuWindow mainMenu = GUIMainMenuWindow(window, guiGameState);

    GUISettings guiSettings(window, guiGameState);

    GUIPauseMenu guiPauseMenu(window, guiGameState);

    sf::Music music;
    music.openFromFile("song.ogg");
    music.setVolume(guiSettings.getVolumeLevel());
    music.play();
    music.setLoop(true);

    while (guiGameState->getGUIGameState() != GuiState::EXIT) {
        while (guiGameState->getGUIGameState() == GuiState::MAIN_MENU) {
            mainMenu.update();
            mainMenu.display();
        }

        while (guiGameState->getGUIGameState() == GuiState::GAME) {
            gameGUI.update();
            gameGUI.display();
            while (guiGameState->getGUIGameState() == GuiState::PAUSE_MENU) {
                guiPauseMenu.update();
                guiPauseMenu.display();
                while (guiGameState->getGUIGameState() == GuiState::SETTINGS) {
                    guiSettings.update();
                    guiSettings.display();
                    music.setVolume(guiSettings.getVolumeLevel());
                }
            }
        }

        while (guiGameState->getGUIGameState() == GuiState::SETTINGS) {
            guiSettings.update();
            guiSettings.display();
            music.setVolume(guiSettings.getVolumeLevel());

        }
        gameManager->restartTheGame();
    }
    window->close();

    return 0;
}
