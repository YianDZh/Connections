//
// Created by Dave R. Smith on 11/30/23.
//

#ifndef CONNECTION_POSITION_H
#define CONNECTION_POSITION_H
#include <SFML/Graphics.hpp>
#include <cmath>
namespace Position
{
    void centerText(const sf::Shape &obj, sf::Text &text);
    /// position obj to the left of constObj
    void left(const sf::Shape& constObj, sf::Shape& obj, float spacing = 0);
    /// position obj to the right of constObj
    void right(const sf::Shape& constObj, sf::Shape& obj, float spacing = 0);
    /// position obj to the top of constObj
    void top(const sf::Shape& constObj, sf::Shape& obj, float spacing = 0);
    /// position obj to the bottom of constObj
    void bottom(const sf::Shape& constObj, sf::Shape& obj, float spacing = 0);
    /// position obj to the bottom of constObj
    void center(const sf::Shape& constObj, sf::Shape& obj);

    sf::Vector2f rightTopCorner(sf::FloatRect floatRect);
    sf::Vector2f bottomRightCorner(sf::FloatRect floatRect);
    sf::Vector2f centerXY(sf::FloatRect floatRect);
}
#endif //CONNECTION_POSITION_H
