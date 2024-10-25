#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include "mainMenu.h"
#include "claseMenuOpciones.h"
#include "claseMenuIngame.h"
#include "claseCompraPlantas.h"

using namespace std;

enum EstadoJuego
{
    MENU,
    JUEGO,
    OPCIONES,
    PAUSAINGAME
};

int main()
{
    std::srand(std::time(NULL));

    // Obtener la resoluci�n de pantalla actual
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en pantalla completa
    sf::RenderWindow window(desktopMode, "Pantalla Completa", sf::Style::Fullscreen);

    mainMenu menu(window.getSize().x, window.getSize().y);

    menuOpciones muestraOpciones(window.getSize().x, window.getSize().y);

    menuIngame ingameMenu(window.getSize().x, window.getSize().y);

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

    sf::Sprite fondoGameOver;
    sf::Texture texGameOver;
    texGameOver.loadFromFile("fondoGameOver.jpeg");
    fondoGameOver.setTexture(texGameOver);

    ///carga de texturas de menu compra
    CompraPlanta compra;

    sf::Sprite tableroCompra;
    sf::Texture texTableroCompra;
    texTableroCompra.loadFromFile("tableroCompra.jpg");
    tableroCompra.setTexture(texTableroCompra);

    sf::Sprite nuezMenu;
    sf::Texture texNuezMenu;
    texNuezMenu.loadFromFile("nuezMenu.jpg");
    nuezMenu.setTexture(texNuezMenu);

    sf::Sprite lanzaguisanteMenu;
    sf::Texture texLanzaguisanteMenu;
    texLanzaguisanteMenu.loadFromFile("guisantevioletaMenu.jpg");
    lanzaguisanteMenu.setTexture(texLanzaguisanteMenu);

    sf::Sprite girasolMenu;
    sf::Texture texGirasolMenu;
    texGirasolMenu.loadFromFile("girasolMenu.jpg");
    girasolMenu.setTexture(texGirasolMenu);


    EstadoJuego estado = MENU;
    EstadoJuego estadoAnterior = MENU;

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

    sf::Texture solTexture;
    solTexture.loadFromFile("solpvz.png");

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
                            if (juego.gameLost())
                            {
                                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                                {
                                    estado = MENU;
                                }
                            }
                        }
                        else if (opcionElegida == 1)
                        {
                            estadoAnterior = MENU;
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
                if (juego.gameLost())
                {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    {
                        estado = MENU;
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    estado = PAUSAINGAME;
                }
            }
            else if (estado == PAUSAINGAME)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        ingameMenu.moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        ingameMenu.moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Return)
                    {
                        int choosenOption = ingameMenu.opcionPresionada();
                        if (choosenOption == 0)
                        {
                            estado = JUEGO; // Regresa al juego
                        }
                        else if (choosenOption == 1)
                        {
                            estadoAnterior = PAUSAINGAME;
                            estado = OPCIONES; // Cambiar a men� de opciones
                        }
                        else if (choosenOption == 2)
                        {
                            estado = MENU; // Volver al men� principal
                        }
                    }
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
                            estado = estadoAnterior;
                        }
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    {
                        estado = estadoAnterior;
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
                compra.draw(window);

                juego.draw(window);
                juego.setZombieTexture(matiTex, maxiTex,vastagTex);
                juego.setPlantaTexture(plantaTexture);
                juego.setGirasolTexture(girasolTexture);
                juego.setNuezTexture(nuezTexture);

                if (juego.gameLost())
                {
                    window.draw(fondoGameOver);
                }

            }
            else if (estado == OPCIONES)
            {
                window.draw(fondoOpciones);
                muestraOpciones.drawOpciones(window);
            }
            else if (estado == PAUSAINGAME)
            {
                window.draw(fondoOpciones);
                ingameMenu.drawOpciones(window);
            }

                window.display();
        }

    return 0;
}
