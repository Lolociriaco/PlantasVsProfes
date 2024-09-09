#ifndef CLASENUEZ_H_INCLUDED
#define CLASENUEZ_H_INCLUDED

class Nuez
{
private:
    sf::CircleShape _nuez;
    sf::Sprite _spriteNuez;
    sf::Texture _nuezTexture;
    int _vida;
    unsigned int _ticsNU = 0;


public:
    Nuez();

    void cmd();
    void update();
    void posInicio(int y);
    sf::CircleShape& getShape();
    sf::Sprite& getSprite();
};


#endif // CLASENUEZ_H_INCLUDED
