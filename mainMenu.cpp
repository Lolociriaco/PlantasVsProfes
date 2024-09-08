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
    tituloInicio.setFont(titulo);
    tituloInicio.setFillColor(sf::Color::Black);
    tituloInicio.setString("PLANTAS VS PROFES");
    tituloInicio.setCharacterSize(130);
    tituloInicio.setPosition(580, 100);
    //jugar
    MainMenu[0].setFont(font);
    MainMenu[0].setFillColor(sf::Color::Blue);
    MainMenu[0].setString("Jugar");
    MainMenu[0].setCharacterSize(80);
    MainMenu[0].setPosition(860, 400);
    //opciones
    MainMenu[1].setFont(font);
    MainMenu[1].setFillColor(sf::Color::Black);
    MainMenu[1].setString("Opciones");
    MainMenu[1].setCharacterSize(80);
    MainMenu[1].setPosition(860, 550);
    //salir
    MainMenu[2].setFont(font);
    MainMenu[2].setFillColor(sf::Color::Black);
    MainMenu[2].setString("Salir");
    MainMenu[2].setCharacterSize(80);
    MainMenu[2].setPosition(860, 700);

    mainMenuSelected = -1;

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
    if (mainMenuSelected -1 >= 0)
    {

        MainMenu[mainMenuSelected].setFillColor(sf::Color::Black);
        mainMenuSelected--;
        MainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);

        if (mainMenuSelected == -1)
        {
            mainMenuSelected = Max_main_menu;
        }

    }
}

///mover abajo
void mainMenu::moveDown()
{
     if (mainMenuSelected + 1 < Max_main_menu)
     {

         MainMenu[mainMenuSelected].setFillColor(sf::Color::Black);
         mainMenuSelected++;
         MainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);

         if (mainMenuSelected == Max_main_menu+4)
         {
             mainMenuSelected = 0;
         }

     }
}
