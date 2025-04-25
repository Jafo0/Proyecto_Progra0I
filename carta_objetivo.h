#include <iostream>

#ifndef CARTA_OBJETIVO_H
#define CARTA_OBJETIVO_H

class Carta_objetivo
{
    /*Descripción general de la dinámica
Cada jugador tiene permanentemente 4 cartas de objetivo en su tablero.
El objetivo principal del juego es intentar completar las cartas de objetivo.
Cada carta de objetivo tiene un puntaje entre 1 y 4 puntos

se asume que cada jugador tiene permanentemente 2 cartas de cada tipo:
Carta de objetivo de panda: establece una cantidad de unidades de bambú de cada color que debe
acumularse en el tablero para ser alcanzada. Este tipo de carta se completa cuando en el tablero personal
se encuentran esas piezas de bambú. Por ejemplo: 2 piezas amarillas y una rosada.

Carta de objetivo de jardinero: establece una cantidad de unidades de bambú y un solo color, que debe
construirse en una loseta de jardín. Este tipo de carta se completa cuando en el jardín (en cualquier loseta)
hay una torre de bambú del color y altura especificado. Por ejemplo: una torre de 3 piezas de bambú rosado
La mayor altura que puede alcanzar un bambú es 4 secciones*/

private:
    char tipo; //'J' si es de objetivo de jardinero, 'P' si es de objetivo de panda
    int puntaje; //Entre 1 y 4 puntos
    int* meta; //Los objetivos a cumplir
    std::string jugador; //Cada jugador tiene 2 cartas de cada tipo, puede ser reemplazado por un puntero al jugador
public:
    Carta_objetivo(std::string); //Constructor de la carta
    ~Carta_objetivo(); //Destructor de la carta
    bool evaluar(/*parametro*/); //Evaluar que se cumplan los objetivos
    void imprimir();
    void setTipo();
    char getTipo();
    void setPuntaje();
    int getPuntaje();
    void setMeta();
    std::string getJugador();
};

#endif //CARTA_OBJETIVO_H
