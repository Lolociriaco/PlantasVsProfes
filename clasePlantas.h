#include <SFML/Graphics.hpp>


class Planta{
private:
    sf::RectangleShape _square;
    int _vida;
    int _danio;

public:
    Planta();

    void cmd();
    void update();
    void disparando();
    sf::RectangleShape& getDraw();
};

