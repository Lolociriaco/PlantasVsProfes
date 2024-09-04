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
    int _vida;
    int _danio;
    ESTADOS_ZOMBIES _estado;

public:
    Zombie();

    void cmd();
    void update();
    void atacando();
    void posInicio();
    sf::RectangleShape& getDraw();
};
