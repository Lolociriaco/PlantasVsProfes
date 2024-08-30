#include <SFML/Graphics.hpp>
#include <iostream>
#include "claseZombies.h"


using namespace std;

int main()
{
    // Obtener la resolución de pantalla actual
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en pantalla completa
    sf::RenderWindow window(desktopMode, "Pantalla Completa", sf::Style::Fullscreen);

    window.setFramerateLimit(60);
    Zombie zombie(1900, 800);
    Zombie zombie1(1900, 600);
    Zombie zombie2(1900, 400);
    Zombie zombie3(1900,200);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();

        }

        zombie.cmd();
        zombie.update();

        zombie1.cmd();
        zombie1.update();

        zombie2.cmd();
        zombie2.update();

        zombie3.cmd();
        zombie3.update();


        ///FRENAR SALTO
        if(zombie.getDraw().getPosition().x < 400){
            zombie.quieto(zombie.getDraw().getPosition().y, 400);
        }


        window.clear();
        window.draw(zombie.getDraw());
        window.draw(zombie1.getDraw());
        window.draw(zombie2.getDraw());
        window.draw(zombie3.getDraw());
        window.display();
    }

    return 0;
}
