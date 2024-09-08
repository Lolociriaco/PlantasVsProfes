#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include "mainMenu.h"

using namespace std;

enum EstadoJuego
{
    MENU,
    JUEGO,
    OPCIONES
};

int main()
{
    // Obtener la resolución de pantalla actual
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en pantalla completa
    sf::RenderWindow window(desktopMode, "Pantalla Completa", sf::Style::Fullscreen);
    mainMenu menu(window.getSize().x, window.getSize().y);


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

    ///sprite fondo de inicio
    sf::Sprite fondoInicio;
    sf::Texture texInicio;
    texInicio.loadFromFile("fondoinicio.jpg");

    fondoInicio.setTexture(texInicio);

    EstadoJuego estado = MENU;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(estado == MENU)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        menu.moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        menu.moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Return)
                    {
                        int opcionElegida = menu.mainMenuPressed();
                        if (opcionElegida == 0)
                        {
                            estado = JUEGO;
                        }
                        else if (opcionElegida == 1)
                        {
                            estado = OPCIONES;
                        }
                        else if (opcionElegida == 2)
                        {
                            window.close();
                        }
                    }
                }
            }
            else if (estado == JUEGO)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    estado = MENU;
                }

            }
            else if (estado == OPCIONES)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    estado = MENU;
                }
            }
        }

        window.clear();

            if (estado == MENU)
            {
                window.draw(fondoInicio);
                menu.draw(window);

            }
            else if (estado == JUEGO)
            {
                Gameplay zb;
                zb.cmd();

                zb.update();

                window.draw(fondo);
                zb.draw(window);

                window.draw(lanzaguisanteSprite);
                window.draw(nuezSprite);
                window.draw(vikingoSprite);
                vikingoSprite.move(-0.5,0);
            }
            else if (estado == OPCIONES)
            {
                sf::Font opciones;
                sf::Text opcionesmenu;
                opciones.loadFromFile("Samdan.ttf");
                opcionesmenu.setFont(opciones);
                opcionesmenu.setFillColor(sf::Color::White);
                opcionesmenu.setString("NO DISPARES SOY IMBECIL :V");
                opcionesmenu.setCharacterSize(130);
                opcionesmenu.setPosition(580, 100);
                window.draw(opcionesmenu);
            }

                window.display();
        }

    return 0;
}
