#include <SFML/Graphics.hpp>
#include "claseZombies.h" // Asegúrate de que shape.h declare la clase Pelota
#include "clasePlantas.h"
#include "claseNuez.h"
#include "claseGirasol.h"
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


    std::vector<Planta> plant;
    int _plantSpace = 0;

    Nuez nuez [10];
    int _nuezSpace = 0;

    Girasol girasol [10];
    int _girasolSpace = 0;

public:

    void cmd();
    void update();
    void draw(sf::RenderWindow &);
    void drawPlant(sf::RenderWindow &);
    void setZombieTexture (const sf::Texture& texture);
    void reiniciar();
    void checkCollisions();
    void guisCollisions();
    void plantsCollisions();



};

///-----------------CMD----------------------

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

    for(Girasol &g : girasol)
    {
        g.cmd();
    }
}


///-----------------UPDATE----------------------


void Gameplay::update()
{

    ///PLANTA UPDATE

    _ticsGm++;

    if (_ticsGm % (60*1) == 0 && _plantSpace < 5)
    {
        std::cout<<"si entro xd \n";
        Planta newPlanta;
        newPlanta.posInicio(_plantSpace+1);
        plant.push_back(newPlanta);  // Agrega el nuevo zombie al vector dinámico.
        std::cout<<"plant space:"<<_plantSpace;
        _plantSpace++;
    }

    for(Planta &p : plant)
    {
        p.update();

    }

    for (unsigned int i = 0; i < plant.size(); ++i)
    {

        if (!plant[i].isAlive())
        {
            plant.erase(plant.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el índice porque hemos eliminado un elemento
            std::cout<<"IS ALIVE 2 \n";
        }
    }


    ///ZOMBIES UPDATE


    // Crear un nuevo zombie cada 3 segundos (180 tics si 60 fps)
    if (_ticsGm % (60 * 2) == 0)
    {
        Zombie newZombie;
        newZombie.posInicio();  // Configura la posición inicial del nuevo zombie.
        zombies.push_back(newZombie);  // Agrega el nuevo zombie al vector dinámico.
    }

    for(Zombie &z : zombies)
    {
        z.update();

    }

    for (unsigned int i = 0; i < zombies.size(); ++i)
    {
        if (!zombies[i].isAlive())
        {
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

    ///GIRASOL UPDATE

    if (_ticsGm % (60*1) == 0 && _girasolSpace < 5)
    {
        girasol[_girasolSpace].posInicio(_girasolSpace+1);
        _girasolSpace++;
    }

    for(int i = 0; i < _nuezSpace; i++)
    {
        girasol[i].update();
    }

    checkCollisions();
}


///-----------------DRAW----------------------



void Gameplay::draw(sf::RenderWindow &window)
{

    for (Zombie& z : zombies)
    {
        window.draw(z.getShape());
        window.draw(z.getSprite());
    }

    for(Planta &p : plant)
    {
        // Dibuja la forma geométrica
        window.draw(p.getShape());
        for (auto& guis : p.getGuisantes())
        {
            window.draw(guis.getDraw());
        }

        window.draw(p.getSprite());

    }

    for(int i = 0; i < _nuezSpace; i++)
    {
        window.draw(nuez[i].getShape());
        window.draw(nuez[i].getSprite());
    }

    for(int i = 0; i < _girasolSpace; i++)
    {
        window.draw(girasol[i].getShape());
        window.draw(girasol[i].getSprite());
    }

}

void Gameplay::setZombieTexture(const sf::Texture& texture)
{
    for (Zombie &z : zombies)
    {
        z.setTexture(texture);
    }
}


///-----------------RESTART----------------------



void Gameplay::reiniciar()
{
    _ticsGm = 0;
    _contadorZombies = 0;
    _plantSpace = 0;
    _nuezSpace = 0;
    _girasolSpace = 0;

    // Reiniciar zombies


    zombies.clear();  // Vacía el vector de zombies.


//    // Reiniciar plantas
//    for (int i = 0; i < 5; ++i)
//    {
//        plant[i].posInicio(i + 1);  // Volver a posicionar plantas
//    }
//
//    // Reiniciar nueces
//    for (int i = 0; i < 10; ++i)
//    {
//        nuez[i].posInicio(i + 1);  // Volver a posicionar nueces
//    }
//
//    // Reiniciar girasoles
//    for (int i = 0; i < 10; ++i)
//    {
//        girasol[i].posInicio(i + 1);  // Volver a posicionar girasoles
//    }

}


///-----------------CHECKCOLLISIONS----------------------



void Gameplay::checkCollisions()
{
    guisCollisions();

    plantsCollisions();

}




void Gameplay::plantsCollisions()
{
    for (Zombie &z : zombies)
    {
        bool enColision = false;  // Bandera para detectar colisión para cada zombie

        for (Planta &p : plant)
        {
            if (p.getBounds().intersects(z.getBounds()))
            {
                enColision = true;  // Si colisiona con alguna planta, se marca como true

                if (enColision)
                {
                    p.hitPlant();
                    if (z.getEstado() != ESTADOS_ZOMBIES::ATACANDO)
                    {
                        z.setEstado(ESTADOS_ZOMBIES::ATACANDO);
                        std::cout << "Zombie esta atacando\n";
                    }
                }

                break;  // No hace falta seguir verificando otras plantas para este zombie
            }
        }
        if(!enColision)
        {
            if (z.getEstado() != ESTADOS_ZOMBIES::CAMINANDO)
            {
                z.setEstado(ESTADOS_ZOMBIES::CAMINANDO);
                std::cout << "Zombie esta caminando\n";
            }
        }

        // Verifica si estaba en colisión o no para cambiar el estado solo si es necesario

    }

}


void Gameplay::guisCollisions()
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
                if (guis.getBounds().intersects(z.getBounds()))
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
