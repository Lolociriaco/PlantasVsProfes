#include "claseZombies.h"
#include <SFML/Graphics.hpp>

Zombie::Zombie(float x, float y){
    _shape.setFillColor(sf::Color::Red);
    _shape.setSize(sf::Vector2f(50.f, 150.f));
    _shape.setPosition(x,y);
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

void Zombie::quieto(float x, float y){
    _estado = ESTADOS_ZOMBIES::QUIETO;

}

    void atacando();

sf::RectangleShape& Zombie::getDraw(){
    return _shape;
}
