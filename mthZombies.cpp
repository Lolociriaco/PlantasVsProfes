#include "claseZombies.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "funciones.h"
#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()



Zombie::Zombie() : _estado (CAMINANDO), _frameWidth(128), _frameHeight(128), _totalFrames(10), _currentFrame(0), _frameDuration(0.1f)
{
//    _shape.setFillColor(sf::Color::Red);
//    _shape.setSize(sf::Vector2f(50.f, 130.f));
//    _vikingoTexture.loadFromFile("dirubecaminando.png");
//    _spriteVikingo.setTexture(_vikingoTexture);
//    _spriteVikingo.setScale(2.f, 2.f);
//    _spriteVikingo.setTextureRect(sf::IntRect(1870, randomNum() * 167, _frameWidth, _frameHeight));  // Configura el primer cuadro

    _shape.setFillColor(sf::Color::Transparent);
    _shape.setSize(sf::Vector2f(50.f, 130.f));


    _spriteVikingo.setScale(2.f, 2.f);
    _spriteVikingo.setTextureRect(sf::IntRect(1870, randomNumber() * 167, _frameWidth, _frameHeight));  // Configura el primer cuadro
//
//    _shape.setFillColor(sf::Color::Red);
//    _shape.setSize(sf::Vector2f(50.f, 130.f));
//    _vastagTexture.loadFromFile("vastagcaminando.png");
//    _spriteVastag.setTexture(_vastagTexture);
//    _spriteVastag.setScale(2.f, 2.f);
//    _spriteVastag.setTextureRect(sf::IntRect(1870, randomNum() * 167, _frameWidth, _frameHeight));  // Configura el primer cuadro
}


void Zombie::cmd()
{

}


void Zombie::update()
{
    switch (_estado)
    {
    case CAMINANDO:
        _shape.move(-1.5, 0);
        _spriteVikingo.move(-1.5, 0);
        updateAnimation();
        break;

    case ATACANDO:
        break;
    }
}

void Zombie::updateAnimation()
{

    // Verifica si ha pasado el tiempo necesario para cambiar de cuadro
    if (_clock.getElapsedTime().asSeconds() > _frameDuration) {
        _currentFrame++;
        if (_currentFrame >= _totalFrames) {
            _currentFrame = 0;  // Vuelve al primer cuadro si se supera el último
        }

        _spriteVikingo.setTextureRect(sf::IntRect((_totalFrames - _currentFrame - 1) * _frameWidth, 0, _frameWidth, _frameHeight));

        _clock.restart();  // Reinicia el reloj para el siguiente cuadro
    }
}

void Zombie::reiniciar() {
    _shape.setFillColor(sf::Color::Transparent);  // O cualquier color inicial
    _shape.setSize(sf::Vector2f(50.f, 130.f));
    _estado = ESTADOS_ZOMBIES::CAMINANDO;
    _shape.setPosition(1920, randomNumber() * 167);  // O cualquier posición inicial
    _spriteVikingo.setColor(sf::Color::White);
}


void Zombie::posInicio()
{
    _shape.setPosition(1920, randomNumber() * 167);

    float offsetX = -75.f;
    float offsetY = -100.f;

    _spriteVikingo.setPosition(_shape.getPosition().x + offsetX, _shape.getPosition().y + offsetY);
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
    _vikingoTexture = texture;
    _spriteVikingo.setTexture(_vikingoTexture);
}


void Zombie::punchZombie(){
    _vida -= 20;
}
