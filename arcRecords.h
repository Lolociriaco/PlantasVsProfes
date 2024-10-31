#ifndef ARCRECORDS_H_INCLUDED
#define ARCRECORDS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include "records.h"


class ArchivoRecords {
private:
    char nombre[30];
    static const int MAX_RECORDS = 8;

public:
    // Constructor que recibe el nombre del archivo
    ArchivoRecords(const char* n) {
        std::strcpy(nombre, n);
    }

    Record leerRegistro(int pos);
    int contarRegistros();
    int comparaRegistros(Record newRecord);
    bool grabarRegistro(Record obj);
    bool modificarRegistro(Record obj, int pos);
    void listarRegistros();
    void inicializarRegistros();
    bool vaciarArchivo();
    std::string getNombres(int i);
    int getRondas(int i);
    int getTiempos(int i);
};


#endif // ARCRECORDS_H_INCLUDED
