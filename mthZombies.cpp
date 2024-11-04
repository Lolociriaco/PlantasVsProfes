#include "claseZombies.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "funciones.h"
#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()



Zombie::Zombie()
{
    _estado = CAMINANDO;
    _frameWidth = 128;
    _frameHeight = 128;
    _totalAttackFrames = 5;
    _currentFrame = 0;
    _frameDuration = 0.1f;

    _shape.setFillColor(sf::Color::Transparent);
    _shape.setSize(sf::Vector2f(50.f, 130.f));

    _spriteVikingo.setScale(2.f, 2.f);
    _spriteSombra.setScale(2.f, 2.f);
    _spriteVikingo.setTextureRect(sf::IntRect(1870, randomNumber() * 167, _frameWidth, _frameHeight));  // Configura el primer cuadro
    _spriteSombra.setTextureRect(sf::IntRect(1870, randomNumber() * 167, _frameWidth, _frameHeight));  // Configura el primer cuadro
}


void Zombie::setProfe(int profe){
    if(profe == 1){
        _totalFrames = 10;
        _profe = MATI;
        _velocidad = -2.2;
        _vida = 40;
    }
    else if(profe == 2){
        _totalFrames = 8;
        _profe = VASTAG;
        _velocidad = -1.3;
        _vida = 100;
    }
    else{
        _profe = MAXI;
        _totalFrames = 8;
        _velocidad = -1.2;
        _vida = 120;
    }
}


TIPO_ZOMBIE Zombie::getProfe(){
    return _profe;
}


void Zombie::cmd()
{

}


void Zombie::update()
{
    switch (_estado)
    {
    case CAMINANDO:
        _spriteVikingo.setTexture(_vikingoTexture);
        _spriteSombra.setTexture(_vikingoTexture);
        _shape.move(_velocidad, 0);
        _spriteVikingo.move(_velocidad, 0);
        _spriteSombra.move(_velocidad, 0);
        updateAnimation();
        hablo = false;
        break;

    case ATACANDO:
        _spriteVikingo.setTexture(_attackTexture);
        _spriteSombra.setTexture(_attackTexture);
        attackAnimation();

        break;
    }
    if(!hitted){
        originalColor = _spriteVikingo.getColor();
    }
    else if(collisionClock.getElapsedTime().asSeconds() >= 0.13){
        _spriteVikingo.setColor(originalColor);
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
        _spriteSombra.setTextureRect(sf::IntRect((_totalFrames - _currentFrame - 1) * _frameWidth, 0, _frameWidth, _frameHeight));

        _clock.restart();  // Reinicia el reloj para el siguiente cuadro
    }
}

void Zombie::attackAnimation() {
    // Verifica si ha pasado el tiempo necesario para cambiar de cuadro de ataque
    if (_clock.getElapsedTime().asSeconds() > _frameDuration) {
        _currentFrame++;
        if (_currentFrame >= _totalAttackFrames) {
            _currentFrame = 0;  // Reinicia al primer cuadro
        }

        // Cambia el rectángulo de textura para la animación de golpeo
        _spriteVikingo.setTextureRect(sf::IntRect((_totalAttackFrames - _currentFrame - 1) * _frameWidth, 0, _frameWidth, _frameHeight));
        _spriteSombra.setTextureRect(sf::IntRect((_totalAttackFrames - _currentFrame - 1) * _frameWidth, 0, _frameWidth, _frameHeight));

        _clock.restart();  // Reinicia el reloj
    }
}

void Zombie::setAttackTexture(const sf::Texture& attackTexture) {
    _attackTexture = attackTexture;
    if (_estado == ATACANDO) {
        _spriteVikingo.setTexture(_attackTexture);
        _spriteSombra.setTexture(_attackTexture);
    }
}

void Zombie::reiniciar() {
    _shape.setFillColor(sf::Color::Transparent);  // O cualquier color inicial
    _shape.setSize(sf::Vector2f(50.f, 130.f));
    _estado = ESTADOS_ZOMBIES::CAMINANDO;
    _shape.setPosition(1920, randomNumber() * 167);  // O cualquier posición inicial
    _spriteVikingo.setColor(sf::Color::Transparent);
    _spriteSombra.setColor(sf::Color::Transparent);
}


void Zombie::posInicio()
{
    _shape.setPosition(1920, randomNumber() * 167);

    float offsetX = -80.f;
    float offsetY = -100.f;

    _spriteVikingo.setPosition(_shape.getPosition().x + offsetX, _shape.getPosition().y + offsetY);


    _spriteSombra.setPosition(_shape.getPosition().x + offsetX + 120.f, _shape.getPosition().y + offsetY - 43.f);
    _spriteSombra.setColor(sf::Color(0, 0, 0, 100));
    _spriteSombra.rotate(25);
}

sf::RectangleShape& Zombie::getShape()
{
    return _shape;
}


sf::Sprite& Zombie::getSprite()
{
    return _spriteVikingo;
}

sf::Sprite& Zombie::getSpriteShadow()
{
    return _spriteSombra;
}


void Zombie::setTexture(const sf::Texture& texture)
{
    _vikingoTexture = texture;
    _spriteVikingo.setTexture(_vikingoTexture);
    _spriteSombra.setTexture(_vikingoTexture);
}


void Zombie::punchZombie(){

    sf::Color collisionColor = sf::Color::Red; // Color al momento de la colisión
    _spriteVikingo.setColor(collisionColor);  // Cambia a color de colisión
    _vida -= 20;
    hitted = true;
    collisionClock.restart();
}
