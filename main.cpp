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
    sf::Sprite lanzaguisanteSprite;
    sf::Texture lanzaguisante_text;

    lanzaguisante_text.loadFromFile("lanzaguisantevioleta.png");

    lanzaguisanteSprite.setTexture(lanzaguisante_text);
    lanzaguisanteSprite.setPosition(322, 515);

    ///sprite nuez
    sf::Sprite nuezSprite;
    sf::Texture nuez_text;

    nuez_text.loadFromFile("nuezpvp.png");

    nuezSprite.setTexture(nuez_text);
    nuezSprite.setPosition(470, 540);

    ///sprite de vikingo
    sf::Sprite vikingoSprite;
    sf::Texture vikingo_text;

    vikingo_text.loadFromFile("vikingo.png");

    vikingoSprite.setTexture(vikingo_text);
    vikingoSprite.setPosition(1720,200);


    ///sprite fondo de partida
    sf::Sprite fondo;
    sf::Texture tex;
    tex.loadFromFile("fondop.jpg");

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

        vikingoSprite.move(-0.5,0);

        zb.cmd();

        zb.update();

        window.clear();

        window.draw(fondo);
        zb.draw(window);

        window.draw(lanzaguisanteSprite);
        window.draw(nuezSprite);
        window.draw(vikingoSprite);

        window.display();
    }

    return 0;
}
