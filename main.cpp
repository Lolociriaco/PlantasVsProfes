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
        zb.draw(window);

        window.display();
    }

    return 0;
}
