#include <iostream>
#include "claseMenuOpciones.h"
#include <SFML/Graphics.hpp>

using namespace std;


///constructor de menu
menuOpciones::menuOpciones(float width, float height)
{
    if (!fuente.loadFromFile("Samdan.ttf"))
    {
        cout<<"PEPE"<<endl;
    }
    //jugar
    Opciones[0].setFont(fuente);
    Opciones[0].setFillColor(sf::Color::Blue);
    Opciones[0].setString("Volumen");
    Opciones[0].setCharacterSize(80);
    Opciones[0].setPosition(840, 300);
    //opciones
    Opciones[1].setFont(fuente);
    Opciones[1].setFillColor(sf::Color::Black);
    Opciones[1].setString("Controles");
    Opciones[1].setCharacterSize(80);
    Opciones[1].setPosition(830, 450);
    //salir
    Opciones[2].setFont(fuente);
    Opciones[2].setFillColor(sf::Color::Black);
    Opciones[2].setString("Volver");
    Opciones[2].setCharacterSize(80);
    Opciones[2].setPosition(870, 600);

    opcionElegida = 0;

}

///destructor
menuOpciones::~menuOpciones()
{
}

///dibujar menu
void menuOpciones::drawOpciones(sf::RenderWindow& window)
{
    for (int i=0; i<MenuOpciones; i++)
    {
        window.draw(Opciones[i]);
    }
}

///mover arriba
void menuOpciones::moveUp()
{
    if (opcionElegida -1 >= 0)
    {

        Opciones[opcionElegida].setFillColor(sf::Color::Black);
        opcionElegida--;
        Opciones[opcionElegida].setFillColor(sf::Color::Blue);

    }
}

///mover abajo
void menuOpciones::moveDown()
{
     if (opcionElegida + 1 < MenuOpciones)
     {

         Opciones[opcionElegida].setFillColor(sf::Color::Black);
         opcionElegida++;
         Opciones[opcionElegida].setFillColor(sf::Color::Blue);

     }
}
