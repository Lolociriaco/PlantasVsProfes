#ifndef CLASENUEZ_H_INCLUDED
#define CLASENUEZ_H_INCLUDED

class Nuez
{
private:
    sf::RectangleShape _nuez;
    sf::Sprite _spriteNuez;
    sf::Sprite _shadowNuez;
    sf::Texture _nuezTexture;
    int _vida = 180;
    unsigned int _ticsNU = 0;
    unsigned int _hitTime = 0;
    int fila;
    int columna;
    sf::Color originalColor;
    sf::Clock collisionClock; // Reloj para medir el tiempo de cambio de color

public:
    Nuez();

    void cmd();
    void update();
    void posInicio(int x, int y);
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    sf::Sprite& getShadowSprite();
    void hitNutt(int damage, int profesor);
    void setTexture(const sf::Texture& texture);
    void posicionMatriz(int x, int y);
    int getFila(){return fila;}
    int getColumna(){return columna;}


    bool isAlive(){
        return _vida > 0;
    }


    sf::FloatRect getBounds() const {
        return _nuez.getGlobalBounds();
    }
};


#endif // CLASENUEZ_H_INCLUDED
