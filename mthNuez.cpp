#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseNuez.h"

Nuez::Nuez()
{
    _nuez.setFillColor(sf::Color::Yellow);
    _nuez.setSize(sf::Vector2f(50.f, 100.f));


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

void Nuez::posInicio(int x, int y)
{
    _nuez.setPosition(y*145 + 45, x*175);
    _spriteNuez.setPosition(y*145 + 45, x*175);
    posicionMatriz(x,y);
}


void Nuez::posicionMatriz(int x, int y){
    fila = x-1;
    columna = y-2;
}


sf::RectangleShape& Nuez::getShape() //cambiar para que reciba la ventana y dibuje
{
    return _nuez;
}

sf::Sprite& Nuez::getSprite()
{
    return _spriteNuez;
}


void Nuez::hitNutt(){
    _hitTime++;

    if(_hitTime % (60) == 0){
        _vida-=25;
    }
}


void Nuez::setTexture(const sf::Texture& texture)
{
    _spriteNuez.setTexture(texture);
}

