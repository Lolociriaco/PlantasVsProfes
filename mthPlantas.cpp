#include "clasePlantas.h"
#include "clasLanzaguisantes.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Planta::Planta()
{
    _plant.setFillColor(sf::Color::Transparent);
    _plant.setSize(sf::Vector2f(3.f, 3.f));
}


void Planta::cmd()
{

}


void Planta::update()
{

    _ticsPL++;

    if(_ticsPL % (60*2) == 0)
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
    _plant.setPosition(400, y * 200);
}

sf::RectangleShape& Planta::getDraw(sf::RenderWindow &window)  //cambiar para que reciba la ventana y dibuje
{
    for(auto &guis : _guisante)
    {
        guis.drawBall(window);

    }


    window.draw(_plant);
    return _plant;
}
