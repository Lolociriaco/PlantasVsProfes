#ifndef LANZAGUISANTES_H
#define LANZAGUISANTES_H
#include <SFML/Graphics.hpp>


class Lanzaguisantes
{
private:
    sf::CircleShape _shape;

public:
    Lanzaguisantes(float y);


    void disparando();
    void drawBall(sf::RenderWindow &window);

    sf::CircleShape& getDraw(){
        return _shape;
    }

    sf::FloatRect getBounds() const { //parte de la colision
        return _shape.getGlobalBounds();
    }
};


#endif // LANZAGUISANTES_H

