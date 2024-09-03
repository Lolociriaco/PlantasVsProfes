#ifndef LANZAGUISANTES_H
#define LANZAGUISANTES_H
#include <SFML/Graphics.hpp>


class Lanzaguisantes{
private:
    sf::CircleShape _shape;

public:
    Lanzaguisantes(float y);
    void disparando();
    void drawBall(sf::RenderWindow &window);

    //PARA MAS ADELANTE sf::Vector2f getPosicion() {
    //PARA MAS ADELANTE     return shape.getPosition();
    //PARA MAS ADELANTE }
};


#endif // LANZAGUISANTES_H

