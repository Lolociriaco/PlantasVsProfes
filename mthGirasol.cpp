#include <iostream>
#include <SFML/Graphics.hpp>
#include "claseGirasol.h"


Girasol::Girasol()
{
    _girasol.setFillColor(sf::Color::Transparent);
    _girasol.setSize(sf::Vector2f(50.f, 130.f));

    _girasolTexture.loadFromFile("girasole.png");
    _spriteGirasol.setTexture(_girasolTexture);
    _spriteGirasol.setScale(1.f, 1.f);

}

void Girasol::cmd()
{

}

std::vector<Soles>& Girasol::getSoles()
{
    return _sol;
}


void Girasol::update()
{
    _ticsGI++;

    if(_ticsGI % 270 == 0)
    {
        if(_sol.size() < 1){
            _sol.push_back(Soles(_girasol.getPosition().y + _girasol.getSize().y - 60, _girasol.getPosition().x + 50));  //95 = cabeza de la planta || 25 = ancho planta/2
        }

    }

}

void Girasol::posInicio(int x, int y)
{
    _girasol.setPosition(y*145 + 48, x*175);
    _spriteGirasol.setPosition(y*145 + 45, x*175);
    posicionMatriz(x,y);
}


void Girasol::posicionMatriz(int x, int y){
    fila = x-1;
    columna = y-2;
}

bool Girasol::checkSolClick(sf::Vector2f mousePos) {
    bool clicked = false;
    for (auto it = _sol.begin(); it != _sol.end(); /* vacío */) {
        if (it->isClicked(mousePos)) {
            it = _sol.erase(it);  // Elimina el sol y ajusta el iterador
            clicked = true;  // Marcamos que hubo un clic exitoso
        } else {
            ++it;
        }
    }
    return clicked;  // Devuelve true si un sol fue clickeado y eliminado
}


sf::RectangleShape& Girasol::getShape() //cambiar para que reciba la ventana y dibuje
{
    return _girasol;
}

sf::Sprite& Girasol::getSprite()
{
    return _spriteGirasol;
}

void Girasol::hitGirasol(){
    _hitTime++;

    if(_hitTime % 60 == 0){
        _vida-=25;
    }
}


void Girasol::setTexture(const sf::Texture& texture)
{
    _spriteGirasol.setTexture(texture);
}

