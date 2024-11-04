#ifndef CLASEMENUJUGABILIDAD_H_INCLUDED
#define CLASEMENUJUGABILIDAD_H_INCLUDED
#include <SFML/Graphics.hpp>

class Jugabilidad
{
    public:
        Jugabilidad(float width, float height);
        void draw(sf::RenderWindow& window);

    private:
        sf::Font font;
        sf::Text controlText;
        sf::Text cartelEnter;
        sf::Text navegacion;
        sf::Text opcionesNav;
        sf::Text seleccion;
        sf::Text opcionesSeleccion;
        sf::Text colocacion;
        sf::Text opcionesColocacion;
        sf::Text captura;
        sf::Text opcionesCaptura;
        sf::Text menuPausa;
        sf::Text opcionesMenu;
};

Jugabilidad::Jugabilidad(float width, float height)
{
    if (!font.loadFromFile("Samdan.ttf")) {
        // Manejar error al cargar la fuente
    }
    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    navegacion.setFont(font);
    navegacion.setString("Navegacion de Menus:");
    navegacion.setCharacterSize(45);
    navegacion.setFillColor(darkGreen);
    navegacion.setPosition(30, 10);
    navegacion.setOutlineColor(sf::Color::Black);
    navegacion.setOutlineThickness(3);

    opcionesNav.setFont(font);
    opcionesNav.setString("- Flechas (UP - DOWN): Navegar por las opciones del menu.");
    opcionesNav.setCharacterSize(35);
    opcionesNav.setFillColor(softYellow);
    opcionesNav.setPosition(30, 90);
    opcionesNav.setOutlineColor(sf::Color::Black);
    opcionesNav.setOutlineThickness(3);

    seleccion.setFont(font);
    seleccion.setString("Seleccion de Plantas:");
    seleccion.setCharacterSize(45);
    seleccion.setFillColor(darkGreen);
    seleccion.setPosition(30, 170);
    seleccion.setOutlineColor(sf::Color::Black);
    seleccion.setOutlineThickness(3);

    opcionesSeleccion.setFont(font);
    opcionesSeleccion.setString("1: Seleccionar girasol.\n"
                                "2: Seleccionar lanzaguisante.\n"
                                "3: Seleccionar nuez.\n"
                                "Mouse: Click izquierdo sobre la planta para seleccionar.");
    opcionesSeleccion.setCharacterSize(35);
    opcionesSeleccion.setFillColor(softYellow);
    opcionesSeleccion.setPosition(30, 250);
    opcionesSeleccion.setOutlineColor(sf::Color::Black);
    opcionesSeleccion.setOutlineThickness(3);

    colocacion.setFont(font);
    colocacion.setString("Colocacion de Plantas en el Jardin:");
    colocacion.setCharacterSize(45);
    colocacion.setFillColor(darkGreen);
    colocacion.setPosition(30, 460);
    colocacion.setOutlineColor(sf::Color::Black);
    colocacion.setOutlineThickness(3);

    opcionesColocacion.setFont(font);
    opcionesColocacion.setString("Mouse: Click izquierdo sobre la posicion deseada.");
    opcionesColocacion.setCharacterSize(35);
    opcionesColocacion.setFillColor(softYellow);
    opcionesColocacion.setPosition(30, 540);
    opcionesColocacion.setOutlineColor(sf::Color::Black);
    opcionesColocacion.setOutlineThickness(3);

    captura.setFont(font);
    captura.setString("Captura de Soles:");
    captura.setCharacterSize(45);
    captura.setFillColor(darkGreen);
    captura.setPosition(30, 620);
    captura.setOutlineColor(sf::Color::Black);
    captura.setOutlineThickness(3);

    opcionesCaptura.setFont(font);
    opcionesCaptura.setString("Mouse: Posicionar cursor sobre el sol para capturarlo.");
    opcionesCaptura.setCharacterSize(35);
    opcionesCaptura.setFillColor(softYellow);
    opcionesCaptura.setPosition(30, 710);
    opcionesCaptura.setOutlineColor(sf::Color::Black);
    opcionesCaptura.setOutlineThickness(3);

    menuPausa.setFont(font);
    menuPausa.setString("Menu de Pausa:");
    menuPausa.setCharacterSize(45);
    menuPausa.setFillColor(darkGreen);
    menuPausa.setPosition(30, 790);
    menuPausa.setOutlineColor(sf::Color::Black);
    menuPausa.setOutlineThickness(3);

    opcionesMenu.setFont(font);
    opcionesMenu.setString("ESCAPE: Abrir el menu de pausa.");
    opcionesMenu.setCharacterSize(35);
    opcionesMenu.setFillColor(softYellow);
    opcionesMenu.setPosition(30, 870);
    opcionesMenu.setOutlineColor(sf::Color::Black);
    opcionesMenu.setOutlineThickness(3);

    cartelEnter.setFont(font);
    cartelEnter.setFillColor(darkGreen);
    cartelEnter.setCharacterSize(40);
    cartelEnter.setOutlineColor(sf::Color::Black);
    cartelEnter.setOutlineThickness(3);
    cartelEnter.setString("Presiona enter para volver...");
    cartelEnter.setPosition(1470, 1010);
}

void Jugabilidad::draw(sf::RenderWindow& window) {
    window.draw(navegacion);
    window.draw(opcionesNav);
    window.draw(seleccion);
    window.draw(opcionesSeleccion);
    window.draw(colocacion);
    window.draw(opcionesColocacion);
    window.draw(captura);
    window.draw(opcionesCaptura);
    window.draw(menuPausa);
    window.draw(opcionesMenu);
    window.draw(cartelEnter);
}
#endif // CLASEMENUJUGABILIDAD_H_INCLUDED
