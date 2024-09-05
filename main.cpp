#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"


using namespace std;

int main()
{
    // Obtener la resolución de pantalla actual
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en pantalla completa
    sf::RenderWindow window(desktopMode, "Pantalla Completa", sf::Style::Fullscreen);

    ///sprite lanzaguisante
    sf::Sprite lanzaguisante;
    sf::Texture lanzaguisante_text;

    lanzaguisante_text.loadFromFile("lanzaguisazul.png");

    lanzaguisante.setTexture(lanzaguisante_text);
    lanzaguisante.setPosition(482, 515);

    ///sprite nuez
    sf::Sprite nuez;
    sf::Texture nuez_text;

    nuez_text.loadFromFile("nuezpvp.png");

    nuez.setTexture(nuez_text);
    nuez.setPosition(660, 540);

    ///sprite fondo de partida
    sf::Sprite fondo;
    sf::Texture tex;
    tex.loadFromFile("fondopvz.jpg");

    fondo.setTexture(tex);

    window.setFramerateLimit(60);
    Gameplay zb;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();

        }

        zb.cmd();

        zb.update();

        window.clear();

        window.draw(fondo);
        zb.draw(window);
        window.draw(lanzaguisante);
        window.draw(nuez);

        window.display();
    }

    return 0;
}
