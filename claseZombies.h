#include <SFML/Graphics.hpp>

enum ESTADOS_ZOMBIES
{
    CAMINANDO,
    ATACANDO
};

class Zombie
{
private:
    sf::RectangleShape _shape;
    sf::Sprite _spriteVikingo;
    sf::Texture _vikingoTexture;
//    sf::Sprite _spriteMaxi;
//    sf::Texture _maxiTexture;
//    sf::Sprite _spriteVastag;
//    sf::Texture _vastagTexture;
    int _vida = 100;
    int _danio;
    ESTADOS_ZOMBIES _estado;

    sf::Texture _attackTexture;

    // Variables para la animación del sprite
    int _frameWidth;        // Ancho de un cuadro del sprite
    int _frameHeight;       // Alto de un cuadro del sprite
    int _totalFrames;       // Total de cuadros en la animación
    int _totalAttackFrames;       // Total de cuadros en la animación
    int _currentFrame;      // Cuadro actual que se está mostrando
    float _frameDuration;   // Duración de cada cuadro en segundos
    sf::Clock _clock;       // Reloj para controlar el tiempo entre cuadros

public:
    Zombie();

    void cmd();
    void update();
    void atacando();
    void posInicio();
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);
    void setAttackTexture(const sf::Texture& attackTexture);
    void reiniciar();
    void punchZombie();

    void attackAnimation();

    bool isAlive(){ return _vida > 0;}

    sf::FloatRect getBounds() const {
        return _shape.getGlobalBounds();
    }

    float getXPosition() const {
        return getBounds().left;
    }


    void setEstado(ESTADOS_ZOMBIES estado){_estado = estado;}  // Método para modificar el estado


    ESTADOS_ZOMBIES getEstado(){return _estado;}  // Método para obtener el estado

    //METODOS PROVISORIOS PARA MATAR AL ZOMBIE

    void updateAnimation();

};
