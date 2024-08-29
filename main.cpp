#include <SFML/Graphics.hpp>
#include <iostream>
#include "shape.h"


using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    Pelota p;



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();

        }

        p.cmd();

        p.update();

        ///FRENAR SALTO
        if(p.getDraw().getPosition().y > 400){
            p.quieto(p.getDraw().getPosition().x, 400);
        }


        window.clear();
        window.draw(p.getDraw());
        window.display();
    }

    return 0;
}
