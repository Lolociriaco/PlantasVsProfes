#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()


int randomNumber()
{
    // Generar un número aleatorio entre 1 y 5
    int random_number = std::rand() % 5 + 1;
    return random_number;
}



#endif // FUNCIONES_H_INCLUDED
