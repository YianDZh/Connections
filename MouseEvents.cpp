//
// Created by Dave R. Smith on 11/30/23.
//

#include "MouseEvents.h"

bool MouseEvents::isClicked(sf::Shape& shape, sf::RenderWindow& window)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    return shape.getGlobalBounds().contains(mpos) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left);
}