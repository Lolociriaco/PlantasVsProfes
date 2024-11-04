#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



enum ESTADOS_ZOMBIES
{
    CAMINANDO,
    ATACANDO
};

enum TIPO_ZOMBIE{
    MAXI,
    MATI,
    VASTAG
};

class Zombie
{
private:
    sf::RectangleShape _shape;
    sf::Sprite _spriteVikingo;
    sf::Sprite _spriteSombra;
    sf::Texture _vikingoTexture;

    int _vida = 100;
    int _danio;
    ESTADOS_ZOMBIES _estado;
    TIPO_ZOMBIE _profe;

    sf::Texture _attackTexture;


    int _frameWidth;
    int _frameHeight;
    int _totalFrames;
    int _totalAttackFrames;
    int _currentFrame;
    float _frameDuration;
    sf::Clock _clock;       // Reloj para controlar el tiempo entre cuadros
    bool hablo = false;
    float _velocidad = -1.5;
    bool hitted = false;
    sf::Color originalColor;
    sf::Clock collisionClock; // Reloj para medir el tiempo de cambio de color

public:
    Zombie();

    sf::Sprite& getSpriteShadow();
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
    void setProfe(int profe);
    TIPO_ZOMBIE getProfe();

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
