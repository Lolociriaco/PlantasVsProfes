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

    _shadowPlanta.setTexture(_plantaTexture);
    _shadowPlanta.setScale(1.f, 1.f);


    if (!_plantaTexture.loadFromFile("lanzaguisantevioleta.png")) {
    std::cout << "Error cargando la textura de la planta" << std::endl;
    }else{
    std::cerr << " textura de la planta" << std::endl;

    }

    std::cout<<"ENTRANDO AL CONSTRUCTOR \n";

}


void Planta::cmd()
{

}


void Planta::update()
{
    _ticsPL++;
    sonidoDisparado = false;

    if(_ticsPL % (60*3) == 0)
    {
        _guisante.push_back(Lanzaguisantes(_plant.getPosition().y + _plant.getSize().y - 95, _plant.getPosition().x + 25));  //95 = cabeza de la planta || 25 = ancho planta/2
        sonidoDisparado = true;
    }

    for(Lanzaguisantes &guis : _guisante)
    {
        guis.disparando();
    }
}

bool Planta::getSonidoDisparado()
{
    return sonidoDisparado;
}

void Planta::hitPlant(int dano, int profesor){
    _hitTime++;

    if(collisionClock.getElapsedTime().asSeconds() >= 0.23){
        _spritePlanta.setColor(originalColor);
    }

    if(_hitTime % (30) == 0 && profesor != 3){
        sf::Color collisionColor = sf::Color::Red; // Color al momento de la colisión
        _spritePlanta.setColor(collisionColor);  // Cambia a color de colisión
        collisionClock.restart();
    }

    if(_hitTime % (29) == 0 && profesor == 3){
        sf::Color collisionColor = sf::Color::Red; // Color al momento de la colisión
        _spritePlanta.setColor(collisionColor);  // Cambia a color de colisión
        collisionClock.restart();
    }

    if(_hitTime % (60) == 0){
        _vida-=dano;
        std::cout<<"vida: "<<_vida<<"\n";
    }
}



void Planta::posInicio(int x, int y)
{
    std::cout << "\n y: " << y << std::endl;
//    sf::Vector2f position(472, y * 175);
    _plant.setPosition(y*145 + 54, x*175);
    _spritePlanta.setPosition(y*145 + 45, x*175);

    _shadowPlanta.setPosition(y*145 + 90 , x*175 - 10);
    _shadowPlanta.rotate(25);

//    _shadowPlanta.rotate(-20);
//    _shadowPlanta.setPosition(y*145 + 5 , x*175 + 10);

    _shadowPlanta.setColor(sf::Color(0, 0, 0, 60));
    posicionMatriz(x,y);

    originalColor = _spritePlanta.getColor();
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

sf::Sprite& Planta::getShadowSprite()
{
    return _shadowPlanta;
}


std::vector<Lanzaguisantes>& Planta::getGuisantes()
{
    return _guisante;
}


void Planta::setTexture(const sf::Texture& texture)
{
    _spritePlanta.setTexture(texture);
    _shadowPlanta.setTexture(texture);
}

