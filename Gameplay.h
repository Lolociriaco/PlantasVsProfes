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

    //Zombie zombies[100];            // Array de pelotas
    unsigned int _ticsGm = 0;        // Contador de tiempo
    int _contadorZombies = 0;       // Contador de pelotas "activas"

    //std::vector<Planta> plant;  // Todas las plantas
    std::vector<Zombie> zombies;  // Todos los zombies


    Planta plant[5];
    int _plantSpace = 0;

    Nuez nuez [10];
    int _nuezSpace = 0;

public:

    void cmd();
    void update();
    void draw(sf::RenderWindow &);
    void drawPlant(sf::RenderWindow &);
    void setZombieTexture (const sf::Texture& texture);
    void reiniciar();
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

    ///PLANTA UPDATE

    _ticsGm++;

    if (_ticsGm % (60*4) == 0 && _plantSpace < 5)
    {
        plant[_plantSpace].posInicio(_plantSpace+1);
        _plantSpace++;
    }

    for(int i = 0; i < _plantSpace; i++)
    {
        plant[i].update();

    }

    ///ZOMBIES UPDATE

    /// Crear un nuevo zombie cada 3 segundos (180 tics si 60 fps)
    if (_ticsGm % (60 * 2) == 0) {
        Zombie newZombie;
        newZombie.posInicio();  // Configura la posición inicial del nuevo zombie.
        zombies.push_back(newZombie);  // Agrega el nuevo zombie al vector dinámico.
    }

    for(Zombie &z : zombies)
    {
        z.update();

    }

    for (size_t i = 0; i < zombies.size(); ++i) {
        if (!zombies[i].isAlive()) {
            zombies.erase(zombies.begin() + i);  // Eliminar zombies con vida 0
            i--;  // Ajustar el índice porque hemos eliminado un elemento
        }
    }


    ///NUEZ UPDATE


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

    for (Zombie& z : zombies) {
        window.draw(z.getShape());
        window.draw(z.getSprite());
    }

    for(int i = 0; i < _plantSpace; i++)
    {
        // Dibuja la forma geométrica
        window.draw(plant[i].getShape());
        for (auto& guis : plant[i].getGuisantes())
        {
            window.draw(guis.getDraw());
        }

        window.draw(plant[i].getSprite());

        // Dibuja los guisantes

        //plant[i].getDraw(window);
        // Dibuja las balas de cada planta
        //for(int j = 0; j < 100; j++){xz
        //    window.draw(plant[i].getBalas()[j].getDraw());
        //}
    }

    for(int i = 0; i < _nuezSpace; i++)
    {
        window.draw(nuez[i].getShape());
        window.draw(nuez[i].getSprite());
    }

}

void Gameplay::setZombieTexture(const sf::Texture& texture)
{
    for (Zombie &z : zombies)
    {
        z.setTexture(texture);
    }
}

void Gameplay::reiniciar()
{
    _ticsGm = 0;
    _contadorZombies = 0;
    _plantSpace = 0;
    _nuezSpace = 0;

    // Reiniciar zombies


    zombies.clear();  // Vacía el vector de zombies.


    // Reiniciar plantas
    for (int i = 0; i < 5; ++i)
    {
        plant[i].posInicio(i + 1);  // Volver a posicionar plantas
    }

    // Reiniciar nueces
    for (int i = 0; i < 10; ++i)
    {
        nuez[i].posInicio(i + 1);  // Volver a posicionar nueces
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
                if (guis.getDraw().getGlobalBounds().intersects(z.getShape().getGlobalBounds()))
                {
                    // Aquí puedes manejar la colisión
                    std::cout << "Colision detectada!" << std::endl;
                    p.removeGuisante(guis);

                    z.punchZombie();

                }
            }
        }
    }
}
