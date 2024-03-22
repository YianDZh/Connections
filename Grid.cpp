//
// Created by Dave R. Smith on 12/5/23.
//

#include "Grid.h"
sf::Font Grid::font;

Grid::Grid()
: grid(4, std::vector<Square>(4, Square())), key(4, std::vector<std::string>(4, ""))
{
    if(!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(2);
    createGrid(grid);
    key=solver();

}


void Grid::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
   for(int i=0; i<grid.size(); i++)
   {
       for(int j=0; j<grid[i].size(); j++)
       {
           window.draw(grid[i][j]);
       }
   }
}

void Grid::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
           grid[i][j].eventHandler(window, event);
        }
    }
}

void Grid::update()
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            grid[i][j].update();
        }
    }
}
void Grid::shuffle()
{
    /// create a sf::Vector2f temp
    sf::Vector2f temp;
    /// loop through grid
    for(int i=0; i<grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            /// int row = random number between 0 and the number of rows -1
            int row = rand() % grid.size();
            /// int col = rnadom number bwteen 0 and the number of cols -1
            int col = rand() % grid[i].size();
            /// set temp = the current square.getPostion()
            temp = grid[i][j].getPosition();
            /// set the current square positio to the position (row, col);
            grid[i][j].setPosition(grid[row][col].getPosition());
            /// // set the square's position at (row, col) to temp
            grid[row][col].setPosition(temp);
        }
    }
}


void Grid::createGrid(std::vector<std::vector<Square>> &grid)
{
    key=solver();
    for(int i=0; i<grid.size(); i++)
    {
        //// create square with text from the file
        grid[i][0] = Square(font, key[i][0]);
        grid[i][0].setSize({100, 100});
        if(i == 0)
            grid[i][0].setPosition({0, 0});
        else
        {
            Position::bottom(grid[i-1][0], grid[i][0], 10.f);
            grid[i][0].setPosition(grid[i][0].getPosition());
        }


        for(int j=1; j<grid[i].size(); j++)
        {
            //// create square with text from the file
            grid[i][j] = Square(font, key[i][j]);
            grid[i][j].setSize({100, 100});
            Position::right(grid[i][j-1], grid[i][j], 10.f);
            grid[i][j].setPosition(grid[i][j].getPosition());
        }
    }
}


void Grid::deselectAll()
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            grid[i][j].setClicked(false);
        }
    }
}


bool Grid::correctChoice (std::vector<std::string>choice){
    int counter = 0;
    for (int i = 0; i < grid.size(); i++){
        std::vector<std::string> tumadre = key [i];
        for (int j = 0; j < grid[i].size(); j++) {
            for (int k = 0; k < choice.size(); ++k) {
                if ( choice[j] == tumadre[k]){
                    counter++;
                }
            }
        }
        if(counter == 4)
            return true;
        counter = 0;
    }
    return false;
}

bool Grid::analyze() {
    std::vector<std::string> temp;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j].getClicked()) {
                temp.push_back(grid[i][j].getString());
            }
        }
    }
    ///// TODO use the string in the vector to determine if there are the correct choices
    bool correct = correctChoice(temp);
    if (correct) {
        return true;
    } else
        return false;
}
void Grid::setPosition(sf::Vector2f position)
{
    for(int i=0; i<grid.size(); i++)
    {
        if(i == 0)
            grid[i][0].setPosition(position);
        else
        {
            Position::bottom(grid[i-1][0], grid[i][0], 10.f);
            grid[i][0].setPosition(grid[i][0].getPosition());
        }


        for(int j=1; j<grid[i].size(); j++)
        {
            Position::right(grid[i][j-1], grid[i][j], 10.f);
            grid[i][j].setPosition(grid[i][j].getPosition());
        }
    }
}
void Grid::reload (){
    key=solver();
    for(int i=0; i<grid.size(); i++)
    {
        //// create square with text from the file
        grid[i][0] = Square(font, key[i][0]);
        grid[i][0].setSize({100, 100});
        if(i == 0)
            grid[i][0].setPosition({0, 0});
        else
        {
            Position::bottom(grid[i-1][0], grid[i][0], 10.f);
            grid[i][0].setPosition(grid[i][0].getPosition());
        }


        for(int j=1; j<grid[i].size(); j++)
        {
            grid[i][j] = Square(font, key[i][j]);
            grid[i][j].setSize({100, 100});
            Position::right(grid[i][j-1], grid[i][j], 10.f);
            grid[i][j].setPosition(grid[i][j].getPosition());
        }
    }
}

void Grid::disapear() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            grid[i][j].invisible();
        }
    }
}

void Grid::Answers () {
    std::vector<sf::Color> rowColors = {
            sf::Color::Magenta,
            sf::Color::Green,
            sf::Color::Cyan,
            sf::Color::Yellow
    };
    for (int i = 0; i < grid.size(); i++) {
        sf::Color rowColor = rowColors[i % rowColors.size()];
        for (int j = 0; j < grid[i].size(); j++) {
            grid[i][j].setFillColor(rowColor);
        }
    }
}

void Grid::Correct() {
    std::vector<std::string> temp;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j].getClicked()) {
                temp.push_back(grid[i][j].getString());
            }
        }
    }
    bool correct = correctChoice(temp);

    if (correct) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // Check if the element was selected before applying the commands
                if (grid[i][j].getClicked()) {
                    grid[i][j].lock();
                    grid[i][j].update();
                }
            }
        }
    }
}
void Grid::Final() {
    sf::Vector2f temp;

    for (int j = 0; j < grid[0].size(); j++) {
        for (int i = 0; i < grid.size() - 1; i++) {
            if (grid[i][j].getClicked()) {
                temp = grid[i][j].getPosition();
                grid[i][j].setPosition(grid[i + 1][j].getPosition());
                grid[i + 1][j].setPosition(temp);
            }
        }
    }
}