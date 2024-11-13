#include <cstring>
#include "arcRecords.h"


Record ArchivoRecords::leerRegistro(int pos){
    FILE *p;
    Record obj;
    p=fopen(nombre ,"rb");
    if(p==nullptr){
        return obj;
    }
    fseek(p, sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoRecords::vaciarArchivo() {
    FILE *p = fopen(nombre, "wb");
    if (p == nullptr) {
        std::cerr << "Error al abrir el archivo para vaciar." << std::endl;
        return false;
    }
    fclose(p);
    return true;
}

int ArchivoRecords::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Record);
}

int ArchivoRecords::comparaRegistros(Record newRecord){
    int cantReg = contarRegistros();
    Record obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getTime() == 0 || obj.getRondas() < newRecord.getRondas() || (obj.getTime() < newRecord.getTime() && obj.getRondas() == newRecord.getRondas())){
            modificarRegistro(obj,i+1);
            return i; ///TENGO EN CUANTA SI EL TIEMPO ESTA VACIO, SI EL OTRO JUGADOR LLEGO A MAS RONDAS Y SI EN LA MISMA RONDA EL JUGADOR HIZO MENOR TIEMPO
        }
    }
    return -898;
}

void ArchivoRecords::inicializarRegistros(){
    int cantReg = contarRegistros();
    Record obj("VACIO", 0, 0);
    if (cantReg < MAX_RECORDS){
        for(int i=cantReg; i<MAX_RECORDS; i++){
            if(!grabarRegistro(obj)) std::cout<<"noi grabo registrosd fajds";
        }
    }
}


bool ArchivoRecords::grabarRegistro(Record obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoRecords::modificarRegistro(Record obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void ArchivoRecords::listarRegistros(){
    int cantReg = contarRegistros();

    Record obj;
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);

            std::cout<<"i :"<<i<<std::endl;
            std::cout<<"cantreg :"<<cantReg<<std::endl;

            obj.mostrar();

            std::cout<<std::endl;

        }
}

std::string ArchivoRecords::getNombres(int i){
    int cantReg = contarRegistros();

    Record obj;
    obj = leerRegistro(i);

    std::cout<<"i :"<<i<<std::endl;
    std::cout<<"cantreg :"<<cantReg<<std::endl;
    return obj.getNombre();

    std::cout<<std::endl;

}

int ArchivoRecords::getTiempos(int i){
    int cantReg = contarRegistros();

    Record obj;
    obj = leerRegistro(i);

    std::cout<<"i :"<<i<<std::endl;
    std::cout<<"cantreg :"<<cantReg<<std::endl;
    return obj.getTime();

    std::cout<<std::endl;

}

int ArchivoRecords::getRondas(int i){
    int cantReg = contarRegistros();

    Record obj;
    obj = leerRegistro(i);

    std::cout<<"i :"<<i<<std::endl;
    std::cout<<"cantreg :"<<cantReg<<std::endl;
    return obj.getRondas();

    std::cout<<std::endl;

}
