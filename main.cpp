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

    ///sprite fondo de partida
    sf::Sprite fondo;
    sf::Texture tex;
    tex.loadFromFile("fondop.jpg");

    fondo.setTexture(tex);

    ///sprite fondo de inicio
    sf::Sprite fondoInicio;
    sf::Texture texInicio;
    texInicio.loadFromFile("pvzfondoinicio.jpg");

    fondoInicio.setTexture(texInicio);

    EstadoJuego estado = MENU;

    window.setFramerateLimit(60);

    Gameplay juego;

    sf::Texture vikingoTex;
    vikingoTex.loadFromFile("vikingo.png");  // Cambia por el nombre de tu archivo de textura

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
                            juego.reiniciar();
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
                juego.cmd();

                juego.update();

                window.draw(fondo);
                juego.draw(window);
                juego.setZombieTexture(vikingoTex);
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
