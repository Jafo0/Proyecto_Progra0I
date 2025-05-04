#include "CartaObjetivo.h"
#include <string>

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador{
    
private:                                //Es un puntero a un array de punteros a objetos CartaObjetivo
    CartaObjetivo** cartas_jugador;     //Estructura: [Carta Jardinero 1, Carta Jardinero 2, Carta Panda 1, Carta Panda 2]
    int bambus_almacenados[3];          //Estructura: [bambus color 0, bambus color 1, bambus color 2]
    int puntos {0};
    std::string nombre;

public:
    Jugador(std::string);
    /*
    Aquí va el constructor que recibe todos los atributos y los inicializa
    */
    ~Jugador();
    std::string get_nombre();
    void imprimir();
    /*
    Función de recolectar bambu. Debe recibir el color del bambu recolectado y acomodarlo acorde al color.
    */

    /*
    Función de evaluar cartas objetivos con los bambus recolectados
    */
};

#endif //JUGADOR_H