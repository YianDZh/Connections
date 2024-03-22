//
// Created by Dave R. Smith on 12/7/23.
//

#ifndef CONNECTION_CONNECTION_H
#define CONNECTION_CONNECTION_H
#include "SFML/Graphics.hpp"
#include "Grid.h"
#include "Mistakes.h"

class Connection : public sf::Drawable
{
private:
    Grid grid,key;
    Mistakes mistakes;
    Square shuffle, submit, deselect, reload;
public:
    Connection();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};



#endif //CONNECTION_CONNECTION_H
