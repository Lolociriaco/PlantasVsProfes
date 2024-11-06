#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseNuez.h"

Nuez::Nuez()
{
    _nuez.setFillColor(sf::Color::Transparent);
    _nuez.setSize(sf::Vector2f(50.f, 100.f));


    _nuezTexture.loadFromFile("nuezpvp.png");
    _spriteNuez.setTexture(_nuezTexture);
    _spriteNuez.setScale(1.f, 1.f);

    _shadowNuez.setTexture(_nuezTexture);
    _shadowNuez.setScale(1.f, 1.f);
    _shadowNuez.setColor(sf::Color(0,0,0,60));
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

    _shadowNuez.setPosition(y*145 + 90 , x*175 - 15);
    _shadowNuez.rotate(23);

    //_shadowPlanta.rotate(-20);
    //_spriteNuez.setPosition(y*145 + 5, x*175 + 10);

    originalColor = _spriteNuez.getColor();

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

sf::Sprite& Nuez::getShadowSprite()
{
    return _shadowNuez;
}


void Nuez::hitNutt(int damage, int profesor){
    _hitTime++;

    if(collisionClock.getElapsedTime().asSeconds() >= 0.19){
        _spriteNuez.setColor(originalColor);
    }

    if(_hitTime % (30) == 0 && profesor != 3){
        sf::Color collisionColor = sf::Color::Red; // Color al momento de la colisión
        _spriteNuez.setColor(collisionColor);  // Cambia a color de colisión
        collisionClock.restart();
    }

    if(_hitTime % (29) == 0 && profesor == 3){
        sf::Color collisionColor = sf::Color::Red; // Color al momento de la colisión
        _spriteNuez.setColor(collisionColor);  // Cambia a color de colisión
        collisionClock.restart();
    }

    if(_hitTime % (60) == 0){
        _vida-=damage;
    }
}


void Nuez::setTexture(const sf::Texture& texture)
{
    _spriteNuez.setTexture(texture);
    _shadowNuez.setTexture(texture);
}

