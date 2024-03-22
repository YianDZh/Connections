//
// Created by Dave R. Smith on 11/30/23.
//

#ifndef CONNECTION_SQUARE_H
#define CONNECTION_SQUARE_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "Position.h"
#include <iostream>
class Square : public sf::RectangleShape ///I am a rectangleShape
{
private:
    sf::Text text;
    bool clicked= false;
    bool por = false;
public:
    Square();

    ///use the font param to setFont,
    /// text to setString
    /// play around with character size,
    /// center the text
    Square(sf::Font& font, std::string text);
    ///even handler, what do we do when an event occurs
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    ///how do I update myself to be in my current state
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(sf::Vector2f position);
    void invisible ();
    bool lock ();
    void changer ();
    void setClicked(bool option);
    bool getClicked();
    std::string getString();
};


#endif //CONNECTION_SQUARE_H
