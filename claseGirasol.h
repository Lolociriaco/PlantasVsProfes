#ifndef CLASEGIRASOL_H_INCLUDED
#define CLASEGIRASOL_H_INCLUDED

class Girasol
{
private:
    sf::CircleShape _girasol;
    sf::Sprite _spriteGirasol;
    sf::Texture _girasolTexture;
    int _vida;
    unsigned int _ticsGI = 0;


public:
    Girasol();

    void cmd();
    void update();
    void posInicio(int y);
    sf::CircleShape& getShape();
    sf::Sprite& getSprite();
};

#endif // CLASEGIRASOL_H_INCLUDED
