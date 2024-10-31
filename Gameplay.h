#include <SFML/Graphics.hpp>
#include "claseZombies.h" // Asegúrate de que shape.h declare la clase Pelota
#include "clasePlantas.h"
#include "claseNuez.h"
#include "cargarJugador.h"
#include "claseGirasol.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "claseCompraPlantas.h"
#include "records.h"
#include "arcRecords.h"
#include <SFML/Audio.hpp>

class Gameplay
{
public:

    Gameplay();
    void cmd();
    void update(const sf::Event& event, sf::RenderWindow &window);
    void draw(sf::RenderWindow &);
    void drawPlant(sf::RenderWindow &);
    void setZombieTexture (const sf::Texture& mati, const sf::Texture& maxi, const sf::Texture& vastag, const sf::Texture& attackTexture, const sf::Texture& attackTextureVastag, const sf::Texture& attackTextureMaxi);
    void setPlantaTexture (const sf::Texture& texture);
    void setGirasolTexture (const sf::Texture& texture, const sf::Texture& solTexture);
    void setNuezTexture (const sf::Texture& texture);
    void setSolTexture(const sf::Texture& texture);
    void reiniciar();
    void checkCollisions();
    void guisCollisions();
    void plantsCollisions();
    void selectPlantas(sf::RenderWindow &window);
    int randomZombie();
    void creadorJuego();
    bool cargarRecord(int);
    void crearZombie();
    bool round1();
    bool round2();
    bool round3();
    bool round4();
    bool round5();
    bool gameLost();
    bool gameWon();
    bool getPartidaGanada(){return partidaGanada;}
    void pausarJuego();
    enum PLANTA_SELECCIONADA{
        NINGUNA,
        LANZAGUISANTES,
        GIRASOL,
        NUEZ
    };


    int randomPos()
    {
    // Generar una posicion random de caida de sol
    int random_number = std::rand() % 1350 + 250;
    return random_number;
    }


private:

    int _ticsGm = 0;        // Contador de tiempo
    int _contadorZombies = 0;
    int _ronda = 0;

    std::vector<Zombie> zombies;

    std::vector<Soles> _sol;

    std::vector<Planta> plant;

    std::vector<Nuez> nuez;

    std::vector<Girasol> girasol;

    bool matriz[5][9] = {false};
    int fila;
    int columna;

    PLANTA_SELECCIONADA _plantaSeleccionada = NINGUNA;

    sf::RectangleShape borde0, borde1, borde2;
    sf::Texture texturaGirasol, texturaLanzaguisantes, texturaNuez, texturaSol;

    CompraPlanta compraPlanta;

    sf::Font font;

    int _totalSoles = 650;

    sf::Sprite fondoGameOver;
    sf::Texture texGameOver;

    sf::Text pressAnyKey;
    sf::Text gameOverText;

    sf::Text youWonText;
    sf::Text salvastePlantasText;

    sf::Sprite readySetPlant;
    sf::Texture texReadySetPlant;

    Jugador jugador;

    int inicioTicsCartel = _ticsGm;  // Almacena el momento de inicio para el cartel
    int duracionCartel = 180;
    bool mostrarCartel = true;
    bool roundWin = false;

    bool pausarTodo = false;

    bool win = false;

    bool juegoPausado = false;
    bool partidaGanada = false;

    int tiempo = 0;

    bool sono = true;
    bool sonoGameOver = false;
    bool nuevoZombie = false;

    sf::SoundBuffer bufferMati;
    sf::Sound soundMati;

    sf::SoundBuffer bufferMaxi;
    sf::Sound soundMaxi;

    sf::SoundBuffer bufferVastag;
    sf::Sound soundVastag;

    sf::SoundBuffer bufferPlantar;
    sf::Sound soundPlantar;

    sf::SoundBuffer bufferRSP;
    sf::Sound soundRSP;

    sf::SoundBuffer bufferWinOver;
    sf::Sound soundWinOver;
};

