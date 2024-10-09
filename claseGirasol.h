#ifndef CLASEGIRASOL_H_INCLUDED
#define CLASEGIRASOL_H_INCLUDED

class Girasol
{
private:
    sf::RectangleShape _girasol;
    sf::Sprite _spriteGirasol;
    sf::Texture _girasolTexture;
    int _vida;
    unsigned int _ticsGI = 0;
    unsigned int _hitTime = 0;


public:
    Girasol();

    void cmd();
    void update();
    void posInicio(int y);
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    void hitGirasol();
    void setTexture(const sf::Texture& texture);


    sf::FloatRect getBounds() const {
        return _girasol.getGlobalBounds();
    }

    bool isAlive(){ return _vida > 0; }
};

#endif // CLASEGIRASOL_H_INCLUDED
