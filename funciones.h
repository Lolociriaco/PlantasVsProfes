#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

//Funciones:
int randomNum();



int randomNum(){
    std::srand(std::time(0));

    // Generar un número aleatorio entre 1 y 5
    int random_number = std::rand() % 5 + 1;
    return random_number;
}
