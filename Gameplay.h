#include <SFML/Graphics.hpp>
#include "claseZombies.h" // Asegúrate de que shape.h declare la clase Pelota
#include "clasePlantas.h"
#include "claseNuez.h"
#include "claseGirasol.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "claseCompraPlantas.h"

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

    unsigned int _ticsGm = 0;        // Contador de tiempo
    int _contadorZombies = 0;

    std::vector<Zombie> zombies;

    std::vector<Planta> plant;

    std::vector<Nuez> nuez;

    std::vector<Girasol> girasol;

    bool matriz[5][9] = {false};
    int fila;
    int columna;

    PLANTA_SELECCIONADA _plantaSeleccionada = NINGUNA;

    sf::Sprite planta0;
    sf::Sprite planta1;
    sf::Sprite planta2;
    int _indicePlantaSeleccionada;

//    CompraPlanta compraPlanta;

};

