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
        Texto[x].setCharacterSize(60);
        Texto[x].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
        Texto[x].setOutlineThickness(3);

        Rondas[x].setFont(fuente);
        Rondas[x].setFillColor(softYellow);
        Rondas[x].setCharacterSize(60);
        Rondas[x].setOutlineColor(sf::Color::Black);  // Agregar contorno negro
        Rondas[x].setOutlineThickness(3);

        Tiempos[x].setFont(fuente);
        Tiempos[x].setFillColor(softYellow);
        Tiempos[x].setCharacterSize(60);
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

    cartelNombre.setFont(fuente);
    cartelNombre.setFillColor(darkGreen);
    cartelNombre.setCharacterSize(65);
    cartelNombre.setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    cartelNombre.setOutlineThickness(3);
    cartelNombre.setString("Nombre");
    cartelNombre.setPosition(450, 180);

    cartelRondas.setFont(fuente);
    cartelRondas.setFillColor(darkGreen);
    cartelRondas.setCharacterSize(65);
    cartelRondas.setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    cartelRondas.setOutlineThickness(3);
    cartelRondas.setString("Ronda");
    cartelRondas.setPosition(850, 180);

    cartelTiempo.setFont(fuente);
    cartelTiempo.setFillColor(darkGreen);
    cartelTiempo.setCharacterSize(65);
    cartelTiempo.setOutlineColor(sf::Color::Black);  // Agregar contorno negro
    cartelTiempo.setOutlineThickness(3);
    cartelTiempo.setString("Tiempo");
    cartelTiempo.setPosition(1264, 180);



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
    window.draw(cartelTiempo);
    window.draw(cartelRondas);
    window.draw(cartelNombre);
}

void menuRecords::update(string nombres[8], int rondas[8], int mins[8], int segs[8])
{

    for(int x = 0; x < _cantidadRecords; x++){
        Texto[x].setString(nombres[x]);
        Texto[x].setPosition(500, 90*(x+3));

        Rondas[x].setString(std::to_string(rondas[x]));
        Rondas[x].setPosition(900, 90*(x+3));

        Tiempos[x].setString(std::to_string(mins[x]) + ":" + (segs[x] < 10 ? "0" : "") + std::to_string(segs[x]));
        Tiempos[x].setPosition(1300, 90*(x+3));
    }

}
