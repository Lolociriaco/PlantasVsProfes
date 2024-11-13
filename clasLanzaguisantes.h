#ifndef LANZAGUISANTES_H
#define LANZAGUISANTES_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Lanzaguisantes
{
private:
    sf::CircleShape _shape;
    sf::CircleShape _shadow;

public:
    Lanzaguisantes(float y, float x);


    void disparando();
    void drawBall(sf::RenderWindow &window);

    sf::CircleShape& getDraw(){
        return _shape;
    }

    sf::CircleShape& getShadowDraw(){
        return _shadow;
    }

    sf::FloatRect getBounds() const { //parte de la colision
        return _shape.getGlobalBounds();
    }
};


#endif // LANZAGUISANTES_H

