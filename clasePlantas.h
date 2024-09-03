#include <SFML/Graphics.hpp>
#include "clasLanzaguisantes.h"
#include <vector>

class Planta{
private:
    //Lanzaguisantes balas[100];
    sf::RectangleShape _plant;
    int _vida;
    int _danio;
    unsigned int _ticsPL = 0;
    std::vector<Lanzaguisantes> _guisante;

public:
    Planta();

    void cmd();
    void update();
    void posInicio(int y);
    sf::RectangleShape& getDraw(sf::RenderWindow &window);
};


