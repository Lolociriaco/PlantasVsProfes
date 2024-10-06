#include "claseZombies.h"
#include <SFML/Graphics.hpp>
#include "funciones.h"
#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()



Zombie::Zombie() : _estado (CAMINANDO)
{
    _shape.setFillColor(sf::Color::Transparent);
    _shape.setSize(sf::Vector2f(50.f, 130.f));

    _vikingoTexture.loadFromFile("dirube.png");
    _spriteVikingo.setTexture(_vikingoTexture);
    _spriteVikingo.setScale(1.f, 1.f);
}


void Zombie::cmd()
{

}


void Zombie::update()
{
    switch (_estado)
    {
    case CAMINANDO:
        _shape.move(-2,0);
        _spriteVikingo.move(-2,0);
        break;

    case ATACANDO:
        break;
    }

}


void Zombie::reiniciar() {
    _shape.setFillColor(sf::Color::Transparent);  // O cualquier color inicial
    _shape.setSize(sf::Vector2f(50.f, 130.f));
    _estado = ESTADOS_ZOMBIES::CAMINANDO;
    _shape.setPosition(1920, randomNum()*168);  // O cualquier posición inicial
    _spriteVikingo.setColor(sf::Color::White);
}


void Zombie::posInicio()
{
    _shape.setPosition(1920,randomNum()*168);
    _spriteVikingo.setPosition(_shape.getPosition());
}


sf::RectangleShape& Zombie::getShape()
{
    return _shape;
}


sf::Sprite& Zombie::getSprite()
{
    return _spriteVikingo;
}


void Zombie::setTexture(const sf::Texture& texture)
{
    _spriteVikingo.setTexture(texture);
}


void Zombie::punchZombie(){
    _vida -= 20;
}
