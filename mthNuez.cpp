#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseNuez.h"

Nuez::Nuez()
{
    _nuez.setFillColor(sf::Color::Transparent);
    _nuez.setRadius(10);

    _nuezTexture.loadFromFile("nuezpvp.png");
    _spriteNuez.setTexture(_nuezTexture);
    _spriteNuez.setScale(1.f, 1.f);
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
        sf::Vector2f position(470, y * 180);
        _nuez.setPosition(position);
        _spriteNuez.setPosition(position);
    }
}

sf::CircleShape& Nuez::getShape() //cambiar para que reciba la ventana y dibuje
{
    return _nuez;
}

sf::Sprite& Nuez::getSprite()
{
    return _spriteNuez;
}

