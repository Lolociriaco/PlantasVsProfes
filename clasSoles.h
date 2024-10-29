#include <SFML/Graphics.hpp>

class Soles
{
private:
    sf::CircleShape _shape;
    sf::Sprite _spriteSol;
    sf::Texture _solTexture;

    float initialY;      // Posición inicial en Y para el salto
    bool movingUp;       // Controla si el sol está subiendo o bajando
    float jumpHeight;    // Altura máxima del salto
    float jumpSpeed;

    sf::Clock inputClock; // Reloj para gestionar la animacion


public:
    Soles(float y, float x) : movingUp(true), jumpHeight(10.f), jumpSpeed(0.22f){
        _shape.setFillColor(sf::Color::Transparent);
        _shape.setRadius(28);
        _shape.setPosition(x, y);

        _solTexture.loadFromFile("solcito.png");
        _spriteSol.setTexture(_solTexture);
        _spriteSol.setScale(1.f, 1.f);
        _spriteSol.setPosition(x, y);

        initialY = y;
    }

    bool picked();

    sf::CircleShape& getDraw(){
        return _shape;
    }

    sf::Sprite& getSprite(){
        return _spriteSol;
    }

    sf::FloatRect getBounds() const { //parte de la colision
        return _shape.getGlobalBounds();
    }

    bool isClicked(sf::Vector2f mousePos){
    // Verifica si la posición del mouse está dentro de los límites de la forma del sol
    return _shape.getGlobalBounds().contains(mousePos);
    }

    void setTexture(const sf::Texture& texture)
    {
        _spriteSol.setTexture(texture);
    }

    void update() {
        if (movingUp) {
            // Mueve hacia arriba
            _spriteSol.move(0, -jumpSpeed);
            if (_spriteSol.getPosition().y <= initialY - jumpHeight) {
                movingUp = false;  // Cambia a bajada
            }
        } else{
            // Mueve hacia abajo
            _spriteSol.move(0, jumpSpeed);
            if (_spriteSol.getPosition().y >= initialY) {
                _spriteSol.setPosition(_spriteSol.getPosition().x, initialY); // Ajuste final
                movingUp = true;
            }
        }
        inputClock.restart();
    }

};


///METODOS


