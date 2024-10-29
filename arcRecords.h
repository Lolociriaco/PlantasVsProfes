#ifndef ARCRECORDS_H_INCLUDED
#define ARCRECORDS_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>


class ArchivoRecords {
private:
    char nombreArchivo[100];

public:
    // Constructor que recibe el nombre del archivo
    ArchivoRecords(const char* nombre) {
        std::strcpy(nombreArchivo, nombre);
    }

    // Método para guardar un record en el archivo
    bool guardarRecord(const Record& record) {
        FILE* archivo = fopen(nombreArchivo, "ab");
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
            return false;
        }
        fwrite(&record, sizeof(Record), 1, archivo);
        fclose(archivo);
        return true;
    }

    // Método para leer un record en una posición específica
    Record leerRecord(int pos) {
        FILE* archivo = fopen(nombreArchivo, "rb");
        Record record;
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para leer." << std::endl;
            record.nombreJugador = "ERROR";
            return record;
        }
        fseek(archivo, sizeof(Record) * pos, SEEK_SET);
        fread(&record, sizeof(Record), 1, archivo);
        fclose(archivo);
        return record;
    }

    // Método para contar cuántos records hay en el archivo
    int contarRecords() {
        FILE* archivo = fopen(nombreArchivo, "rb");
        if (!archivo) {
            return 0;
        }
        fseek(archivo, 0, SEEK_END);
        int tam = ftell(archivo);
        fclose(archivo);
        return tam / sizeof(Record);
    }

    // Método para actualizar los records si el tiempo es mejor que los existentes en el top 5
    bool intentarActualizarRecord(const Record& nuevoRecord) {
        std::vector<Record> records = cargarRecords();

        // Insertar y ordenar los records para mantener solo los 5 mejores tiempos
        records.push_back(nuevoRecord);
        std::sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
            return a.tiempo < b.tiempo;
        });

        if (records.size() > 5) {
            records.resize(5);
        }

        // Guardar los records nuevamente
        FILE* archivo = fopen(nombreArchivo, "wb");
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para actualizar records." << std::endl;
            return false;
        }
        for (const auto& record : records) {
            fwrite(&record, sizeof(Record), 1, archivo);
        }
        fclose(archivo);
        return true;
    }

    // Método para cargar todos los records del archivo
    std::vector<Record> cargarRecords() {
        std::vector<Record> records;
        FILE* archivo = fopen(nombreArchivo, "rb");
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para cargar records." << std::endl;
            return records;
        }

        Record record;
        while (fread(&record, sizeof(Record), 1, archivo)) {
            records.push_back(record);
        }

        fclose(archivo);
        return records;
    }

    // Método para mostrar todos los records en consola
    void mostrarRecords() {
        std::vector<Record> records = cargarRecords();
        std::cout << "Records:" << std::endl;
        for (size_t i = 0; i < records.size(); ++i) {
            std::cout << i + 1 << ". Jugador: " << records[i].nombreJugador
                      << ", Tiempo: " << records[i].tiempo
                      << ", Rondas Jugadas: " << records[i].rondasJugadas << std::endl;
        }
    }
};

#endif // ARCRECORDS_H_INCLUDED
