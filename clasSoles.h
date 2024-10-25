#include <SFML/Graphics.hpp>

class Soles
{
private:
    sf::CircleShape _shape;
    sf::Sprite _spriteSol;
    sf::Texture _solTexture;
public:
    Soles(float y, float x){
        _shape.setFillColor(sf::Color::Yellow);
        _shape.setRadius(28);
        _shape.setPosition(x, y);

        _solTexture.loadFromFile("solpvz.png");
        _spriteSol.setTexture(_solTexture);
        _spriteSol.setScale(1.f, 1.f);
    }

    bool picked();

    sf::CircleShape& getDraw(){
        return _shape;
    }

    sf::FloatRect getBounds() const { //parte de la colision
        return _shape.getGlobalBounds();
    }

    bool isClicked(sf::Vector2f mousePos){
    // Verifica si la posición del mouse está dentro de los límites de la forma del sol
    return _shape.getGlobalBounds().contains(mousePos);
    }
};


///METODOS


