#include "clasePlantas.h"
#include "clasLanzaguisantes.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Planta::Planta() : _ticsPL(0)
{

    _plant.setFillColor(sf::Color::Transparent);
    _plant.setSize(sf::Vector2f(50.f, 130.f));

    sf::Texture _plantaTexture;
    _plantaTexture.loadFromFile("lanzaguisantevioleta.png");
    _spritePlanta.setTexture(_plantaTexture);
    _spritePlanta.setScale(1.f, 1.f);


    if (!_plantaTexture.loadFromFile("lanzaguisantevioleta.png")) {
    std::cout << "Error cargando la textura de la planta" << std::endl;
    }else{
    std::cerr << " textura de la planta" << std::endl;

    }

    std::cout<<"ENTRANDO AL CONSTRUCTOR \n";

    bufferGuisante.loadFromFile("peashootersound.wav");
    soundGuisante.setBuffer(bufferGuisante);
    soundGuisante.setVolume(100);

}


void Planta::cmd()
{

}


void Planta::update()
{
    _ticsPL++;
    if(_ticsPL % (60*3) == 0)
    {
        _guisante.push_back(Lanzaguisantes(_plant.getPosition().y + _plant.getSize().y - 95, _plant.getPosition().x + 25));  //95 = cabeza de la planta || 25 = ancho planta/2
        playSound();
    }

    for(Lanzaguisantes &guis : _guisante)
    {
        guis.disparando();
    }
}


void Planta::hitPlant(){
    _hitTime++;

    if(_hitTime % (60) == 0){
        _vida-=25;
        std::cout<<"vida: "<<_vida<<"\n";
    }
}



void Planta::posInicio(int x, int y)
{
    std::cout << "\n y: " << y << std::endl;
//    sf::Vector2f position(472, y * 175);
    _plant.setPosition(y*145 + 54, x*175);
    _spritePlanta.setPosition(y*145 + 45, x*175);
    posicionMatriz(x,y);
}


void Planta::posicionMatriz(int x, int y){
    fila = x-1;
    columna = y-2;
}


sf::RectangleShape& Planta::getShape()
{
    return _plant;
}


sf::Sprite& Planta::getSprite()
{
    return _spritePlanta;
}


std::vector<Lanzaguisantes>& Planta::getGuisantes()
{
    return _guisante;
}


void Planta::setTexture(const sf::Texture& texture)
{
    _spritePlanta.setTexture(texture);
}

void Planta::playSound()
{
    soundGuisante.play();
}
