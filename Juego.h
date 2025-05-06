#include "Menu.h"
#include "Loseta.h"
#include "Jugador.h"

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
    Jugador* j1;
    Jugador* j2;
    Jugador* jugador_actual;
    bool fin_del_juego {false};

    public:
    Juego(std::string nombre_j1, std::string nombre_j2, int dimension);
    /*
    Aquí va el constructor que recibe todos los atributos y los inicializa
    */
    ~Juego();

    void imprimir_tablero();
    void mostrar_estado_del_juego();
    void definir_fin_del_juego();

    bool crecer_jardin(int i, int j);
    bool regar_loseta(int i, int j);
    bool usar_jardinero(int i, int j);
    bool usar_panda(int i, int j);
    bool realizar_accion();

    void jugar();
    
};


#endif  //JUEGO_H