#ifndef CLASEMENUOPCIONES_H_INCLUDED
#define CLASEMENUOPCIONES_H_INCLUDED
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#define MenuOpciones 4

class menuOpciones
{
    private:
        int opcionElegida;
        sf::Font fuente;
        sf::Text Opciones[MenuOpciones];

    public:
        menuOpciones (float width, float height);
        void drawOpciones(sf::RenderWindow& window);
        void moveUp();
        void moveDown();
        int opcionPresionada()
        {
            return opcionElegida;
        }

        ~menuOpciones();

};

///constructor de menu
menuOpciones::menuOpciones(float width, float height)
{
    if (!fuente.loadFromFile("Samdan.ttf"))
    {
        cout<<"PEPE"<<endl;
    }

    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    //SILENCIAR MUSICA
    Opciones[0].setFont(fuente);
    Opciones[0].setFillColor(softYellow);
    Opciones[0].setString("> Silenciar música <");
    Opciones[0].setCharacterSize(80);
    Opciones[0].setPosition(700, 250);
    Opciones[0].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    Opciones[0].setOutlineThickness(3);
    //REANUDAR MUSICA
    Opciones[1].setFont(fuente);
    Opciones[1].setFillColor(darkGreen);
    Opciones[1].setString("> Reanudar música <");
    Opciones[1].setCharacterSize(80);
    Opciones[1].setPosition(705, 400);
    Opciones[1].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    Opciones[1].setOutlineThickness(3);
    //JUGABILIDAD
    Opciones[2].setFont(fuente);
    Opciones[2].setFillColor(darkGreen);
    Opciones[2].setString("> Jugabilidad <");
    Opciones[2].setCharacterSize(80);
    Opciones[2].setPosition(795, 550);
    Opciones[2].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    Opciones[2].setOutlineThickness(3);
    //salir
    Opciones[3].setFont(fuente);
    Opciones[3].setFillColor(darkGreen);
    Opciones[3].setString("> Volver <");
    Opciones[3].setCharacterSize(80);
    Opciones[3].setPosition(850, 700);
    Opciones[3].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    Opciones[3].setOutlineThickness(3);

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

    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    if (opcionElegida -1 >= 0)
    {
        Opciones[opcionElegida].setFillColor(darkGreen);
        opcionElegida--;
        Opciones[opcionElegida].setFillColor(softYellow);
    }
}

///mover abajo
void menuOpciones::moveDown()
{
    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

     if (opcionElegida + 1 < MenuOpciones)
     {
         Opciones[opcionElegida].setFillColor(darkGreen);
         opcionElegida++;
         Opciones[opcionElegida].setFillColor(softYellow);
     }
}



#endif // CLASEMENUOPCIONES_H_INCLUDED
