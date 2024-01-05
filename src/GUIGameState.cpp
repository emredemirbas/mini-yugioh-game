//
// Created by Esat on 28.12.2023.
//

#include "GUIGameState.h"

GUIGameState::GUIGameState() {
    guiGameState = GuiState::MAIN_MENU;
}

GUIGameState::~GUIGameState() {

}

GuiState GUIGameState::getGUIGameState() {
    return guiGameState;
}

GuiState GUIGameState::getPreviousState(){
    return previousState;
}

void GUIGameState::setGUIGameState(GuiState state) {
    previousState = guiGameState;
    guiGameState = state;
}