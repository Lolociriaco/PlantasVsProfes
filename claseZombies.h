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
    int _vida = 100;
    int _danio;
    ESTADOS_ZOMBIES _estado;

public:
    Zombie();

    void cmd();
    void update();
    void atacando();
    void posInicio();
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);
    void reiniciar();
    void punchZombie();

    bool isAlive(){ return _vida > 0;}

    sf::FloatRect getBounds() const {
        return _shape.getGlobalBounds();
    }


    //METODOS PROVISORIOS PARA MATAR AL ZOMBIE


};
