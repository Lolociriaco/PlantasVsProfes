#include "clasLanzaguisantes.h"

Lanzaguisantes::Lanzaguisantes(float y, float x)
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(15);
    _shape.setPosition(x, y);

    _shadow.setFillColor(sf::Color::Magenta);
    _shadow.setRadius(15);
    _shadow.setPosition(x+25, y+45);
    _shadow.setFillColor(sf::Color(0, 0, 0, 60));


}


void Lanzaguisantes::disparando()
{
    _shape.move(10,0);
    _shadow.move(10,0);
}



