#include <SFML/Graphics.hpp>


class Soles
{
private:
    sf::CircleShape _shape;

public:
    Soles(float y, float x){
        _shape.setFillColor(sf::Color::Yellow);
        _shape.setRadius(28);
        _shape.setPosition(x, y);
    }

    bool picked();

    sf::CircleShape& getDraw(){
        return _shape;
    }

    sf::FloatRect getBounds() const { //parte de la colision
        return _shape.getGlobalBounds();
    }

    bool isClicked(sf::Vector2f mousePos){
    // Verifica si la posici�n del mouse est� dentro de los l�mites de la forma del sol
    return _shape.getGlobalBounds().contains(mousePos);
    }
};


///METODOS


