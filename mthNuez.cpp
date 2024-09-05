#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseNuez.h"

Nuez::Nuez()
{
    _nuez.setFillColor(sf::Color::Blue);
    _nuez.setRadius(10);
}


void Nuez::cmd()
{

}


void Nuez::update()
{
    _ticsNU++;

}

void Nuez::posInicio(int y)
{
    if (_ticsNU % (60*2) == 0)
    {
       _nuez.setPosition(680, y * 194);
    }
}

sf::CircleShape& Nuez::getDraw(sf::RenderWindow &window) //cambiar para que reciba la ventana y dibuje
{

    window.draw(_nuez);
    return _nuez;
}

