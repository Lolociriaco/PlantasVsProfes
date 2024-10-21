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

    enum PLANTA_SELECCIONADA{
        NINGUNA,
        LANZAGUISANTES,
        GIRASOL,
        NUEZ
    };

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
    int fila;
    int columna;

    PLANTA_SELECCIONADA _plantaSeleccionada = NINGUNA;



};

