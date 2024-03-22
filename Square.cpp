//
// Created by Dave R. Smith on 11/30/23.
//

#include "Square.h"

///use the font param to setFont,
/// text to setString
/// play around with character size,
/// center the text
Square::Square(sf::Font& font, std::string word)
{
    text.setFont(font);
    text.setString(word);
    text.setCharacterSize(16);
    Position::centerText(*this, text);
}
Square::Square(){}



void Square::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    sf::RectangleShape parent = *this;

    window.draw(parent);
    window.draw(text);
}

void Square::setPosition(sf::Vector2f position)
{
    sf::RectangleShape::setPosition(position);
    Position::centerText(*this, text);
}

void Square::setClicked(bool option)
{
    clicked = option;
}
bool Square::getClicked()
{
    return clicked;
}

std::string Square::getString()
{
    return text.getString();
}

void Square::invisible (){
    setSize({0,0});
    text.setCharacterSize(0);
    text.setString("");
}

bool Square::lock (){
    por = true;
    return por ;
}
void Square::update() {
    ////if true make the filler color different and move to the top
    if (por)
        Square::changer();
    ///if in clicked state, change color to blue else change to white
    if (clicked && !por) {
        setFillColor(sf::Color(90, 89, 78, 255));
        text.setFillColor(sf::Color::White);
    }
    else if(!por){
        setFillColor(sf::Color(239, 239, 230));
        text.setFillColor(sf::Color::Black);
    }
}

void Square::eventHandler(sf::RenderWindow& window, sf::Event event) {
    ////if new bool true clicked=clicked?

    ///if the square left-clicked by the mouse
    ///toggle the squares click state
    if (MouseEvents::isClicked(*this, window)) {
            clicked = !clicked;
    }
}
void Square::changer () {
        setFillColor(sf::Color::Green);
        text.setFillColor(sf::Color::Black);
}
