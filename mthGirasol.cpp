#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseGirasol.h"

Girasol::Girasol()
{
    _girasol.setFillColor(sf::Color::Transparent);
    _girasol.setRadius(10);

    _girasolTexture.loadFromFile("girasole.png");
    _spriteGirasol.setTexture(_girasolTexture);
    _spriteGirasol.setScale(1.f, 1.f);
}


void Girasol::cmd()
{

}


void Girasol::update()
{
    _ticsGI++;

}

void Girasol::posInicio(int y)
{
    if (_ticsGI % (60*2) == 0)
    {
        sf::Vector2f position(322, y * 175);
        _girasol.setPosition(position);
        _spriteGirasol.setPosition(position);
    }
}

sf::CircleShape& Girasol::getShape() //cambiar para que reciba la ventana y dibuje
{
    return _girasol;
}

sf::Sprite& Girasol::getSprite()
{
    return _spriteGirasol;
}


