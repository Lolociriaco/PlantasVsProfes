#ifndef CLASENUEZ_H_INCLUDED
#define CLASENUEZ_H_INCLUDED

class Nuez
{
private:
    sf::CircleShape _nuez;
    int _vida;
    unsigned int _ticsNU = 0;


public:
    Nuez();

    void cmd();
    void update();
    void posInicio(int y);
    sf::CircleShape& getDraw(sf::RenderWindow &window);
};


#endif // CLASENUEZ_H_INCLUDED
