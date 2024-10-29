#include <iostream>
#include "mainMenu.h"
#include <SFML/Graphics.hpp>

using namespace std;


///constructor de menu
mainMenu::mainMenu(float ancho, float alto)
{
    if (!font.loadFromFile("Samdan.ttf"))
    {
        cout<<"PEPE"<<endl;
    }

    titulo.loadFromFile("Samdan.ttf");

    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    tituloInicio.setFont(titulo);
    tituloInicio.setFillColor(darkGreen);
    tituloInicio.setString("PLANTAS  VS  PROFES");
    tituloInicio.setCharacterSize(130);
    tituloInicio.setPosition(480, 100);
    tituloInicio.setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    tituloInicio.setOutlineThickness(5);

    //jugar
    MainMenu[0].setFont(font);
    MainMenu[0].setFillColor(softYellow);
    MainMenu[0].setString("Jugar");
    MainMenu[0].setCharacterSize(80);
    MainMenu[0].setPosition(880, 500);
    MainMenu[0].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    MainMenu[0].setOutlineThickness(3);
    //opciones
    MainMenu[1].setFont(font);
    MainMenu[1].setFillColor(darkGreen);
    MainMenu[1].setString("Opciones");
    MainMenu[1].setCharacterSize(80);
    MainMenu[1].setPosition(840, 650);
    MainMenu[1].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    MainMenu[1].setOutlineThickness(3);
    //salir
    MainMenu[2].setFont(font);
    MainMenu[2].setFillColor(darkGreen);
    MainMenu[2].setString("Records");
    MainMenu[2].setCharacterSize(80);
    MainMenu[2].setPosition(880, 800);
    MainMenu[2].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    MainMenu[2].setOutlineThickness(3);

    MainMenu[3].setFont(font);
    MainMenu[3].setFillColor(darkGreen);
    MainMenu[3].setString("Salir");
    MainMenu[3].setCharacterSize(80);
    MainMenu[3].setPosition(880, 950);
    MainMenu[3].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    MainMenu[3].setOutlineThickness(3);



    mainMenuSelected = 0;

}

///destructor
mainMenu::~mainMenu()
{
}

///dibujar menu
void mainMenu::draw(sf::RenderWindow& window)
{
    window.draw(tituloInicio);
    for (int i=0; i<Max_main_menu; i++)
    {
        window.draw(MainMenu[i]);
    }
}

///mover arriba
void mainMenu::moveUp()
{
    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);
    if (mainMenuSelected -1 >= 0)
    {

        MainMenu[mainMenuSelected].setFillColor(darkGreen);
        mainMenuSelected--;
        MainMenu[mainMenuSelected].setFillColor(softYellow);

    }
}

///mover abajo
void mainMenu::moveDown()
{
     sf::Color darkGreen(0, 100, 0);
     sf::Color softYellow(255, 223, 0);
     if (mainMenuSelected + 1 < Max_main_menu)
     {

         MainMenu[mainMenuSelected].setFillColor(darkGreen);
         mainMenuSelected++;
         MainMenu[mainMenuSelected].setFillColor(softYellow);

     }
}
