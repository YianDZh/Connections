//
// Created by Dave R. Smith on 12/6/23.
//

#ifndef CONNECTION_MISTAKES_H
#define CONNECTION_MISTAKES_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"
class Mistakes : public sf::Drawable
{
private:
    sf::Text text;
    std::vector<sf::CircleShape> circles;
    sf::Clock clock;
    bool shrinking = false;
    int mistakecount=0;
public:
    Mistakes();
    Mistakes(sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void markdown();
    void update();
    void setPosition(sf::Vector2f position);
    int count () const;
};


#endif //CONNECTION_MISTAKES_H
