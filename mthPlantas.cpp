#include "clasePlantas.h"
#include "clasLanzaguisantes.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Planta::Planta() : _ticsPL(0)
{

    _plant.setFillColor(sf::Color::Red);
    _plant.setSize(sf::Vector2f(50.f, 60.f));

    if (!_plantaTexture.loadFromFile("lanzaguisantevioleta.png"))
    {
    std::cout << "Error cargando la textura de la planta" << std::endl;
    }
    else
    {
    ///lo comentado es para la opacidad
    sf::Color color = _spritePlanta.getColor();  // Obtener el color actual
    color.a = 255;  // 128 es 50% de opacidad (0 completamente transparente, 255 completamente opaco)
    _spritePlanta.setColor(color);
    _spritePlanta.setTexture(_plantaTexture);
    _spritePlanta.setScale(1.f, 1.f);

    }

    std::cout<<"ENTRANDO AL CONSTRUCTOR \n";

}


void Planta::cmd()
{

}


void Planta::update()
{
    _ticsPL++;

    if(_ticsPL % (60*3) == 0)
    {
        _guisante.push_back(Lanzaguisantes(_plant.getPosition().y + _plant.getSize().y - 65));  //65 = size planta / 2
    }

    for(Lanzaguisantes &guis : _guisante)
    {
        guis.disparando();
    }
}


void Planta::hitPlant()
{
    _hitTime++;

    if(_hitTime % (60) == 0)
    {
        _vida-=25;
        std::cout<<"vida: "<<_vida<<"\n";
    }
}

void Planta::setTexture(const sf::Texture& textura)
{
    _spritePlanta.setTexture(textura);
}

void Planta::posInicio(int y)
{
    std::cout << "\n y: " << y << std::endl;
    sf::Vector2f position(472, y * 175);
    _plant.setPosition(position);
    _spritePlanta.setPosition(position);
}


sf::RectangleShape& Planta::getShape()
{
    return _plant;
}

sf::Sprite& Planta::getSprite()
{
    return _spritePlanta;
}


std::vector<Lanzaguisantes> &Planta::getGuisantes()
{
    return _guisante;
}

//sf::RectangleShape& Planta::getDraw(sf::RenderWindow &window)  //cambiar para que reciba la ventana y dibuje
//{
//    for(auto &guis : _guisante)
//    {
//        guis.drawBall(window);
//
//    }
//
//
//    window.draw(_plant);
//    return _plant;
//}
