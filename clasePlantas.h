enum ESTADOS_ZOMBIES{
    CAMINANDO,
    ATACANDO
};


class Zombie{
private:
    sf::RectangleShape _square;
    int _vida;
    int _danio;
    ESTADOS_ZOMBIES _estado;

public:
    Zombie();

    void cmd();
    void update();
    void atacando();
    sf::CircleShape& getDraw();
};

