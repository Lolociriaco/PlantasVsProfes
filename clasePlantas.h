#include <SFML/Graphics.hpp>
#include "clasLanzaguisantes.h"
#include <vector>

class Planta
{
private:
    //Lanzaguisantes balas[100];
    sf::RectangleShape _plant;
    sf::Sprite _spritePlanta;
    sf::Texture _plantaTexture;
    int _vida;
    int _danio;
    unsigned int _ticsPL = 0;
    std::vector<Lanzaguisantes> _guisante;

public:
    Planta();

    void cmd();
    void update();
    void posInicio(int y);
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();

    std::vector<Lanzaguisantes>& getGuisantes();


    void removeGuisante(Lanzaguisantes& guisanteToRemove)
    {
        auto it = std::remove_if(_guisante.begin(), _guisante.end(),
                                 [&guisanteToRemove](Lanzaguisantes& guis)
        {
            return guis.getDraw().getGlobalBounds().intersects(guisanteToRemove.getDraw().getGlobalBounds());
        });
        _guisante.erase(it, _guisante.end());
    }

};


