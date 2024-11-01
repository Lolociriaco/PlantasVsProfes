#include "clasLanzaguisantes.h"

Lanzaguisantes::Lanzaguisantes(float y, float x)
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(15);
    _shape.setPosition(x, y);
    _shape.setOutlineColor(sf::Color::Black);
    _shape.setOutlineThickness(3);

}


void Lanzaguisantes::disparando()
{
    _shape.move(10,0);
}



