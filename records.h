#ifndef RECORDS_H_INCLUDED
#define RECORDS_H_INCLUDED

class Record {
public:
    std::string nombreJugador;
    int tiempo;
    int rondasJugadas;

    Record(const std::string& nombre = "", int tiempo = 0, int rondas = 0)
        : nombreJugador(nombre), tiempo(tiempo), rondasJugadas(rondas) {}
};

#endif // RECORDS_H_INCLUDED
