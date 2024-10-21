#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseGirasol.h"

Girasol::Girasol()
{
    _girasol.setFillColor(sf::Color::Red);
    _girasol.setSize(sf::Vector2f(50.f, 130.f));

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

void Girasol::posInicio(int x, int y)
{
    _girasol.setPosition(y*145 + 45, x*175);
    _spriteGirasol.setPosition(y*145 + 45, x*175);
    posicionMatriz(x,y);
}


void Girasol::posicionMatriz(int x, int y){
    fila = x-1;
    columna = y-2;
}


sf::RectangleShape& Girasol::getShape() //cambiar para que reciba la ventana y dibuje
{
    return _girasol;
}

sf::Sprite& Girasol::getSprite()
{
    return _spriteGirasol;
}

void Girasol::hitGirasol(){
    _hitTime++;

    if(_hitTime % (60) == 0){
        _vida-=25;
    }
}


void Girasol::setTexture(const sf::Texture& texture)
{
    _spriteGirasol.setTexture(texture);
}
