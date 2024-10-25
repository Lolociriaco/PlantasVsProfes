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

    Gameplay();
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
    void selectPlantas();
    int randomZombie();
    void generadorZombie();
    void crearZombie();
    bool round1();
    bool round2();
    bool round3();
    bool round4();
    bool round5();
    bool gameLost();
//    void cartelGameOver();

    enum PLANTA_SELECCIONADA{
        NINGUNA,
        LANZAGUISANTES,
        GIRASOL,
        NUEZ
    };

private:

    int _ticsGm = 0;        // Contador de tiempo
    int _contadorZombies = 0;
    int _ronda = 1;

    std::vector<Zombie> zombies;

    std::vector<Planta> plant;

    std::vector<Nuez> nuez;

    std::vector<Girasol> girasol;

    bool matriz[5][9] = {false};
    int fila;
    int columna;

    PLANTA_SELECCIONADA _plantaSeleccionada = NINGUNA;

    sf::RectangleShape borde0, borde1, borde2;
    sf::Texture texturaGirasol, texturaLanzaguisantes, texturaNuez;

    CompraPlanta compraPlanta;

    sf::Font font;

    int _totalSoles = 250;

    sf::Sprite fondoGameOver;
    sf::Texture texGameOver;

    sf::Text pressAnyKey;
    sf::Text gameOverText;

};

