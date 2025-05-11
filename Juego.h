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
    int* personaje {this->panda};
    int dimension_tablero {9};
    int espacio_texto {6};  //Necesario para imprimir el tablero
    int puntos_juego {5};
    int ronda {1};
    bool ronda_completa {false};
    bool fin_del_juego {false};
    int accion_jugador_actual {1};
    Loseta*** tablero;
    Jugador* j1;
    Jugador* j2;
    Jugador* jugador_actual;
    //int movimiento;
    //int posiciones; atributos para movimiento

    public:
    Juego(std::string, std::string, int, int);
	Juego(Jugador*, Jugador*, int, int, int, int, int, Jugador*, Loseta***);

    ~Juego();
    void alternar_jugador();
    void imprimir_tablero();
    void mostrar_estado_del_juego();
    void guardar_en_archivo();

    bool comprobar_adyacencia(int, int, bool); //comprobar adyacencia e irrigacion (de ser necesario) de una loseta

    bool crecer_jardin(int, int);
    bool regar_loseta(int, int);

    void nueva_posicion_jardinero(int, int);
    bool nueva_posicion_panda(int, int);
    bool mover_personaje(int, int, int, int, int, bool);
    
    
    bool realizar_accion();
    
    void revisar_ganador();
    void jugar();
    
};


#endif  //JUEGO_H