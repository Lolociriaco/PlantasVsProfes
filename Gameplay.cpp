#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include <thread>
#include <SFML/Audio.hpp>


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


    bufferMati.loadFromFile("jejetranqui.wav");
    soundMati.setBuffer(bufferMati);
    soundPlantar.setVolume(100);

    bufferMaxi.loadFromFile("elforesunciclo.wav");
    soundMaxi.setBuffer(bufferMaxi);
    soundPlantar.setVolume(100);

    bufferVastag.loadFromFile("bienvenidavastag.wav");
    soundVastag.setBuffer(bufferVastag);
    soundPlantar.setVolume(100);

    bufferPlantar.loadFromFile("sonidoplantar.wav");
    soundPlantar.setBuffer(bufferPlantar);
    soundPlantar.setVolume(50);

    bufferRSP.loadFromFile("sonidorsp.wav");
    soundRSP.setBuffer(bufferRSP);
    soundRSP.setVolume(50);

    bufferWin.loadFromFile("sonidoWin.wav");
    soundWin.setBuffer(bufferWin);
    soundWin.setVolume(30);

    bufferGameOver.loadFromFile("defeatsound.wav");
    soundGameOver.setBuffer(bufferGameOver);
    soundGameOver.setVolume(30);

    bufferSoles.loadFromFile("sonidoGirasoles.wav");
    soundSoles.setBuffer(bufferSoles);
    soundSoles.setVolume(40);


    musicIngame.openFromFile("musicaIngame.ogg");
    musicIngame.setVolume(50);
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


///-----------------SELECIONADOR DE PLANAS CON 1,2 O 3----------------------

void Gameplay::selectPlantas(sf::RenderWindow &window){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        _plantaSeleccionada = GIRASOL;
        borde0.setOutlineThickness(7);
        borde1.setOutlineThickness(0);
        borde2.setOutlineThickness(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        _plantaSeleccionada = LANZAGUISANTES;
        borde1.setOutlineThickness(7);
        borde0.setOutlineThickness(0);
        borde2.setOutlineThickness(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        _plantaSeleccionada = NUEZ;
        borde2.setOutlineThickness(7);
        borde0.setOutlineThickness(0);
        borde1.setOutlineThickness(0);
    }


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Obtener la posición del mouse en la ventana
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Posición del mouse en coordenadas de pantalla
        int fila = mousePos.y / 140;
        int columna = (mousePos.x - 8) / 100;


        if (fila == 0) {
            if(columna == 4){
                _plantaSeleccionada = GIRASOL;
                borde0.setOutlineThickness(7);
                borde1.setOutlineThickness(0);
                borde2.setOutlineThickness(0);
            }
            if(columna == 5){
                _plantaSeleccionada = LANZAGUISANTES;
                borde1.setOutlineThickness(7);
                borde0.setOutlineThickness(0);
                borde2.setOutlineThickness(0);
            }
            if(columna == 6){
                _plantaSeleccionada = NUEZ;
                borde2.setOutlineThickness(7);
                borde0.setOutlineThickness(0);
                borde1.setOutlineThickness(0);
            }

        }
    }



}

///-----------------UPDATE----------------------

void Gameplay::update(const sf::Event& event,sf::RenderWindow &window)
{

    creadorJuego(); ///NECESARIO PARA QUE SE DESPAUSE EL JUEGO NO MOVER COQUI
    _ticsGm++;

    if (_ronda == 0){ /// CARGAR NOMBRE JUGADOR
        mostrarCartel = false;
        if(jugador.handleEvent(event)){
            _ronda++;
            reiniciar();
        }
    }

    if(pausarTodo){
        compraPlanta.enCero();
        return;
    }


    ///COMPRA PLANTA UPDATE
    compraPlanta.update();

    ///SELECCIONADOR DE PLANTAS
    selectPlantas(window);


    ///PLANTA UPDATE

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

                            soundPlantar.play();
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
//        p.playSound();
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
                            soundPlantar.play();
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
                            soundPlantar.play();
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


    //CHEQUEO PARA CUANDO PASO POR ENCIMA DE LOS SOLES

        // Obtener la posición del mouse en la ventana
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Posición del mouse en coordenadas de pantalla
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));  // Convertir a float

        for(Girasol &g : girasol){
            if (g.checkSolClick(mousePosF)) {
                soundSoles.play();
                std::cout << "¡Hiciste clic en un sol!" << std::endl;
                _totalSoles+=25;
                // Aquí puedes eliminar el sol o realizar otra acción
            }
        }

    ///UPDATE SOLES

    for(unsigned int i = 0; i < _sol.size(); ++i){
        _sol[i].solCayendo();
        if(_sol[i].isMouseOver(mousePosF)){
            soundSoles.play();
            _sol.erase(_sol.begin() + i);
            _totalSoles+=25;
        }
    }

    if(_ticsGm % 300 == 0){
        _sol.push_back(Soles(-35, randomPos()));
    }


    ///PREGUNTO POR COLLISIONES

    checkCollisions();
}



///-----------------RONDAS----------------------

bool Gameplay::round1()
{
    if (mostrarCartel)
    {
        pausarTodo = true;
        if (sono == true)
        {
            soundRSP.play();
            sono = false;
        }

        if (_ticsGm > (2 * 60)) {
            mostrarCartel = false;
            pausarTodo = false;
        }
        return false; // No continua la ronda hasta que el cartel desaparezca
    }

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
                    tiempo += compraPlanta.getSegundos();
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
    if (mostrarCartel)
    {
        pausarTodo = true;

        if (sono == true)
        {
            soundRSP.play();
            sono = false;
        }

        if (_ticsGm > (2 * 60)) {
            mostrarCartel = false;
            pausarTodo = false;
        }
        return false; // No continua la ronda hasta que el cartel desaparezca
    }


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
                    tiempo += compraPlanta.getSegundos();
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
    if (mostrarCartel)
    {
        pausarTodo = true;

        if (sono == true)
        {
            soundRSP.play();
            sono = false;
        }

        if (_ticsGm > (3 * 60)) {
            mostrarCartel = false;
            pausarTodo = false;
        }
        return false; // No continua la ronda hasta que el cartel desaparezca
    }

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
                    tiempo += compraPlanta.getSegundos();
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
    if (mostrarCartel)
    {
        pausarTodo = true;

        if (sono == true)
        {
            soundRSP.play();
            sono = false;
        }

        if (_ticsGm > (3 * 60)) {
            mostrarCartel = false;
            pausarTodo = false;
        }
        return false; // No continua la ronda hasta que el cartel desaparezca
    }

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
                    tiempo += compraPlanta.getSegundos();
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
    if (mostrarCartel)
    {
        pausarTodo = true;

        if (sono == true)
        {
            soundRSP.play();
            sono = false;
        }

        if (_ticsGm > (3 * 60)) {
            mostrarCartel = false;
            pausarTodo = false;
        }
        return false; // No continua la ronda hasta que el cartel desaparezca
    }

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
                    tiempo += compraPlanta.getSegundos();
                    _ronda++;
                    pausarTodo = true;
                    partidaGanada = true; /// DEJAR DEBAJO DE REINCIAR
                    if (!sonoGameOver)
                    {
                        soundWin.play();
                        sonoGameOver = true;
                    }

                    mostrarCartel = false; /// SOLO DEJO QUE SALGA EL CARTEL DE RONDA GANADA
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
                musicIngame.pause();
                isMusicIngamePlaying = false;
            if (!sonoGameOver)
            {
                soundGameOver.play();
                sonoGameOver = true;
            }
            return true;
        }
    }
    return false;
}

bool Gameplay::gameWon(){

    if (_ronda == 1 && win)
    {
        return true;
    }
    return false;
}

///-----------------GENERADOR DE ZOMBIES POR RONDA----------------------


void Gameplay::creadorJuego()
{

    if (_ronda == 1) {
        if(round1()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    }
    else if (_ronda == 2) {
        if(round2()){
            std::cout<<"PERDIOOOOOOO"<<std::endl;
            if(newRecord){
                cargarRecord(2);
                std::cout<<"hiciste un nuevo record"<<std::endl;
                newRecord = false;
            }
        }
    }
    else if (_ronda == 3) {
        if(round3()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    }
    else if (_ronda == 4) {
        if(round4()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    }
    else if (_ronda == 5) {
        if(round5()) std::cout<<"PERDIOOOOOOO"<<std::endl;
    }
    else if (_ronda > 5)
    {
        partidaGanada = true;
    }

}


bool Gameplay::cargarRecord(int ronda){
    ArchivoRecords arc("archivo.dat");
    Record record(jugador.getPlayerName(),tiempo,ronda);

//    arc.vaciarArchivo();
//    arc.inicializarRegistros();
//    arc.listarRegistros();


    int pos = arc.comparaRegistros(record);
    std::cout<<"POSICON "<<pos<<std::endl;    std::cout<<"POSICON "<<pos<<std::endl;    std::cout<<"POSICON "<<pos<<std::endl;
    if(pos != -1 && pos < 8 ){
        arc.modificarRegistro(record, pos);
        return true;
    }

    std::cout<<"-----------------------------------------------------------------"<<std::endl;

    arc.listarRegistros();


    return false;
}


void Gameplay::crearZombie(){
    Zombie newZombie;
    newZombie.posInicio();  // Configura la posición inicial del nuevo zombie.
    newZombie.setProfe(randomZombie());
    zombies.push_back(newZombie);  // Agrega el nuevo zombie al vector dinámico.
    nuevoZombie = true;
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
    if (_ronda>5)
    {
        roundText.setString("ROUND " + std::to_string(_ronda-1));
    }
    else
    roundText.setString("ROUND " + std::to_string(_ronda));
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
            s.update();
            window.draw(s.getDraw());
            window.draw(s.getSprite());
        }
    }

    for(Soles &s :  _sol) ///DIBUJANDO LOS SOLES QUE CAEN DEL CIELO
    {
        window.draw(s.getShape());
        window.draw(s.getSprite());
    }


    if (gameLost())
    {
            font.loadFromFile("Samdan.ttf");

            gameOverText.setFont(font);
            gameOverText.setString("GAME OVER");
            gameOverText.setCharacterSize(110);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(760, 350);
            gameOverText.setOutlineColor(sf::Color::Black);
            gameOverText.setOutlineThickness(10);

            pressAnyKey.setFont(font);
            pressAnyKey.setString("PRESIONA 'ENTER' PARA CONTINUAR");
            pressAnyKey.setCharacterSize(45);
            pressAnyKey.setFillColor(sf::Color::Red);
            pressAnyKey.setPosition(695, 850);
            pressAnyKey.setOutlineColor(sf::Color::Black);
            pressAnyKey.setOutlineThickness(7);

            window.draw(gameOverText);
            window.draw(pressAnyKey);

            pausarTodo = true;
    }


    if (partidaGanada)
    {

            font.loadFromFile("Samdan.ttf");

            gameOverText.setFont(font);
            gameOverText.setString("¡YOU WIN!");
            gameOverText.setCharacterSize(110);
            gameOverText.setFillColor(sf::Color::Green);
            gameOverText.setPosition(780, 350);
            gameOverText.setOutlineColor(sf::Color::Black);
            gameOverText.setOutlineThickness(10);

            pressAnyKey.setFont(font);
            pressAnyKey.setString("PRESIONA 'ENTER' PARA CONTINUAR");
            pressAnyKey.setCharacterSize(45);
            pressAnyKey.setFillColor(sf::Color::Green);
            pressAnyKey.setPosition(695, 850);
            pressAnyKey.setOutlineColor(sf::Color::Black);
            pressAnyKey.setOutlineThickness(7);

            window.draw(gameOverText);
            window.draw(pressAnyKey);

            pausarTodo = true;
            mostrarCartel = false; /// ?
    }

    if (mostrarCartel)
    {
        texReadySetPlant.loadFromFile("cartelReady.png");
        readySetPlant.setTexture(texReadySetPlant);
        readySetPlant.setScale(1.f, 1.f);
        readySetPlant.setPosition(800, 300);
        window.draw(readySetPlant);
    }

    if(_ronda == 0)
    {
        window.draw(jugador.getCuadro());
        window.draw(jugador.getDraw());
    }

}


///SETEO DE TEXTURAS

void Gameplay::setZombieTexture(const sf::Texture& mati, const sf::Texture& maxi, const sf::Texture& vastag, const sf::Texture& attackTexture, const sf::Texture& attackTextureVastag, const sf::Texture& attackTextureMaxi)
{
    if(zombies.size()==0) return;
    if(nuevoZombie){
        int random = randomZombie();

        if (random == 1){
            zombies[zombies.size()-1].setTexture(mati);
            zombies[zombies.size()-1].setAttackTexture(attackTexture);
        }
        else if (random == 2){
            zombies[zombies.size()-1].setTexture(vastag);
            zombies[zombies.size()-1].setAttackTexture(attackTextureVastag);
        }
        else{
            zombies[zombies.size()-1].setTexture(maxi);
            zombies[zombies.size()-1].setAttackTexture(attackTextureMaxi);
        }
        nuevoZombie = false;
    }
}


void Gameplay::setPlantaTexture(const sf::Texture& texture)
{
    for (Planta &p : plant)
    {
        p.setTexture(texture);
    }
}


void Gameplay::setGirasolTexture(const sf::Texture& texture, const sf::Texture& solTexture)
{
    for (Girasol &g : girasol)
    {
        g.setTexture(texture);

        for(Soles &s :  g.getSoles())
        {
            s.setTexture(solTexture);
        }
    }
}

void Gameplay::setSolTexture(const sf::Texture& solTexture)
{

    for(Soles &s : _sol)
    {
        s.setTexture(solTexture);
    }
}


void Gameplay::setNuezTexture(const sf::Texture& texture)
{
    for (Nuez &n : nuez)
    {
        n.setTexture(texture);
    }
}

void Gameplay::playMusicIngame()
{
    if (!isMusicIngamePlaying) {
        if (musicIngame.getStatus() == sf::SoundSource::Paused) {
            musicIngame.play(); // Reanuda si está en pausa
        } else {
            musicIngame.setLoop(true);
            musicIngame.setVolume(20.f);
            musicIngame.play();
        }
        isMusicIngamePlaying = true;
    }
}

void Gameplay::pauseMusicIngame()
{
    musicIngame.pause();
    isMusicIngamePlaying = false;
}

void Gameplay::pauseGameOver()
{
    soundGameOver.stop();
    soundWin.stop();
}

void Gameplay::pauseRSP()
{
    soundRSP.stop();
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
    _totalSoles = 300;
    compraPlanta.reiniciarContador();
    duracionCartel = 180;
    mostrarCartel = true;
    pausarTodo = true;
    juegoPausado = false;
    partidaGanada = false;
    sono = true;
    sonoGameOver = false;


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

void Gameplay::pausarJuego()
{
        zombies.clear();
        plant.clear();
        girasol.clear();
        nuez.clear();
        pausarTodo = true;
        compraPlanta.enCero();
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
                            if (z.getProfe() == MATI)
                            {
                                soundMati.play();
                            }
                            else if (z.getProfe() == VASTAG)
                            {
                                soundVastag.play();
                            }
                            else if (z.getProfe() == MAXI)
                            {
                                soundMaxi.play();
                            }

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
                            if (z.getProfe() == MATI)
                            {
                                soundMati.play();
                            }
                            else if (z.getProfe() == VASTAG)
                            {
                                soundVastag.play();
                            }
                            else if (z.getProfe() == MAXI)
                            {
                                soundMaxi.play();
                            }

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
                            if (z.getProfe() == MATI)
                            {
                                soundMati.play();
                            }
                            else if (z.getProfe() == VASTAG)
                            {
                                soundVastag.play();
                            }
                            else if (z.getProfe() == MAXI)
                            {
                                soundMaxi.play();
                            }

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
