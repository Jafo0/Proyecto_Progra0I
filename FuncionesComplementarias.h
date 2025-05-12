#ifndef FUNCIONESCOMPLEMENTARIAS_H
#define FUNCIONESCOMPLEMENTARIAS_H
#include <string>
#include <fstream>
#include "Juego.h"
#include "Jugador.h"

    int desplegar();
    int menu_mov();

    
    //Lee una línea y me regresa un puntero a arreglo de strings con los valores de la línea separados por coma
    std::string* lector(int, std::string);

    Jugador* leer_jugador(std::ifstream&);
    int* leer_personaje(std::ifstream&);
    Loseta* leer_loseta(std::ifstream&);
    Juego* leer_juego(std::ifstream&, Jugador*, Jugador*, int*, int*);
    
    Juego* cargar_juego();

#endif //FUNCIONESCOMPLEMENTARIAS_H