#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"


///-----------------CMD----------------------

void Gameplay::cmd()
{

    for(Planta &p : plant)
    {
        p.cmd();
    }

    for(Zombie &z : zombies)
    {
        z.cmd();
    }

    for(Nuez &n : nuez)
    {
        n.cmd();
    }

    for(Girasol &g : girasol)
    {
        g.cmd();
    }
}


///-----------------UPDATE----------------------


void Gameplay::update(const sf::Event& event,sf::RenderWindow &window)
{

    borde0.setSize(sf::Vector2f(90, 125)); // Ajusta el tama�o seg�n sea necesario
    borde0.setFillColor(sf::Color::Transparent);
    borde0.setOutlineColor(sf::Color::Yellow);
//    borde0.setOutlineThickness(0);

    borde1.setSize(sf::Vector2f(90, 125));
    borde1.setFillColor(sf::Color::Transparent);
    borde1.setOutlineColor(sf::Color::Yellow);
//    borde1.setOutlineThickness(0);

    borde2.setSize(sf::Vector2f(90, 125));
    borde2.setFillColor(sf::Color::Transparent);
    borde2.setOutlineColor(sf::Color::Yellow);
//    borde2.setOutlineThickness(0);

    compraPlanta.update();

//    borde0.setOutlineThickness(0);
//    borde1.setOutlineThickness(0);
//    borde2.setOutlineThickness(0);

    borde0.setPosition(412, 11);
    borde1.setPosition(517, 11);
    borde2.setPosition(622, 11);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        _plantaSeleccionada = GIRASOL;
        std::cout << "Has presionado el n�mero 1: "<< std::endl;
        borde0.setOutlineThickness(7);
        borde1.setOutlineThickness(0);
        borde2.setOutlineThickness(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        _plantaSeleccionada = LANZAGUISANTES;
        std::cout << "Has presionado el n�mero 2, lanza: "<< std::endl;
        borde1.setOutlineThickness(7);
        borde0.setOutlineThickness(0);
        borde2.setOutlineThickness(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        _plantaSeleccionada = NUEZ;
        std::cout << "Has presionado el n�mero 3, nuez: "<< std::endl;
        borde2.setOutlineThickness(7);
        borde0.setOutlineThickness(0);
        borde1.setOutlineThickness(0);
    }


    ///PLANTA UPDATE

    _ticsGm++;

    if(_plantaSeleccionada == LANZAGUISANTES){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "ENTRO EN LANZAGUISTANES "<< std::endl;
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                fila = mousePos.y / 175; //ancho de un casillero
                columna = mousePos.x / 145; // largo de un casillero

                if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10){
                    if(matriz[fila-1][columna-2] == false)
                    {
                        Planta newPlanta;
                        newPlanta.posInicio(fila, columna);
                        plant.push_back(newPlanta);  // Agrega el nuevo zombie al vector din�mico.

                        matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                        for(int x = 0; x < 5;x++){
                            for(int i = 0; i < 9; i++){
                                std::cout<<" "<<matriz[x][i];
                            }
                            std::cout<<std::endl;
                        }
                        //_plantaSeleccionada = NINGUNA;
                }
            }
        }
    }


    for(Planta &p : plant)
    {
        p.update();

    }

    for (unsigned int i = 0; i < plant.size(); ++i)
    {
        if (!plant[i].isAlive())
        {
            matriz[plant[i].getFila()][plant[i].getColumna()] = false;
            plant.erase(plant.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
            std::cout<<"IS ALIVE 2 \n";
        }
    }


    ///ZOMBIES UPDATE


    // Crear un nuevo zombie cada 3 segundos (180 tics si 60 fps)
    if (_ticsGm % (60 * 2) == 0)
    {
        Zombie newZombie;
        newZombie.posInicio();  // Configura la posici�n inicial del nuevo zombie.
        zombies.push_back(newZombie);  // Agrega el nuevo zombie al vector din�mico.
    }

    for(Zombie &z : zombies)
    {
        z.update();
    }

    for (unsigned int i = 0; i < zombies.size(); ++i)
    {
        if (!zombies[i].isAlive())
        {
            zombies.erase(zombies.begin() + i);  // Eliminar zombies con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
        }
    }

    ///NUEZ UPDATE

    if(_plantaSeleccionada == NUEZ){

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    std::cout << "ENTRO EN NUEZ "<< std::endl;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                fila = mousePos.y / 175; //ancho de un casillero
                columna = mousePos.x / 145; // largo de un casillero

                if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10){
                    if(matriz[fila-1][columna-2] == false)
                    {
                        Nuez newNuez;
                        newNuez.posInicio(fila,columna);  // Configura la posici�n inicial de la nueva nuez.
                        nuez.push_back(newNuez);  // Agrega la nuez al vector din�mico.

                        matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                        for(int x = 0; x < 5;x++){
                            for(int i = 0; i < 9; i++){
                                std::cout<<" "<<matriz[x][i];
                            }
                            std::cout<<std::endl;
                        }
                    //_plantaSeleccionada = NINGUNA;

                    }
                }
        }
    }


    for (unsigned int i = 0; i < nuez.size(); ++i)
    {
        if (!nuez[i].isAlive())
        {
            matriz[nuez[i].getFila()][nuez[i].getColumna()] = false;
            nuez.erase(nuez.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
        }
    }

    for(Nuez &n : nuez)
    {
        n.update();
    }

    ///GIRASOL UPDATE

        if(_plantaSeleccionada == GIRASOL){
        if (event.type == sf::Event::MouseButtonPressed) {
            std::cout << "ENTRO EN GIRASOL "<< std::endl;
            if(event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                fila = mousePos.y / 175; //ancho de un casillero
                columna = mousePos.x / 145; // largo de un casillero

                if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10){
                    if(matriz[fila-1][columna-2] == false)
                    {
                        Girasol newGirasol;
                        newGirasol.posInicio(fila,columna);  // Configura la posici�n inicial de la nueva nuez.
                        girasol.push_back(newGirasol);  // Agrega la nuez al vector din�mico.

                        matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                        for(int x = 0; x < 5;x++){
                            for(int i = 0; i < 9; i++){
                                std::cout<<" "<<matriz[x][i];
                            }
                            std::cout<<std::endl;
                        }
                        //_plantaSeleccionada = NINGUNA;

                    }
                }
            }
        }
    }

    for (unsigned int i = 0; i < girasol.size(); ++i)
    {
        if (!girasol[i].isAlive())
        {
            matriz[girasol[i].getFila()][girasol[i].getColumna()] = false;
            girasol.erase(girasol.begin() + i);  // Eliminar plantas con vida 0
            i--;  // Ajustar el �ndice porque hemos eliminado un elemento
        }
    }

    for(Girasol &g : girasol)/// no es nuez space MODIFICAR
    {
        g.update();
    }


    ///PREGUNTO POR COLLISIONES

    checkCollisions();
}


///-----------------DRAW----------------------



void Gameplay::draw(sf::RenderWindow &window)
{

    compraPlanta.draw(window);

    window.draw(borde0);
    window.draw(borde1);
    window.draw(borde2);

    for (Zombie& z : zombies)
    {
        window.draw(z.getShape());
        window.draw(z.getSprite());
    }

    for(Planta &p : plant)
    {
        // Dibuja la forma geom�trica
        window.draw(p.getShape());
        for (auto& guis : p.getGuisantes())
        {
            window.draw(guis.getDraw());
        }

        window.draw(p.getSprite());

    }

    for(Nuez &n : nuez)
    {
        window.draw(n.getShape());
        window.draw(n.getSprite());
    }

    for(Girasol &g : girasol)
    {
        window.draw(g.getShape());
        window.draw(g.getSprite());
    }

}


///SETEO DE TEXTURAS


void Gameplay::setZombieTexture(const sf::Texture& mati, const sf::Texture& maxi, const sf::Texture& vastag)
{
    int random = randomZombie();

    for (Zombie &z : zombies)
    {
        if (random == 1) z.setTexture(mati);
        else if (random == 2) z.setTexture(vastag);
        else z.setTexture(maxi);
        //z.setTexture(vastag);
    }
}


void Gameplay::setPlantaTexture(const sf::Texture& texture)
{
    for (Planta &p : plant)
    {
        p.setTexture(texture);
    }
}


void Gameplay::setGirasolTexture(const sf::Texture& texture)
{
    for (Girasol &g : girasol)
    {
        g.setTexture(texture);
    }
}


void Gameplay::setNuezTexture(const sf::Texture& texture)
{
    for (Nuez &n : nuez)
    {
        n.setTexture(texture);
    }
}




///-----------------RESTART----------------------



void Gameplay::reiniciar()
{
    _ticsGm = 0;

    // Reiniciar todos los vectores

    zombies.clear();  // Vac�a el vector de zombies.
    plant.clear();  // Vac�a el vector de zombies.
    girasol.clear();  // Vac�a el vector de zombies.
    nuez.clear();

}


///-----------------CHECKCOLLISIONS----------------------



void Gameplay::checkCollisions()
{
    guisCollisions();

    plantsCollisions();

}




void Gameplay::plantsCollisions()
{
    for (Zombie &z : zombies) ///ITERO SOBRE TODOS LOS ZOMBIES
    {
        bool enColision = false;  // Bandera para detectar colisi�n para cada zombie

        /// PREGUNTO SI HAY COLISION CON PLANTAS

        for (Planta &p : plant)
        {
            if (p.getBounds().intersects(z.getBounds()))
            {
                enColision = true;  // Si colisiona con alguna planta, se marca como true

                if (enColision)
                {
                    p.hitPlant();
                    if (z.getEstado() != ESTADOS_ZOMBIES::ATACANDO)
                    {
                        z.setEstado(ESTADOS_ZOMBIES::ATACANDO);
                        std::cout << "Zombie esta atacando\n";
                    }
                }

                break;  // No hace falta seguir verificando otras plantas para este zombie
            }
        }

        /// SI NO HAY COLISION CON PLANTAS PREGUNTO SI HAY COLISION CON NUECES

        if(!enColision)
        {
            for (Nuez &n : nuez)
            {
                if (n.getBounds().intersects(z.getBounds()))
                {
                    enColision = true;  // Si colisiona con alguna planta, se marca como true

                    if (enColision)
                    {
                        n.hitNutt();
                        if (z.getEstado() != ESTADOS_ZOMBIES::ATACANDO)
                        {
                            z.setEstado(ESTADOS_ZOMBIES::ATACANDO);
                            std::cout << "Zombie esta atacando\n";
                        }
                    }

                    break;  // No hace falta seguir verificando otras plantas para este zombie
                }

            }
        }


        /// SI NO HAY COLISION CON PLANTAS NI CON NUECES PREGUNTO SI HAY COLISION CON GIRASOLES

        if(!enColision)
        {
            for (Girasol &g : girasol)
            {
                if (g.getBounds().intersects(z.getBounds()))
                {
                    enColision = true;  // Si colisiona con alguna planta, se marca como true

                    if (enColision)
                    {
                        g.hitGirasol();
                        if (z.getEstado() != ESTADOS_ZOMBIES::ATACANDO)
                        {
                            z.setEstado(ESTADOS_ZOMBIES::ATACANDO);
                            std::cout << "Zombie esta atacando\n";
                        }
                    }

                    break;  // No hace falta seguir verificando otras plantas para este zombie
                }

            }
        }


        if(!enColision)
        {
            if (z.getEstado() != ESTADOS_ZOMBIES::CAMINANDO)
            {
                z.setEstado(ESTADOS_ZOMBIES::CAMINANDO);
                std::cout << "Zombie esta caminando\n";
            }
        }

        // Verifica si estaba en colisi�n o no para cambiar el estado solo si es necesario

    }

}


void Gameplay::guisCollisions()
{
    // Iterar sobre todas las plantas
    for(Planta &p : plant)
    {
        // Iterar sobre todos los guisantes disparados por cada planta
        for (Lanzaguisantes& guis : p.getGuisantes())
        {
            // Obtener los l�mites del guisante

            // Comprobar si choca con alg�n zombie
            for (Zombie &z : zombies)
            {

                // Verificar si los l�mites del guisante intersectan con los del zombie
                if (guis.getBounds().intersects(z.getBounds()))
                {
                    // Aqu� puedes manejar la colisi�n
                    std::cout << "Colision detectada!" << std::endl;
                    p.removeGuisante(guis);

                    z.punchZombie(); //majo

                }
            }
        }
    }
}
