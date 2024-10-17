#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()


int randomNumber()
{
    std::srand(std::time(NULL));

    // Generar un número aleatorio entre 1 y 5
    int random_number = std::rand() % 5 + 1;
    return random_number;
}



