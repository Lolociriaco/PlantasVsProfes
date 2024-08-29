#include <SFML/Graphics.hpp>

///DECLARACION DE ENUM PELOTA (ESTADOS DE PELOTA)

enum ESTADOS_PELOTA{
    QUIETO,
    CAMINANDO_ADELANTE,
    CAMINANDO_ATRAS,
    SALTANDO
};

///DECLARACION CLASE PELOTA

class Pelota{

private:
    sf::CircleShape _shape;
    ESTADOS_PELOTA _estado;
    float _velocidadSalto;

public:
    Pelota();

    void cmd();
    void update();
    sf::CircleShape& getDraw();
    void quieto(float x, float y);

};

///CONSTRUCTOR DE PELOTA

Pelota::Pelota(){
    _shape.setFillColor(sf::Color::Cyan);
    _shape.setRadius(50);
    _shape.setPosition(500,400);
    _estado = ESTADOS_PELOTA::QUIETO;
    _velocidadSalto = 0;
}


///METODO QUIETO
void Pelota::quieto(float x, float y){
    _estado = ESTADOS_PELOTA::QUIETO;
    _velocidadSalto = 0;
    _shape.setPosition(x,y);
}



///METODO CMD

void Pelota::cmd(){
    if(_estado == ESTADOS_PELOTA::QUIETO){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            _estado = ESTADOS_PELOTA::CAMINANDO_ADELANTE;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            _estado = ESTADOS_PELOTA::CAMINANDO_ATRAS;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            _estado = ESTADOS_PELOTA::SALTANDO;
            _velocidadSalto = 50;
        }

    }

}
///METODO UPDATE

void Pelota::update(){

    switch(_estado)
    {
    case QUIETO:

        break;

    case CAMINANDO_ADELANTE:
    _shape.move(20,0);
    _estado = ESTADOS_PELOTA::QUIETO;
        break;

    case CAMINANDO_ATRAS:
    _shape.move(-20,0);
    _estado = ESTADOS_PELOTA::QUIETO;
        break;

    case SALTANDO:
        _velocidadSalto -= 5;
        _shape.move(0, -_velocidadSalto);
        break;

    }

}

///METODO GETDRAW

sf::CircleShape& Pelota::getDraw(){
    return _shape;
}
