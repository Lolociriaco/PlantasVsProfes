#ifndef RECORDS_H_INCLUDED
#define RECORDS_H_INCLUDED

#include <iostream>
#include <cstring>


class Record {
private:
    char nombreJugador[25];
    int tiempo;
    int rondasJugadas;

public:
       Record(const std::string& nombre = "", int tiempo = 0, int rondas = 0)
        : tiempo(tiempo), rondasJugadas(rondas) {
        strncpy(nombreJugador, nombre.c_str(), sizeof(nombreJugador) - 1);
        nombreJugador[sizeof(nombreJugador) - 1] = '\0'; // Asegura que el nombre esté terminado en null
    }

    int getTime(){
        return tiempo;
    }

    std::string getNombre(){
        return nombreJugador;
    }

    int getRondas(){
        return rondasJugadas;
    }


    void mostrar(){
    std::cout<<"nombre: "<<nombreJugador<<std::endl;
    std::cout<<"tiempo: "<<tiempo<<std::endl;
    std::cout<<"rondasjugadass: "<<rondasJugadas<<std::endl<<std::endl;
    }
};

#endif // RECORDS_H_INCLUDED
