//
// Created by Dave R. Smith on 11/30/23.
//

#include "Position.h"
void Position::centerText(const sf::Shape &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

sf::Vector2f Position::rightTopCorner(sf::FloatRect floatRect)
{
    sf::Vector2f result;
    result.x = floatRect.left + floatRect.width;
    result.y = floatRect.top;
    return result;
}
sf::Vector2f Position::bottomRightCorner(sf::FloatRect floatRect)
{
    sf::Vector2f result = rightTopCorner(floatRect);
    result.y += floatRect.height;
    return result;
}
sf::Vector2f Position::centerXY(sf::FloatRect floatRect)
{
    sf::Vector2f result;
    result.x = floatRect.left + floatRect.width/2;
    result.y = floatRect.top + floatRect.height/2;
    return result;
}

void Position::left(const sf::Shape& constObj, sf::Shape& obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    sf::Vector2f pos = {cb.left - ob.width - spacing, cb. top};
    obj.setPosition(pos);
}

void Position::right(const sf::Shape& constObj, sf::Shape& obj, float spacing)
{
    sf::Vector2f pos = rightTopCorner(constObj.getGlobalBounds());
    pos.x += spacing;
    obj.setPosition(pos);
}
void Position::bottom(const sf::Shape& constObj, sf::Shape& obj, float spacing)
{
    sf::Vector2f pos = bottomRightCorner(constObj.getGlobalBounds());
    pos.x -= constObj.getGlobalBounds().width;
    pos.y += spacing;
    obj.setPosition(pos);
}

void Position::center(const sf::Shape& constObj, sf::Shape& obj)
{
    sf::Vector2f pos = centerXY(constObj.getGlobalBounds());
    pos.x -= obj.getGlobalBounds().width/2;
    pos.y -= obj.getGlobalBounds().height/2;
}
void Position::top(const sf::Shape& constObj, sf::Shape& obj, float spacing)
{
    sf::Vector2f pos = rightTopCorner(constObj.getGlobalBounds());
    pos.x -= obj.getGlobalBounds().width;
    pos.y -= obj.getGlobalBounds().height - spacing;
}