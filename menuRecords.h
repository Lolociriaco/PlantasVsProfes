#ifndef MENURECORDS_H_INCLUDED
#define MENURECORDS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#define _cantidadRecords 8

class menuRecords
{
    private:
        int opcionElegida;
        sf::Font fuente;
        //int _cantidadRecords = 8;
        sf::Text cartelRecords;
        sf::Text cartelEnter;
        sf::Text cartelTiempo;
        sf::Text cartelRondas;
        sf::Text cartelNombre;
        sf::Text Texto[_cantidadRecords];
        sf::Text Rondas[_cantidadRecords];
        sf::Text Tiempos[_cantidadRecords];

    public:
        menuRecords();
        void drawTexto(sf::RenderWindow& window);
        void update(string nombres[], int rondas[], int mins[8], int segs[8]);
};

#endif // MENURECORDS_H_INCLUDED


