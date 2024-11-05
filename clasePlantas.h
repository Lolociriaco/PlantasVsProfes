#include <SFML/Graphics.hpp>
#include "clasLanzaguisantes.h"
#include <vector>


class Planta
{
private:
    sf::RectangleShape _plant;
    sf::Sprite _spritePlanta;
    sf::Texture _plantaTexture;
    int _vida = 100;
    int _danio;
    unsigned int _ticsPL = 0;
    unsigned int _hitTime = 0;
    std::vector<Lanzaguisantes> _guisante;
    int fila;
    int columna;
    bool sonidoDisparado = false;

public:
    Planta();

    void cmd();
    void update();
    void posInicio(int x, int y);
    void hitPlant();
    sf::RectangleShape& getShape();
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);
    void posicionMatriz(int x, int y);
    int getFila(){return fila;}
    int getColumna(){return columna;}
    void playSound();
    bool getSonidoDisparado();
    std::vector<Lanzaguisantes>& getGuisantes();

    sf::FloatRect getBounds() const {
        return _plant.getGlobalBounds();
    }




    void removeGuisante(Lanzaguisantes& guisanteToRemove)
    {
        auto it = std::remove_if(_guisante.begin(), _guisante.end(),
                                 [&guisanteToRemove](Lanzaguisantes& guis)
        {
            return guis.getDraw().getGlobalBounds().intersects(guisanteToRemove.getDraw().getGlobalBounds());
        });
        _guisante.erase(it, _guisante.end());
    }

    bool isAlive(){
        return _vida > 0;
    }

};


