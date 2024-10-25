#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include <thread>

///-----------------CONSTRUCTOR----------------------

Gameplay::Gameplay()
{
    borde0.setSize(sf::Vector2f(88, 124)); // Ajusta el tamaño según sea necesario
    borde0.setFillColor(sf::Color::Transparent);
    borde0.setOutlineColor(sf::Color::Yellow);

    borde1.setSize(sf::Vector2f(88, 124));
    borde1.setFillColor(sf::Color::Transparent);
    borde1.setOutlineColor(sf::Color::Yellow);

    borde2.setSize(sf::Vector2f(88, 124));
    borde2.setFillColor(sf::Color::Transparent);
    borde2.setOutlineColor(sf::Color::Yellow);

    borde0.setPosition(413, 12);
    borde1.setPosition(518, 12);
    borde2.setPosition(623, 12);

}

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
void Gameplay::selectPlantas(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        _plantaSeleccionada = GIRASOL;
        std::cout << "Has presionado el número 1: "<< std::endl;
        borde0.setOutlineThickness(7);
        borde1.setOutlineThickness(0);
        borde2.setOutlineThickness(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        _plantaSeleccionada = LANZAGUISANTES;
        std::cout << "Has presionado el número 2, lanza: "<< std::endl;
        borde1.setOutlineThickness(7);
        borde0.setOutlineThickness(0);
        borde2.setOutlineThickness(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        _plantaSeleccionada = NUEZ;
        std::cout << "Has presionado el número 3, nuez: "<< std::endl;
        borde2.setOutlineThickness(7);
        borde0.setOutlineThickness(0);
        borde1.setOutlineThickness(0);
    }
}

void Gameplay::update(const sf::Event& event,sf::RenderWindow &window)
{

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Obtener la posición del mouse en la ventana
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Posición del mouse en coordenadas de pantalla
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));  // Convertir a float

        for(Girasol &g : girasol){
            if (g.checkSolClick(mousePosF)) {
                std::cout << "¡Hiciste clic en un sol!" << std::endl;
                _totalSoles+=25;
                // Aquí puedes eliminar el sol o realizar otra acción
            }
        }
        // Verificar si se hizo clic en algún sol
    }

    ///COMPRA PLANTA UPDATE
    compraPlanta.update();

    ///SELECCIONADOR DE PLANTAS
    selectPlantas();


    ///PLANTA UPDATE

    _ticsGm++;

    if(_plantaSeleccionada == LANZAGUISANTES){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        std::cout << "ENTRO EN LANZAGUISTANES "<< std::endl;
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                fila = mousePos.y / 175; //ancho de un casillero
                columna = mousePos.x / 145; // largo de un casillero

                if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10)
                {
                    if(matriz[fila-1][columna-2] == false)
                    {
                        if (_totalSoles>=150)
                        {
                            _totalSoles-=150;

                            Planta newPlanta;
                            newPlanta.posInicio(fila, columna);
                            plant.push_back(newPlanta);  // Agrega el nuevo zombie al vector dinámico.

                            matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                            for(int x = 0; x < 5;x++)
                            {
                                for(int i = 0; i < 9; i++)
                                {
                                    std::cout<<" "<<matriz[x][i];
                                }
                                std::cout<<std::endl;
                            }

                        }
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
            i--;  // Ajustar el índice porque hemos eliminado un elemento
            std::cout<<"IS ALIVE 2 \n";
        }
    }


    ///ZOMBIES UPDATE


    generadorZombie();

    for(Zombie &z : zombies)
    {
        z.update();
    }

    for (unsigned int i = 0; i < zombies.size(); ++i)
    {
        if (!zombies[i].isAlive())
        {
            zombies.erase(zombies.begin() + i);  // Eliminar zombies con vida 0
            i--;  // Ajustar el índice porque hemos eliminado un elemento
        }
    }

    ///NUEZ UPDATE

    if(_plantaSeleccionada == NUEZ){

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
                    std::cout << "ENTRO EN NUEZ "<< std::endl;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                fila = mousePos.y / 175; //ancho de un casillero
                columna = mousePos.x / 145; // largo de un casillero

                if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10)
                {
                    if(matriz[fila-1][columna-2] == false)
                    {
                        if (_totalSoles>=50)
                        {
                            _totalSoles-=50;

                            Nuez newNuez;
                            newNuez.posInicio(fila,columna);  // Configura la posición inicial de la nueva nuez.
                            nuez.push_back(newNuez);  // Agrega la nuez al vector dinámico.

                            matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                            for(int x = 0; x < 5;x++)
                            {
                                for(int i = 0; i < 9; i++)
                                {
                                    std::cout<<" "<<matriz[x][i];
                                }
                                std::cout<<std::endl;
                            }

                        }
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
            i--;  // Ajustar el índice porque hemos eliminado un elemento
        }
    }

    for(Nuez &n : nuez)
    {
        n.update();
    }

    ///GIRASOL UPDATE
    if(_plantaSeleccionada == GIRASOL)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            std::cout << "ENTRO EN GIRASOL "<< std::endl;
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                fila = mousePos.y / 175; //ancho de un casillero
                columna = mousePos.x / 145; // largo de un casillero

                if(fila >= 1 && fila < 7 && columna >= 2 && columna <= 10)
                {
                    if(matriz[fila-1][columna-2] == false)
                    {
                        if (_totalSoles>=50)
                        {
                            _totalSoles-=50;

                            Girasol newGirasol;
                            newGirasol.posInicio(fila,columna);  // Configura la posición inicial de la nueva nuez.
                            girasol.push_back(newGirasol);  // Agrega la nuez al vector dinámico.

                            matriz[fila-1][columna-2] = true; //adapto la posicion a la matriz y la marco como verdadera
                            for(int x = 0; x < 5;x++)
                            {
                                for(int i = 0; i < 9; i++)
                                {
                                    std::cout<<" "<<matriz[x][i];
                                }
                                std::cout<<std::endl;
                            }

                        }
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
            i--;  // Ajustar el índice porque hemos eliminado un elemento
        }
    }

    for(Girasol &g : girasol)
    {
        g.update();
    }


    ///PREGUNTO POR COLLISIONES

    checkCollisions();
}


///-----------------RONDAS----------------------

bool Gameplay::round1()
{
    if (8 < _ticsGm / 60){//PREGUNTO SI EL TIEMPO ES MAYOR A CUATRO SEGUNDOS
        if (35 > _ticsGm / 60){
            if (_ticsGm % (60 * 6) == 0)
            {
                crearZombie();
            }
        }
        else{
            if(60 < _ticsGm / 60){
                if(zombies.size() == 0){
                    _ronda++;
                    reiniciar();
                }
            }
            else if (_ticsGm % (60 * 5) == 0){
                crearZombie();
            }
        }
    }

    if(gameLost())
    {
        return true;
    }
    return false;
}

bool Gameplay::round2()
{
    if (6 < _ticsGm / 60){  //PREGUNTO SI EL TIEMPO ES MAYOR A CUATRO SEGUNDOS
        if (35 > _ticsGm / 60){
            if (_ticsGm % (60 * 5) == 0)
            {
                crearZombie();
            }
        }
        else{
            if(70 < _ticsGm / 60){
                if(zombies.size() == 0){
                    _ronda++;
                    reiniciar();
                }
            }
            else if (_ticsGm % (60 * 4) == 0){
                crearZombie();
            }
        }
    }
    if(gameLost())
    {
        return true;
    }
    return false;
}

bool Gameplay::round3()
{
    if (5.8 < _ticsGm / 60){  //PREGUNTO SI EL TIEMPO ES MAYOR A CUATRO SEGUNDOS
        if (35 > _ticsGm / 60){
            if (_ticsGm % (60 * 5) == 0)
            {
                crearZombie();
            }
        }
        else{
            if(70 < _ticsGm / 60){
                if(zombies.size() == 0){
                    _ronda++;
                    reiniciar();
                }
            }
            else if (_ticsGm % (60 * 4) == 0){
                crearZombie();
            }
        }
    }

    if(gameLost())
    {
        return true;
    }
    return false;
}

bool Gameplay::round4()
{
    if (5.5 < _ticsGm / 60){  //PREGUNTO SI EL TIEMPO ES MAYOR A CUATRO SEGUNDOS
        if (45 > _ticsGm / 60){
            if (_ticsGm % (60 * 5) == 0)
            {
                crearZombie();
            }
        }
        else{
            if(70 < _ticsGm / 60){
                if(zombies.size() == 0){
                    _ronda++;
                    reiniciar();
                }
            }
            else if (_ticsGm % (60 * 4) == 0){
                crearZombie();
            }
        }
    }
    if(gameLost())
    {
        return true;
    }
    return false;
}

bool Gameplay::round5()
{
    if (5.1 < _ticsGm / 60){  //PREGUNTO SI EL TIEMPO ES MAYOR A CUATRO SEGUNDOS
        if (35 > _ticsGm / 60){
            if (_ticsGm % (60 * 4) == 0)
            {
                crearZombie();
            }
        }
        else{
            if(70 < _ticsGm / 60){
                if(zombies.size() == 0){
                    _ronda++;
                    reiniciar();
                }
            }
            else if (_ticsGm % (60 * 3) == 0){
                crearZombie();
            }
        }
    }
    if(gameLost())
    {
        return true;
    }
    return false;
}


bool Gameplay::gameLost(){

    for (Zombie& z : zombies)
    {
        if(z.getXPosition() < -50)
        {
            return true;
        }
    }
    return false;
}


///-----------------GENERADOR DE ZOMBIES POR RONDA----------------------


void Gameplay::generadorZombie()
{
    if (_ronda == 1) {
        if(!round1()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    } else if (_ronda == 2) {
        if(!round2()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    } else if (_ronda == 3) {
        if(!round3()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    } else if (_ronda == 4) {
        if(!round4()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    } else if (_ronda == 5) {
        if(!round5()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    }

}


void Gameplay::crearZombie(){
    Zombie newZombie;
    newZombie.posInicio();  // Configura la posición inicial del nuevo zombie.
    zombies.push_back(newZombie);  // Agrega el nuevo zombie al vector dinámico.
}

///-----------------DRAW----------------------



void Gameplay::draw(sf::RenderWindow &window)
{

    compraPlanta.draw(window);

    window.draw(borde0);
    window.draw(borde1);
    window.draw(borde2);

    sf::Color marron(139, 69, 19);
    sf::Color marronBordes(190, 89, 47);

    sf::RectangleShape cuadroSoles;
    cuadroSoles.setFillColor(marron);
    cuadroSoles.setSize(sf::Vector2f(110.f, 41.f));
    cuadroSoles.setPosition(274, 109);
    cuadroSoles.setOutlineColor(marronBordes);
    cuadroSoles.setOutlineThickness(3);

    sf::Text solesText;
    font.loadFromFile("Samdan.ttf");
    solesText.setFont(font);
    solesText.setString(std::to_string(_totalSoles));
    solesText.setCharacterSize(30);
    solesText.setFillColor(sf::Color::Black);
    solesText.setPosition(313, 114);
    solesText.setOutlineColor(sf::Color::Yellow);
    solesText.setOutlineThickness(2);

    sf::Text roundText;
    font.loadFromFile("Samdan.ttf");
    roundText.setFont(font);
    roundText.setString("ROUND " + std::to_string(_ronda));
    roundText.setCharacterSize(75);
    roundText.setFillColor(sf::Color(255, 223, 0));
    roundText.setPosition(950, 35);
    roundText.setOutlineColor(sf::Color::Black);
    roundText.setOutlineThickness(5);

    window.draw(cuadroSoles);
    window.draw(solesText);
    window.draw(roundText);


    for (Zombie& z : zombies)
    {
        window.draw(z.getShape());
        window.draw(z.getSprite());
    }

    for(Planta &p : plant)
    {
        // Dibuja la forma geométrica
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

        for(Soles &s :  g.getSoles())
        {
            window.draw(s.getDraw());
        }
    }

    if (gameLost())
    {
        texGameOver.loadFromFile("fondoGameOver.jpg");
        fondoGameOver.setTexture(texGameOver);
        font.loadFromFile("Samdan.ttf");

        gameOverText.setFont(font);
        gameOverText.setString("GAME OVER");
        gameOverText.setCharacterSize(110);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setPosition(760, 350);
        gameOverText.setOutlineColor(sf::Color::Black);
        gameOverText.setOutlineThickness(12);

        pressAnyKey.setFont(font);
        pressAnyKey.setString("PRESIONA 'ENTER' PARA CONTINUAR");
        pressAnyKey.setCharacterSize(45);
        pressAnyKey.setFillColor(sf::Color::Red);
        pressAnyKey.setPosition(695, 850);
        pressAnyKey.setOutlineColor(sf::Color::Black);
        pressAnyKey.setOutlineThickness(12);

        window.draw(fondoGameOver);
        window.draw(gameOverText);
        window.draw(pressAnyKey);
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

    zombies.clear();  // Vacía el vector de zombies.
    plant.clear();  // Vacía el vector de zombies.
    girasol.clear();  // Vacía el vector de zombies.
    nuez.clear();
    _totalSoles = 250;
    compraPlanta.reiniciarContador();

    for(int x = 0; x < 5;x++)
    {
        for(int i = 0; i < 9; i++)
        {

            std::cout<<" "<<matriz[x][i];
            matriz[x][i] = 0;
        }
            std::cout<<std::endl;
    }
}


///-----------------RANDOM ZOMBIE----------------------

int Gameplay::randomZombie()
{
        std::srand(std::time(NULL));
        int random = std::rand() % 100 + 1;
        if(random > 60) return 1;
        else if(random < 20) return 2;
        else return 3;
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
        bool enColision = false;  // Bandera para detectar colisión para cada zombie

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

        // Verifica si estaba en colisión o no para cambiar el estado solo si es necesario

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
            // Obtener los límites del guisante

            // Comprobar si choca con algún zombie
            for (Zombie &z : zombies)
            {

                // Verificar si los límites del guisante intersectan con los del zombie
                if (guis.getBounds().intersects(z.getBounds()))
                {
                    // Aquí puedes manejar la colisión
                    std::cout << "Colision detectada!" << std::endl;
                    p.removeGuisante(guis);

                    z.punchZombie(); //majo

                }
            }
        }
    }
}
