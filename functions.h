//
// Created by Dave R. Smith on 11/30/23.
//

#ifndef CONNECTION_FUNCTIONS_H
#define CONNECTION_FUNCTIONS_H
#include <SFML/Graphics.hpp>

namespace Moveable
{
    void bounce(sf::Shape& shape, sf::Vector2u winSize, sf::Vector2f& velocity);
    void getAway();
}



#endif //CONNECTION_FUNCTIONS_H
