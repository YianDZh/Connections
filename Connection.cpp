//
// Created by Dave R. Smith on 12/7/23.
//

#include "Connection.h"

Connection::Connection()
: grid(), shuffle(Grid::font, "Shuffle"), deselect(Grid::font, "Deselect"), reload(Grid::font, "Reload"),
submit(Grid::font, "Submit"), mistakes(Grid::font), key()
{
    // TODO Initital position of member variables
    key.setPosition({0,0});
    grid.setPosition({0, 0});
    grid.shuffle();
    mistakes.setPosition({0, 500});
    shuffle.setSize({100, 50});
    deselect.setSize({100, 50});
    reload.setSize({100, 50});
    submit.setSize({100, 50});
    shuffle.setPosition({0, 550});

    Position::right(shuffle, deselect, 10.f);
    Position::right(deselect, reload, 10.f);
    Position::right(reload, submit, 10.f);


    submit.setPosition(submit.getPosition());
    deselect.setPosition(deselect.getPosition());
    reload.setPosition(reload.getPosition());
}

void Connection::eventHandler(sf::RenderWindow& window, sf::Event event) {
    key.eventHandler(window, event);
    int count = mistakes.count();
    grid.eventHandler(window, event);
    shuffle.eventHandler(window, event);
    deselect.eventHandler(window, event);
    reload.eventHandler(window, event);
    submit.eventHandler(window, event);
    ///if shuffle button is clicked, shuffle the grid
    if (MouseEvents::isClicked(shuffle, window)) {
        grid.shuffle();
    }
    else if (MouseEvents::isClicked(submit, window)) {
        if (!grid.analyze()) {
            mistakes.markdown();
            mistakes.update();
            if (4 == count){
                grid.disapear();
            }
        }
        else {
            grid.Correct();
            grid.Final();
            grid.deselectAll();
        }
    }
    else if (MouseEvents::isClicked(deselect, window)) {
        grid.deselectAll();
    }
    else if (MouseEvents::isClicked(reload, window)) {
        mistakes.update();
        grid.reload();
        grid.shuffle();
        key.reload();

    }
}
void Connection::update()
{
    grid.update();
    mistakes.update();
    shuffle.update();
    submit.update();
    deselect.update();
    reload.update();
    key.update();
    key.Answers();

}
void Connection::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(key);
    window.draw(grid);
    window.draw(mistakes);
    window.draw(shuffle);
    window.draw(deselect);
    window.draw(reload);
    window.draw(submit);
}

