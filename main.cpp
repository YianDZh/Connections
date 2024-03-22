#include <iostream>
#include <SFML/Graphics.hpp>
#include "functions.h"
#include "Grid.h"
#include "Connection.h"
////// create a file containg 10 lines, each containing 16 words separated by spaces
///// write a class or fucntion to add one line to a 4x4 vector of strings
int main()
{
    sf::VideoMode videoMode(720, 1000, 32);
    sf::RenderWindow window(videoMode, "Connection");
    window.setFramerateLimit(60);
    Connection connections;
    while(window.isOpen())
    {
        sf::Event event;
        ///event listener
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            connections.eventHandler(window, event);

        }

        connections.update();
        //grid.update();
        window.clear();
        window.draw(connections);
       // window.draw(grid);
        window.display();
    }
    return 0;
}
