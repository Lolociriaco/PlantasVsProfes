#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#define Max_main_menu 3

class mainMenu
{
    private:
        int mainMenuSelected;
        sf::Font font;
        sf::Text MainMenu[Max_main_menu];
        sf::Font titulo;
        sf::Text tituloInicio;

    public:
        mainMenu (float ancho, float alto);
        void draw(sf::RenderWindow& window);
        void moveUp();
        void moveDown();

        int mainMenuPressed()
        {
            return mainMenuSelected;
        }

        ~mainMenu();
};


#endif // MAINMENU_H_INCLUDED
