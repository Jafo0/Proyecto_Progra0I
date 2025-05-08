#include "Menu.h"
#include "Loseta.h"
#include "Jugador.h"

#include <iostream>
#include <string>

#ifndef JUEGO_H
#define JUEGO_H



class Juego{
    private:
    int panda[2] {-1,-1};
    int jardinero[2] {-1,-1};
    int dimension_tablero {9};
    int espacio_texto {6};  //Necesario para imprimir el tablero
    int puntos_juego {5};
    bool fin_del_juego {false};
    Loseta*** tablero;
    Menu* menu;
    Jugador* j1;
    Jugador* j2;
    Jugador* jugador_actual;
    

    public:
    Juego(std::string, std::string, int, int);
	Juego(Jugador*, Jugador*, int, int, int, int, int, Menu*, Jugador*, Loseta***);

    /*
    Aquí va el constructor que recibe todos los atributos y los inicializa
    */
    ~Juego();
    void alternar_jugador();
    void imprimir_tablero();
    void mostrar_estado_del_juego();
    void definir_fin_del_juego();

    bool crecer_jardin(int, int);
    bool regar_loseta(int, int);
    bool usar_jardinero(int, int);
    bool usar_panda(int, int);
    bool realizar_accion();

    void jugar();
    
};


#endif  //JUEGO_H