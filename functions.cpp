//
// Created by Dave R. Smith on 11/30/23.
//


#include "functions.h"

namespace Moveable
{
    void bounce(sf::Shape& shape, sf::Vector2u winSize, sf::Vector2f& velocity)
    {
        ///when shape reaches the left side or the right side
        if(shape.getPosition().x <= 0 ||
           shape.getPosition().x + shape.getGlobalBounds().width >= winSize.x)
            velocity.x *= -1;
        ///when shape reaches the top or the bottom
        if(shape.getPosition().y <= 0 ||
           shape.getPosition().y + shape.getGlobalBounds().height >= winSize.y)
            velocity.y *= -1;

        shape.move(velocity);
    }
}

