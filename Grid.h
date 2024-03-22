//
// Created by Dave R. Smith on 12/5/23.
//

#ifndef CONNECTION_GRID_H
#define CONNECTION_GRID_H
#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Position.h"
#include "fileio.h"

class Grid : public sf::Drawable {
public:
    static sf::Font font;

    /// load the font;
    /// set positions of each square
    Grid();

    //// loop throught 2D grid and draw each square
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    /// loop through 2D vextor and call the eventhandler on each square
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    /// loop through 2D vector and call the update function on each
    void update();
    void deselectAll();
    void shuffle();
    bool analyze();
    void setPosition(sf::Vector2f position);
    bool correctChoice(std::vector<std::string> choice);
    void reload ();
    void disapear ();
    void Answers ();
    void Correct();
    void Final ();

private:
    std::vector<std::vector<std::string>> key;
    std::vector<std::vector<Square>> grid;
    int count =0;
    void createGrid(std::vector<std::vector<Square>> &grid);
};
#endif //CONNECTION_GRID_H
