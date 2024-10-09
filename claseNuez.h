#ifndef CLASENUEZ_H_INCLUDED
#define CLASENUEZ_H_INCLUDED

class Nuez
{
private:
    sf::RectangleShape _nuez;
    sf::Sprite _spriteNuez;
    sf::Texture _nuezTexture;
    int _vida;
    unsigned int _ticsNU = 0;
    unsigned int _hitTime = 0;


public:
    Nuez();

    void cmd();
    void update();
    void posInicio(int y);
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    void hitNutt();
    void setTexture(const sf::Texture& texture);


    bool isAlive(){
        return _vida > 0;
    }


    sf::FloatRect getBounds() const {
        return _nuez.getGlobalBounds();
    }
};


#endif // CLASENUEZ_H_INCLUDED
