#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()


int randomNum()
{
    std::srand(std::time(NULL));

    // Generar un número aleatorio entre 1 y 5
    int random_number = std::rand() % 5 + 1;
    return random_number;
}

void cargarSprites();

//void cargarSprites()
//{
//    ///sprite fondo de partida
//    sf::Sprite fondo;
//    sf::Texture tex;
//    tex.loadFromFile("fondop.jpg");
//
//    fondo.setTexture(tex);
//
//    ///sprite fondo de inicio
//    sf::Sprite fondoInicio;
//    sf::Texture texInicio;
//    texInicio.loadFromFile("utnINICIO.jpg");
//
//    fondoInicio.setTexture(texInicio);
//
//    ///sprite fondo de opciones
//    sf::Sprite fondoOpciones;
//    sf::Texture texfondoOpciones;
//    texfondoOpciones.loadFromFile("fondomenuopciones.jpeg");
//
//    fondoOpciones.setTexture(texfondoOpciones);
//}

