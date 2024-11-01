#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

#define Max_main_menu 4

class mainMenu
{
    private:
        int mainMenuSelected;
        sf::Font font;
        sf::Text MainMenu[Max_main_menu];
        sf::Font titulo;
        sf::Text tituloInicio;
        sf::Music musicMenu;
        bool isMusicPlaying = false;

    public:
        mainMenu (float ancho, float alto);
        void draw(sf::RenderWindow& window);
        void moveUp();
        void moveDown();
        void playMusic();
        void stopMusic();
        void pauseMusic();
        int mainMenuPressed()
        {
            return mainMenuSelected;
        }

        ~mainMenu();
};


#endif // MAINMENU_H_INCLUDED
