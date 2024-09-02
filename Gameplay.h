#include <SFML/Graphics.hpp>
#include "claseZombies.h" // Asegúrate de que shape.h declare la clase Pelota


class Gameplay{
private:
    Zombie zombies[3000];            // Array de pelotas
    unsigned int _tics = 0;        // Contador de tiempo
    int _contadorPelotas = 0;      // Contador de pelotas "activas"
public:
    void cmd();
    void update();
    void draw(sf::RenderWindow &);
};

void Gameplay::cmd(){
    for(Zombie &z : zombies){
        z.cmd();
    }
}


void Gameplay::update(){
    _tics++;

    // Crear una nueva pelota cada 3 segundos (180 tics si 60 fps)
    if (_tics % (60*1) == 0 && _contadorPelotas < 3000) {
        zombies[_contadorPelotas].posInicio();  // Posición inicial de la nueva pelota
        _contadorPelotas++;  // Incrementar el contador de pelotas activas
    }

    for(int i = 0; i < _contadorPelotas; i++){
        zombies[i].update();

    }
}


void Gameplay::draw(sf::RenderWindow &window){
    for(int i = 0; i < _contadorPelotas; i++){
        window.draw(zombies[i].getDraw());
    }
}



