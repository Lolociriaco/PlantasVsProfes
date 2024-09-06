#include <SFML/Graphics.hpp>
#include "claseZombies.h" // Asegúrate de que shape.h declare la clase Pelota
#include "clasePlantas.h"
#include "claseNuez.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Gameplay
{
private:

    Zombie zombies[100];            // Array de pelotas
    unsigned int _ticsGm = 0;        // Contador de tiempo
    int _contadorZombies = 0;       // Contador de pelotas "activas"

    //std::vector<Planta> plant;  // Todas las plantas
    //std::vector<Zombie> zombies;  // Todos los zombies


    Planta plant[5];
    int _plantSpace = 0;

    Nuez nuez [10];
    int _nuezSpace = 0;

public:

    void cmd();
    void update();
    void draw(sf::RenderWindow &);
    void drawPlant(sf::RenderWindow &);

    void checkCollisions();



};

void Gameplay::cmd()
{

    for(Planta &p : plant)
    {
        p.cmd();
    }

    for(Zombie &z : zombies)
    {
        z.cmd();
    }

    for(Nuez &n : nuez)
    {
        n.cmd();
    }
}


void Gameplay::update()
{
    _ticsGm++;

    if (_ticsGm % (60*2) == 0 && _plantSpace < 5)
    {
        plant[_plantSpace].posInicio(_plantSpace+1);
        _plantSpace++;
    }

    for(int i = 0; i < _plantSpace; i++)
    {
        plant[i].update();

    }

    // Crear un nuevo zombie cada 3 segundos (180 tics si 60 fps)
    if (_ticsGm % (60*1) == 0 && _contadorZombies < 100)
    {
        zombies[_contadorZombies].posInicio();  // Posición inicial de la nueva pelota
        _contadorZombies++;  // Incrementar el contador de pelotas activas
    }

    for(int i = 0; i < _contadorZombies; i++)
    {
        zombies[i].update();

    }

    if (_ticsGm % (60*1) == 0 && _nuezSpace < 5)
    {
        nuez[_nuezSpace].posInicio(_nuezSpace+1);
        _nuezSpace++;
    }

    for(int i = 0; i < _nuezSpace; i++)
    {
        nuez[i].update();
    }

    checkCollisions();
}


void Gameplay::draw(sf::RenderWindow &window)
{

    for(int i = 0; i < _contadorZombies; i++)
    {
        window.draw(zombies[i].getDraw());
    }

    for(int i = 0; i < _plantSpace; i++)
    {
        plant[i].getDraw(window);
        // Dibuja las balas de cada planta
        //for(int j = 0; j < 100; j++){xz
        //    window.draw(plant[i].getBalas()[j].getDraw());
        //}
    }

    for(int i = 0; i < _nuezSpace; i++)
    {
        nuez[i].getDraw(window);
    }

}



void Gameplay::checkCollisions()
{
    // Iterar sobre todas las plantas
    for(Planta &p : plant)
    {
        // Iterar sobre todos los guisantes disparados por cada planta
        for (Lanzaguisantes& guis : p.getGuisantes())
        {
            // Obtener los límites del guisante

            // Comprobar si choca con algún zombie
            for (Zombie &z : zombies)
            {

                // Verificar si los límites del guisante intersectan con los del zombie
                if (guis.getDraw().getGlobalBounds().intersects(z.getDraw().getGlobalBounds()))
                {
                    // Aquí puedes manejar la colisión
                    std::cout << "Colisión detectada!" << std::endl;
                    p.removeGuisante(guis);

                    z.golpe();

                }
            }
        }
    }
}
