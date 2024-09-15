#ifndef CLASEMENUOPCIONES_H_INCLUDED
#define CLASEMENUOPCIONES_H_INCLUDED
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#define MenuOpciones 3

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


#endif // CLASEMENUOPCIONES_H_INCLUDED
