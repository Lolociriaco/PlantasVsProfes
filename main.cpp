#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include "mainMenu.h"
#include "claseMenuOpciones.h"

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

    menuOpciones muestraOpciones(window.getSize().x, window.getSize().y);

    ///sprite fondo de partida
    sf::Sprite fondo;
    sf::Texture tex;
    tex.loadFromFile("fondop.jpg");

    fondo.setTexture(tex);

    ///sprite fondo de inicio
    sf::Sprite fondoInicio;
    sf::Texture texInicio;
    texInicio.loadFromFile("utnINICIO.jpg");

    fondoInicio.setTexture(texInicio);

    ///sprite fondo de opciones
    sf::Sprite fondoOpciones;
    sf::Texture texfondoOpciones;
    texfondoOpciones.loadFromFile("OpcionesMenu.jpg");

    fondoOpciones.setTexture(texfondoOpciones);


    EstadoJuego estado = MENU;

    window.setFramerateLimit(60);


    Gameplay juego;

    sf::Texture matiTex;
    matiTex.loadFromFile("dirubecaminando.png");  // Cambia por el nombre de tu archivo de textura

    sf::Texture maxiTex;
    maxiTex.loadFromFile("maxicaminando.png");

    sf::Texture vastagTex;
    vastagTex.loadFromFile("vastagcaminando.png");

    sf::Texture plantaTexture;
    plantaTexture.loadFromFile("lanzaguisantevioleta.png");  // Cambia por el nombre de tu archivo de textura

    sf::Texture nuezTexture;
    nuezTexture.loadFromFile("nuezpvp.png");  // Cambia por el nombre de tu archivo de textura

    sf::Texture girasolTexture;
    girasolTexture.loadFromFile("girasole.png");  // Cambia por el nombre de tu archivo de textura


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

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        muestraOpciones.moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        muestraOpciones.moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Return)
                    {
                        int choosenOption = muestraOpciones.opcionPresionada();
                        if (choosenOption == 0)
                        {

                        }
                        else if (choosenOption == 1)
                        {

                        }
                        else if (choosenOption == 2)
                        {
                            estado = MENU;
                        }
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    {
                        estado = MENU;
                    }
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

                juego.update(event, window);

                window.draw(fondo);
                juego.draw(window);

                juego.setZombieTexture(matiTex, maxiTex,vastagTex);
                juego.setPlantaTexture(plantaTexture);
                juego.setGirasolTexture(girasolTexture);
                juego.setNuezTexture(nuezTexture);

            }
            else if (estado == OPCIONES)
            {
                window.draw(fondoOpciones);
                muestraOpciones.drawOpciones(window);
            }

                window.display();
        }

    return 0;
}
