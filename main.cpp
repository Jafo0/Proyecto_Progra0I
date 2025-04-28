#include <iostream>
#include <ctime>                //Para usar std::time(NULL).
#include <cstdlib>              //Para usar std::rand

#include "CartaObjetivo.h"
#include "Jugador.h"
#include "Loseta.h"

int main() {
    srand(time(NULL));  //Establecemos la semilla que utilizaremos para la generación de números aleatorios

    /*
    Esto es una prueba para que se visualize la creación de 3 jugadores con cartas objetivo 
    propias y de valores aleatorios.
    */

    for(int i = 0; i < 3; i++){  
        std::string nombre = "Jugador ";    //Esto es para definir un formato al nombre
        nombre += std::to_string(i);     

        Jugador jugador = Jugador(nombre);  //Creamos un jugador con el nombre indicado
        jugador.imprimir();                 //Imprimimos su información
        jugador.~Jugador();                 //Lo eliminamos
    }
}
