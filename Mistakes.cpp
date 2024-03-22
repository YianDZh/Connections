//
// Created by Dave R. Smith on 12/6/23.
//

#include "Mistakes.h"

Mistakes::Mistakes()
{}
Mistakes::Mistakes(sf::Font& font)
: circles(4, sf::CircleShape(5.f))
{
    /// load the file into the font
    if(!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(3);
    /// set the font to the text
    text.setFont(font);
    /// set the string of the text
    text.setString("Mistakes Remaining:");
    /// set the character size;
    text.setCharacterSize(24);
    /// set the first circle to the right of the text
    circles[0].setPosition(text.getPosition());
    circles[0].move(text.getGlobalBounds().width + 10.f, 0);
    /// loop through the remaining circles and set each circle to the
    /// right of the previous circle
    for(int i=1; i<circles.size(); i++)
        Position::right(circles[i-1], circles[i], 10.f);
}
void Mistakes::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    states.transform = text.getTransform();
    window.draw(text);
    for(int i=0; i<circles.size(); i++)
        window.draw(circles[i], states);
}
void Mistakes::markdown()
{
    shrinking = true;
    mistakecount++;
}
void Mistakes::update()
{
    //// if shrinking is true,
    if(shrinking && circles.size() > 0)
    {
        if(clock.getElapsedTime().asMilliseconds() > 25)
        {
            circles.back().setRadius(circles.back().getRadius() - 1);
            clock.restart();
            if(circles.back().getRadius() <= 0)
            {
                shrinking = false;
                circles.pop_back();
            }
        }
    }
}
void Mistakes::setPosition(sf::Vector2f position)
{
    text.setPosition(position);
}
int Mistakes::count() const {
    return mistakecount;
}
