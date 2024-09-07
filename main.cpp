#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include "mainMenu.h"

using namespace std;

int main()
{
    // Obtener la resolución de pantalla actual
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en pantalla completa
    sf::RenderWindow window(desktopMode, "Pantalla Completa", sf::Style::Fullscreen);
    mainMenu mainMenu(window.getSize().x, window.getSize().y);


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

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    mainMenu.moveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    mainMenu.moveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return)
                {
                    sf::RenderWindow Jugar(sf::VideoMode(desktopMode), "Plantas VS Profes");
                    sf::RenderWindow Opciones(sf::VideoMode(desktopMode), "Opciones");
                    sf::RenderWindow Salir(sf::VideoMode(desktopMode), "Salir");

                    int x = mainMenu.mainMenuPressed();
                    if (x == 0)
                    {
                        while (Jugar.isOpen())
                        {
                            sf::Event aevent;

                            while (Jugar.pollEvent(aevent))
                            {
                                if (aevent.type == sf::Event::Closed)
                                {
                                    Jugar.close();
                                }
                                if (aevent.type == sf::Event::KeyPressed)
                                {
                                    if (aevent.type == sf::Keyboard::Escape)
                                    {
                                        Jugar.close();
                                    }
                                }
                            }
                                    window.clear();

                                    Gameplay zb;
                                    zb.cmd();

                                    zb.update();

                                    window.draw(fondo);
                                    zb.draw(window);

                                    window.draw(lanzaguisanteSprite);
                                    window.draw(nuezSprite);
                                    window.draw(vikingoSprite);
                                    vikingoSprite.move(-0.5,0);

                                    window.display();
                            Opciones.close();
                            Salir.close();
                            Jugar.clear();
                            Jugar.display();
                        }
                    }
                    if (x == 1)
                    {
                        while (Opciones.isOpen())
                        {
                            sf::Event aevent;
                            while (Opciones.pollEvent(aevent))
                            {
                                if (aevent.type == sf::Event::Closed)
                                {
                                    Opciones.close();
                                }
                                if (aevent.type == sf::Event::KeyPressed)
                                {
                                    if (aevent.key.code == sf::Keyboard::Escape)
                                    {
                                        Opciones.close();
                                    }
                                }
                            }
                            Jugar.close();
                            Opciones.clear();
                            Salir.close();
                            Opciones.display();
                        }
                    }
                    if (x == 2)
                    {
                        window.close();
                        break;
                    }
                }
            }
            window.clear();
            window.draw(fondoInicio);
            mainMenu.draw(window);
            window.display();
        }




//        window.clear();
//
//        window.draw(fondo);
//        zb.draw(window);
//
//        window.draw(lanzaguisanteSprite);
//        window.draw(nuezSprite);
//        window.draw(vikingoSprite);
//
//        window.display();
    }

    return 0;
}
