#ifndef CLASEMENUINGAME_H_INCLUDED
#define CLASEMENUINGAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#define MenuIngame 3

class menuIngame
{
private:
    int opcionElegida;
    sf::Font fuente;
    sf::Text Opciones[MenuIngame];

public:
    menuIngame(float width, float height);
    void drawOpciones(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    int opcionPresionada()
    {
        return opcionElegida;
    }

    ~menuIngame();
};

menuIngame::menuIngame(float width, float height)
{
    if (!fuente.loadFromFile("Samdan.ttf"))
    {
        cout << "Error al cargar fuente" << endl;
    }

    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    // Reanudar
    Opciones[0].setFont(fuente);
    Opciones[0].setFillColor(softYellow);
    Opciones[0].setString("Reanudar");
    Opciones[0].setCharacterSize(80);
    Opciones[0].setPosition(840, 300);
    Opciones[0].setOutlineColor(sf::Color::Black);
    Opciones[0].setOutlineThickness(3);

    // Opciones
    Opciones[1].setFont(fuente);
    Opciones[1].setFillColor(darkGreen);
    Opciones[1].setString("Opciones");
    Opciones[1].setCharacterSize(80);
    Opciones[1].setPosition(845, 450);
    Opciones[1].setOutlineColor(sf::Color::Black);
    Opciones[1].setOutlineThickness(3);

    // Volver al menú
    Opciones[2].setFont(fuente);
    Opciones[2].setFillColor(darkGreen);
    Opciones[2].setString("Volver al Menú");
    Opciones[2].setCharacterSize(80);
    Opciones[2].setPosition(747, 600);
    Opciones[2].setOutlineColor(sf::Color::Black);
    Opciones[2].setOutlineThickness(3);

    opcionElegida = 0;
}

menuIngame::~menuIngame()
{
}

void menuIngame::drawOpciones(sf::RenderWindow& window)
{
    for (int i = 0; i < MenuIngame; i++)
    {
        window.draw(Opciones[i]);
    }
}

void menuIngame::moveUp()
{
    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    if (opcionElegida - 1 >= 0)
    {
        Opciones[opcionElegida].setFillColor(darkGreen);
        opcionElegida--;
        Opciones[opcionElegida].setFillColor(softYellow);
    }
}

void menuIngame::moveDown()
{
    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    if (opcionElegida + 1 < MenuIngame)
    {
        Opciones[opcionElegida].setFillColor(darkGreen);
        opcionElegida++;
        Opciones[opcionElegida].setFillColor(softYellow);
    }
}

#endif // CLASEMENUINGAME_H_INCLUDED
