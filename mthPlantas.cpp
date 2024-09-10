#include "clasePlantas.h"
#include "clasLanzaguisantes.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Planta::Planta() : _ticsPL(0)
{
    _plant.setFillColor(sf::Color::Transparent);
    _plant.setSize(sf::Vector2f(3.f, 3.f));

    _plantaTexture.loadFromFile("lanzaguisantevioleta.png");
    _spritePlanta.setTexture(_plantaTexture);
    _spritePlanta.setScale(1.f, 1.f);
}


void Planta::cmd()
{

}


void Planta::update()
{

    _ticsPL++;

    if(_ticsPL % (60*3) == 0)
    {
        _guisante.push_back(Lanzaguisantes(_plant.getPosition().y + _plant.getSize().y - 65));  //65 = size planta / 2
    }

    for(Lanzaguisantes &guis : _guisante)
    {
        guis.disparando();
    }
}

void Planta::posInicio(int y)
{
    sf::Vector2f position(322, y * 175);
    _plant.setPosition(position);
    _spritePlanta.setPosition(position);
}

sf::RectangleShape& Planta::getShape()
{
    return _plant;
}

sf::Sprite& Planta::getSprite()
{
    return _spritePlanta;
}

std::vector<Lanzaguisantes>& Planta::getGuisantes()
{
    return _guisante;
}

//sf::RectangleShape& Planta::getDraw(sf::RenderWindow &window)  //cambiar para que reciba la ventana y dibuje
//{
//    for(auto &guis : _guisante)
//    {
//        guis.drawBall(window);
//
//    }
//
//
//    window.draw(_plant);
//    return _plant;
//}
