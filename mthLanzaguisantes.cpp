#include "clasLanzaguisantes.h"
#include <iostream>

Lanzaguisantes::Lanzaguisantes(float y)
{
    _shape.setFillColor(sf::Color::Green);
    _shape.setRadius(15);
    _shape.setPosition(335,y+85);
}


void Lanzaguisantes::disparando()
{
    _shape.move(10,0);

}


void Lanzaguisantes::drawBall(sf::RenderWindow &window)
{
    window.draw(_shape);
}

