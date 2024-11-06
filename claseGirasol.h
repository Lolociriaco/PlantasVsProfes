#ifndef CLASEGIRASOL_H_INCLUDED
#define CLASEGIRASOL_H_INCLUDED
#include "clasSoles.h"

class Girasol
{
private:
    sf::RectangleShape _girasol;
    sf::Sprite _spriteGirasol;
    sf::Sprite _shadowGirasol;
    sf::Texture _girasolTexture;

    int _vida = 100;
    unsigned int _ticsGI = 0;
    unsigned int _hitTime = 0;
    int fila;
    int columna;
    std::vector<Soles> _sol;
    sf::Color originalColor;
    sf::Clock collisionClock; // Reloj para medir el tiempo de cambio de color

public:
    Girasol();

    void cmd();
    void update();
    void posInicio(int x, int y);
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    sf::Sprite& getShadowSprite();
    void hitGirasol(int damage, int profesor);
    void setTexture(const sf::Texture& texture);
    void posicionMatriz(int x, int y);
    int getFila(){return fila;}
    int getColumna(){return columna;}
    std::vector<Soles>& getSoles();
    bool checkSolClick(sf::Vector2f mousePos);
    void playSound();

    sf::FloatRect getBounds() const {
        return _girasol.getGlobalBounds();
    }

    bool isAlive(){ return _vida > 0; }
};

#endif // CLASEGIRASOL_H_INCLUDED
