#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include "mainMenu.h"
#include "claseMenuOpciones.h"
#include "claseMenuIngame.h"
#include "claseCompraPlantas.h"
#include "menuRecords.h"
#include <SFML/Audio.hpp>
#include "claseMenuJugabilidad.h"

using namespace std;

enum EstadoJuego
{
    MENU,
    JUEGO,
    OPCIONES,
    PAUSAINGAME,
    RECORDS,
    JUGABILIDAD
};

int main()
{
    std::srand(std::time(NULL));

    // Obtener la resolución de pantalla actual
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en pantalla completa
    sf::RenderWindow window(desktopMode, "Pantalla Completa", sf::Style::Fullscreen);

    mainMenu menu(window.getSize().x, window.getSize().y);

    menuOpciones muestraOpciones(window.getSize().x, window.getSize().y);

    menuIngame ingameMenu(window.getSize().x, window.getSize().y);

    menuRecords objMenuRecords;

    Jugabilidad jugaMenu(window.getSize().x, window.getSize().y);

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

    ///sprite fondo menu ingame
    sf::Sprite fondoIngame;
    sf::Texture texfondoIngame;
    if (!texfondoIngame.loadFromFile("utnINICIO.jpg")) {
        cout<<"el pepe";
    }

    fondoIngame.setTexture(texfondoIngame);


    sf::Color transparentColor(255, 255, 255, 40); // 128 es semi-transparente
    fondoIngame.setColor(transparentColor);

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

    sf::Texture attackMati;
    attackMati.loadFromFile("dirubeatacando.png");

    sf::Texture maxiTex;
    maxiTex.loadFromFile("maxicaminando.png");

    sf::Texture attackMaxi;
    attackMaxi.loadFromFile("maxiatacando.png");

    sf::Texture vastagTex;
    vastagTex.loadFromFile("vastagcaminando.png");

    sf::Texture attackVastag;
    attackVastag.loadFromFile("vastagatacando.png");

    sf::Texture plantaTexture;
    plantaTexture.loadFromFile("lanzaguisantevioleta.png");  // Cambia por el nombre de tu archivo de textura

    sf::Texture nuezTexture;
    nuezTexture.loadFromFile("nuezpvp.png");  // Cambia por el nombre de tu archivo de textura

    sf::Texture girasolTexture;
    girasolTexture.loadFromFile("girasole.png");  // Cambia por el nombre de tu archivo de textura

    sf::Texture solTexture;
    solTexture.loadFromFile("solcito.png");

    bool musicaEnPausa = false;

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
                            estadoAnterior = MENU;
                            estado = OPCIONES;
                        }
                        else if (opcionElegida == 2)
                        {
                            estado = RECORDS;
                        }
                        else if (opcionElegida == 3)
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
                        std::cout<<"ENTROOOOOO";
                        juego.setRonda(0);
                        juego.setNewRecord();
                        juego.jugador.reinciarNombre();
                        estado = MENU;
                    }
                }

                if (juego.getPartidaGanada())
                {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    {
                        juego.reiniciar();
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
                            estado = OPCIONES; // Cambiar a menú de opciones
                        }
                        else if (choosenOption == 2)
                        {
                            estado = MENU; // Volver al menú principal

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
                            menu.pauseMusic();
                            juego.pauseMusicIngame();
                            musicaEnPausa = true;
                        }

                        else if (choosenOption == 1)
                        {
                            if (musicaEnPausa == true)
                            {
                                menu.playMusic();
                                juego.playMusicIngame();
                                musicaEnPausa = false;
                            }
                        }
                        else if (choosenOption == 2)
                        {
                            estado = JUGABILIDAD;
                        }
                        else if (choosenOption == 3)
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
                else if(estado == RECORDS){
                ArchivoRecords archivo("archivo.dat");
                Record record;

                std::string nombres[8];
                int mins[8];
                int segs[8];
                int rondas[8];

                for(int x = 0; x < 8; x++){
                    record = archivo.leerRegistro(x);

                    nombres[x] = record.getNombre();
                    mins[x] = record.getTime()/60;
                    segs[x] = record.getTime() % 60;
                    rondas[x] = record.getRondas();
                }

                objMenuRecords.update(nombres,rondas,mins,segs);

                if (event.type == sf::Event::KeyPressed){
                    if (event.key.code == sf::Keyboard::Return){
                        estado = MENU;
                    }
                }
            }
            else if (estado == JUGABILIDAD)
            {
                if (event.type == sf::Event::KeyPressed){
                    if (event.key.code == sf::Keyboard::Return){
                        estado = OPCIONES;
                    }
                }
            }
        }
        window.clear();

            if (estado == MENU)
            {

                juego.pauseMusicIngame();
                juego.pauseGameOver();
                if (!musicaEnPausa)
                {
                    menu.playMusic();
                }
                window.draw(fondoInicio);
                menu.draw(window);
            }
            else if (estado == JUEGO)
            {
                menu.stopMusic();
                if (!musicaEnPausa)
                {
                    juego.playMusicIngame();

                }
                juego.cmd();

                juego.update(event, window);

                window.draw(fondo);
                compra.draw(window);

                juego.setZombieTexture(matiTex, maxiTex, vastagTex, attackMati, attackVastag, attackMaxi);
                juego.setPlantaTexture(plantaTexture);
                juego.setGirasolTexture(girasolTexture, solTexture);
                juego.setSolTexture(solTexture);
                juego.setNuezTexture(nuezTexture);
                juego.draw(window);

            }
            else if (estado == OPCIONES)
            {
                window.draw(fondoOpciones);
                muestraOpciones.drawOpciones(window);
            }
            else if (estado == PAUSAINGAME)
            {
                juego.pauseMusicIngame();
                juego.pauseRSP();
                window.draw(fondoIngame);
                ingameMenu.drawOpciones(window);
            }
            else if (estado == RECORDS){
                window.draw(fondoOpciones);
                objMenuRecords.drawTexto(window);
            }
            else if (estado == JUGABILIDAD)
            {
                window.draw(fondoOpciones);
                jugaMenu.draw(window);
            }
                window.display();
        }

    return 0;
}
