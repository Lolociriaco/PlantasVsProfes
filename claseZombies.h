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
    int _vida = 100;
    int _danio;
    ESTADOS_ZOMBIES _estado;

public:
    Zombie();

    void cmd();
    void update();
    void atacando();
    void posInicio();
    sf::RectangleShape& getDraw();

    sf::FloatRect getBounds() const {
        return _shape.getGlobalBounds();
    }


    //METODOS PROVISORIOS PARA MATAR AL ZOMBIE

    void golpe(){
        _vida -= 50;
        if(_vida < 1) zombieRemove();
    }

    void zombieRemove(){
        _shape.setFillColor(sf::Color::Black);

    }
};
