#include "menuRecords.h"

///constructor de menu
menuRecords::menuRecords()
{
    if (!fuente.loadFromFile("Samdan.ttf"))
    {
        cout<<"PEPE"<<endl;
    }

    sf::Color darkGreen(0, 100, 0);
    sf::Color softYellow(255, 223, 0);

    for(int x = 0; x < _cantidadRecords; x++){
        Texto[x].setFont(fuente);
        Texto[x].setFillColor(softYellow);
        Texto[x].setCharacterSize(80);
        Texto[x].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
        Texto[x].setOutlineThickness(3);

        Rondas[x].setFont(fuente);
        Rondas[x].setFillColor(softYellow);
        Rondas[x].setCharacterSize(80);
        Rondas[x].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
        Rondas[x].setOutlineThickness(3);

        Tiempos[x].setFont(fuente);
        Tiempos[x].setFillColor(softYellow);
        Tiempos[x].setCharacterSize(80);
        Tiempos[x].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
        Tiempos[x].setOutlineThickness(3);

    }

    cartelRecords.setFont(fuente);
    cartelRecords.setFillColor(darkGreen);
    cartelRecords.setCharacterSize(90);
    cartelRecords.setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    cartelRecords.setOutlineThickness(3);
    cartelRecords.setString("RECORDS");
    cartelRecords.setPosition(800, 60);

    cartelEnter.setFont(fuente);
    cartelEnter.setFillColor(darkGreen);
    cartelEnter.setCharacterSize(40);
    cartelEnter.setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    cartelEnter.setOutlineThickness(3);
    cartelEnter.setString("Presiona enter para volver...");
    cartelEnter.setPosition(1470, 1010);



}

///dibujar menu
void menuRecords::drawTexto(sf::RenderWindow& window)
{
    for (int i=0; i<_cantidadRecords; i++)
    {
        window.draw(Texto[i]);
        window.draw(Tiempos[i]);
        window.draw(Rondas[i]);
    }
    window.draw(cartelRecords);
    window.draw(cartelEnter);
}

void menuRecords::update(string nombres[8], int rondas[8], int tiempos[8])
{

    for(int x = 0; x < _cantidadRecords; x++){
        Texto[x].setString(nombres[x]);
        Texto[x].setPosition(500, 100*(x+2));

        Rondas[x].setString(std::to_string(rondas[x]));
        Rondas[x].setPosition(900, 100*(x+2));

        Tiempos[x].setString(std::to_string(tiempos[x]));
        Tiempos[x].setPosition(1300, 100*(x+2));
    }

}
