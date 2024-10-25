#ifndef CLASECOMPRAPLANTAS_H_INCLUDED
#define CLASECOMPRAPLANTAS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class CompraPlanta
{
    private:
        sf::Sprite tableroCompra;
        sf::Texture texTableroCompra;

        sf::Sprite nuezMenu;
        sf::Texture texNuezMenu;

        sf::Sprite lanzaguisanteMenu;
        sf::Texture texLanzaguisanteMenu;

        sf::Sprite girasolMenu;
        sf::Texture texGirasolMenu;

        sf::Font contador;
        sf::Text contadorRondas;

        sf::RectangleShape cuadroContador;

        sf::Text cartaGirasol;
        sf::Text cartaLanzaguisante;
        sf::Text cartaNuez;

        sf::Text tapaUTN;
        sf::Text tapaLevels;

        sf::Clock reloj; // Reloj para medir el tiempo
        int segundos = 0;
        int minutos = 0;

    public:
        CompraPlanta();
        void draw(sf::RenderWindow& window);
        void update();
        void reiniciarContador();

};
#endif // CLASECOMPRAPLANTAS_H_INCLUDED
