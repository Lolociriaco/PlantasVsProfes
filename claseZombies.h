#include <SFML/Graphics.hpp>

enum ESTADOS_ZOMBIES{
    CAMINANDO,
    ATACANDO,
    QUIETO
};


class Zombie{
private:
    sf::RectangleShape _shape;
    int _vida;
    int _danio;
    ESTADOS_ZOMBIES _estado;

public:
    Zombie(float x, float y);

    void cmd();
    void update();
    void atacando();
    void quieto(float x, float y);
    sf::RectangleShape& getDraw();
};
