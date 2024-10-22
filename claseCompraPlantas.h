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

        sf::Clock reloj; // Reloj para medir el tiempo
        int segundos; // Contador de segundos

    public:
        CompraPlanta();
        void draw(sf::RenderWindow& window);
        void setColor(const sf::Color& color);
        void actualizarContador();
};
#endif // CLASECOMPRAPLANTAS_H_INCLUDED
