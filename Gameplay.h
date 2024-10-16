#include <SFML/Graphics.hpp>
#include "claseZombies.h" // Aseg�rate de que shape.h declare la clase Pelota
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

    std::vector<Nuez> nuez;
    int _nuezSpace = 0;

    std::vector<Girasol> girasol;
    int _girasolSpace = 0;

    bool matriz[5][9] = {false};

public:

    void cmd();
    void update(const sf::Event& event, sf::RenderWindow &window);
    void draw(sf::RenderWindow &);
    void drawPlant(sf::RenderWindow &);
    void setZombieTexture (const sf::Texture& mati, const sf::Texture& maxi, const sf::Texture& vastag );
    void setPlantaTexture (const sf::Texture& texture);
    void setGirasolTexture (const sf::Texture& texture);
    void setNuezTexture (const sf::Texture& texture);
    void reiniciar();
    void checkCollisions();
    void guisCollisions();
    void plantsCollisions();
    int randomZombie(){
        std::srand(std::time(NULL));

        int random = std::rand() % 100 + 1;

        if(random > 60) return 1;

        else if(random < 20) return 2;

        else return 3;
    }


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


void Gameplay::update(const sf::Event& event,sf::RenderWindow &window)
{



    ///PLANTA UPDATE

    _ticsGm++;

    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            int fila = mousePos.y / 175; //ancho de un casillero
            int columna = mousePos.x / 145; // largo de un casillero

            if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10){
                if(matriz[fila-1][columna-2] == false)
                {
                    Planta newPlanta;
                    newPlanta.posInicio(fila, columna);
                    plant.push_back(newPlanta);  // Agrega el nuevo zombie al vector din�mico.

                    matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                    for(int x = 0; x < 5;x++){
                        for(int i = 0; i < 9; i++){
                            std::cout<<" "<<matriz[x][i];
                        }
                        std::cout<<std::endl;
                    }
                }
            }
        }
    }

//    if (_ticsGm % (60*1) == 0 && _plantSpace < 5)
//    {
//        std::cout<<"si entro xd \n";
//        Planta newPlanta;
//        newPlanta.posInicio(_plantSpace+1);
//        plant.push_back(newPlanta);  // Agrega el nuevo zombie al vector din�mico.
//        std::cout<<"plant space:"<<_plantSpace;
//        _plantSpace++;
//    }

    for(Planta &p : plant)
    {
        p.update();

    }

    for (unsigned int i = 0; i < plant.size(); ++i)
    {
        if (!plant[i].isAlive())
        {
            matriz[plant[i].getFila()][plant[i].getColumna()] = false;
            plant.erase(plant.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
            std::cout<<"IS ALIVE 2 \n";
        }
    }


    ///ZOMBIES UPDATE


    // Crear un nuevo zombie cada 3 segundos (180 tics si 60 fps)
    if (_ticsGm % (60 * 2) == 0)
    {
        Zombie newZombie;
        newZombie.posInicio();  // Configura la posici�n inicial del nuevo zombie.
        zombies.push_back(newZombie);  // Agrega el nuevo zombie al vector din�mico.
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
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
        }
    }

    ///NUEZ UPDATE

    if (_ticsGm % (60*1) == 0 && _nuezSpace < 5)
    {
        Nuez newNuez;
        newNuez.posInicio(_nuezSpace+1);  // Configura la posici�n inicial de la nueva nuez.
        nuez.push_back(newNuez);  // Agrega la nuez al vector din�mico.
        _nuezSpace++;
    }

    for (unsigned int i = 0; i < nuez.size(); ++i)
    {
        if (!nuez[i].isAlive())
        {
            nuez.erase(nuez.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
        }
    }

    for(Nuez &n : nuez)
    {
        n.update();
    }

    ///GIRASOL UPDATE

    if (_ticsGm % (60*1) == 0 && _girasolSpace < 5)
    {
        Girasol newGirasol;
        newGirasol.posInicio(_girasolSpace+1);
        girasol.push_back(newGirasol);
        _girasolSpace++;
    }

    for (unsigned int i = 0; i < girasol.size(); ++i)
    {
        if (!girasol[i].isAlive())
        {
            girasol.erase(girasol.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
        }
    }

    for(Girasol &g : girasol)/// no es nuez space MODIFICAR
    {
        g.update();
    }


    ///PREGUNTO POR COLLISIONES

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
        // Dibuja la forma geom�trica
        window.draw(p.getShape());
        for (auto& guis : p.getGuisantes())
        {
            window.draw(guis.getDraw());
        }

        window.draw(p.getSprite());

    }

    for(Nuez &n : nuez)
    {
        window.draw(n.getShape());
        window.draw(n.getSprite());
    }

    for(Girasol &g : girasol)
    {
        window.draw(g.getShape());
        window.draw(g.getSprite());
    }

}



///SETEO DE TEXTURAS


void Gameplay::setZombieTexture(const sf::Texture& mati, const sf::Texture& maxi, const sf::Texture& vastag)
{
    int random = randomZombie();

    for (size_t i = 0; i < zombies.size(); ++i)
    {
        int random = randomZombie();  // Genera un n�mero aleatorio para cada zombie

        if (random == 1) {
            zombies[i].setTexture(mati);  // Aplica la textura a cada zombie
        }
        else if (random == 2) {
            zombies[i].setTexture(vastag);
        }
        else {
            zombies[i].setTexture(maxi);
        }
    }
}


void Gameplay::setPlantaTexture(const sf::Texture& texture)
{
    for (Planta &p : plant)
    {
        p.setTexture(texture);
    }
}


void Gameplay::setGirasolTexture(const sf::Texture& texture)
{
    for (Girasol &g : girasol)
    {
        g.setTexture(texture);
    }
}


void Gameplay::setNuezTexture(const sf::Texture& texture)
{
    for (Nuez &n : nuez)
    {
        n.setTexture(texture);
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


    zombies.clear();  // Vac�a el vector de zombies.


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

//    nuttCollisions();
//
//    sunflowerCollisions();
}




void Gameplay::plantsCollisions()
{
    for (Zombie &z : zombies) ///ITERO SOBRE TODOS LOS ZOMBIES
    {
        bool enColision = false;  // Bandera para detectar colisi�n para cada zombie

        /// PREGUNTO SI HAY COLISION CON PLANTAS

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

        /// SI NO HAY COLISION CON PLANTAS PREGUNTO SI HAY COLISION CON NUECES

        if(!enColision)
        {
            for (Nuez &n : nuez)
            {
                if (n.getBounds().intersects(z.getBounds()))
                {
                    enColision = true;  // Si colisiona con alguna planta, se marca como true

                    if (enColision)
                    {
                        n.hitNutt();
                        if (z.getEstado() != ESTADOS_ZOMBIES::ATACANDO)
                        {
                            z.setEstado(ESTADOS_ZOMBIES::ATACANDO);
                            std::cout << "Zombie esta atacando\n";
                        }
                    }

                    break;  // No hace falta seguir verificando otras plantas para este zombie
                }

            }
        }


        /// SI NO HAY COLISION CON PLANTAS NI CON NUECES PREGUNTO SI HAY COLISION CON GIRASOLES

        if(!enColision)
        {
            for (Girasol &g : girasol)
            {
                if (g.getBounds().intersects(z.getBounds()))
                {
                    enColision = true;  // Si colisiona con alguna planta, se marca como true

                    if (enColision)
                    {
                        g.hitGirasol();
                        if (z.getEstado() != ESTADOS_ZOMBIES::ATACANDO)
                        {
                            z.setEstado(ESTADOS_ZOMBIES::ATACANDO);
                            std::cout << "Zombie esta atacando\n";
                        }
                    }

                    break;  // No hace falta seguir verificando otras plantas para este zombie
                }

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

        // Verifica si estaba en colisi�n o no para cambiar el estado solo si es necesario

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
            // Obtener los l�mites del guisante

            // Comprobar si choca con alg�n zombie
            for (Zombie &z : zombies)
            {

                // Verificar si los l�mites del guisante intersectan con los del zombie
                if (guis.getBounds().intersects(z.getBounds()))
                {
                    // Aqu� puedes manejar la colisi�n
                    std::cout << "Colision detectada!" << std::endl;
                    p.removeGuisante(guis);

                    z.punchZombie(); //majo

                }
            }
        }
    }
}
