#ifndef MINIYUGIOHGUI_GUICARDINFOPANEL_H
#define MINIYUGIOHGUI_GUICARDINFOPANEL_H

#include "GUIWindowElement.h"
#include "SFML/Graphics.hpp"
#include <string>

/**
 * @class GUICardInfoPanel
 * @brief A class that represents the GUI Card Info Panel.
 * @details This class inherits from GUIWindowElement and provides functionalities to display card information.
 */
class GUICardInfoPanel : public GUIWindowElement {
private:
    sf::Texture *cardImage; ///< Texture object to hold the card image.
    std::string cardDescription; ///< String to hold the card description.
    sf::Font font; ///< Font object for text rendering.
    sf::RectangleShape background; ///< RectangleShape object for the background.

public:
    /**
     * @brief Default constructor.
     */
    GUICardInfoPanel();

    /**
     * @brief Constructor with parameters.
     * @param x The x-coordinate of the panel.
     * @param y The y-coordinate of the panel.
     */
    GUICardInfoPanel(float x, float y);

    /**
     * @brief Destructor.
     */
    ~GUICardInfoPanel();

    /**
     * @brief Sets the card image.
     * @param image Pointer to the Texture object.
     */
    void setCardImage(sf::Texture *image);

    /**
     * @brief Sets the card description.
     * @param description The card description.
     */
    void setCardDescription(std::string description);

    /**
     * @brief Creates a Text object.
     * @param text The string to be displayed.
     * @return The created Text object.
     */
    sf::Text createText(std::string text);

    /**
     * @brief Draws the panel on the window.
     * @param window Pointer to the RenderWindow object.
     */
    virtual void draw(sf::RenderWindow *window) override;
};

#endif //MINIYUGIOHGUI_GUICARDINFOPANEL_H
