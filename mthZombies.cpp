#include "claseZombies.h"
#include <SFML/Graphics.hpp>
#include "funciones.h"


Zombie::Zombie(){
    _shape.setFillColor(sf::Color::Red);
    _shape.setSize(sf::Vector2f(50.f, 150.f));
    _estado = ESTADOS_ZOMBIES::CAMINANDO;
}

void Zombie::cmd(){

}

void Zombie::update(){
    switch (_estado)
    {
    case CAMINANDO:
        _shape.move(-0.5,0);
        break;

    case ATACANDO:
        break;
    }
}


void Zombie::posInicio(){
    _estado = ESTADOS_ZOMBIES::CAMINANDO;
    _shape.setPosition(1900,randomNum()*150);
}



sf::RectangleShape& Zombie::getDraw(){
    return _shape;
}
