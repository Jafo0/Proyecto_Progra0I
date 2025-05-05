#include <iostream>
#include <ctime>                //Para usar std::time(NULL).
#include <cstdlib>              //Para usar std::rand
#include <string>

#include "Juego.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(NULL));  //Establecemos la semilla que utilizaremos para la generación de números aleatorios

    cout<<"Desea cargar una partida anterior? (1.Si / 2.No): ";
    int cargar_partida {2};
    cin>>cargar_partida;

    if(cargar_partida == 1){
        //Código para cargar la partida desde un archivo de texto
    }else{
        // std::string nombre_j1, nombre_j2;

        // cout<<"Ingrese el nombre del jugador 1: ";
        // cin>>nombre_j1;

        // cout<<"Ingrese el nombre del jugador 2: ";
        // cin>>nombre_j2;

        // cout<<"Ingrese la dimension del tablero (Para pruebas iniciales, ingresar 9): ";
        // int dimension;
        // cin>>dimension;
        // cout<<endl;

        // Juego* juego = new Juego(nombre_j1, nombre_j2, dimension);
        // juego->jugar();

        Juego* juego = new Juego("Ale", "Fio", 9);
        juego->jugar();

    }
}