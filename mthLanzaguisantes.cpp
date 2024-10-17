#include "clasLanzaguisantes.h"
#include <iostream>

Lanzaguisantes::Lanzaguisantes(float y, float x)
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(15);
    _shape.setPosition(x, y);
}


void Lanzaguisantes::disparando()
{
    _shape.move(10,0);

}


void Lanzaguisantes::drawBall(sf::RenderWindow &window)
{
    window.draw(_shape);
}

