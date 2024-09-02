#include "clasePlantas.h"
#include <SFML/Graphics.hpp>

Planta::Planta(){
    _shape.setFillColor(sf::Color::Green);
    _shape.setSize(sf::Vector2f(50.f, 120.f));
}

void cmd();
void update();
void atacando();
sf::RectangleShape& getDraw();
