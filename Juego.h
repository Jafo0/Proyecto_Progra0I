#include "Menu.h"
#include "Loseta.h"

#include <iostream>
#include <string>

#ifndef JUEGO_H
#define JUEGO_H



class Juego{
    private:
    Loseta*** tablero;
    Menu* menu;
    int panda[2] {-1,-1};
    int jardinero[2] {-1,-1};
    int dimension_tablero;


    public:
    Juego(int dimension);
    ~Juego();

    void crecer_jardin();
    void regar_loseta();
    void usar_jardinero();
    void usar_panda();

    void jugar(std::string nombre_j1, std::string nombre_j2);
    void imprimir_tablero();
};


#endif  //JUEGO_H