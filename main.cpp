#include <iostream>
#include <ctime>                //Para usar std::time(NULL).
#include <cstdlib>              //Para usar std::rand
#include <string>

#include "Juego.h"
#include "FuncionesComplementarias.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(NULL));  //Establecemos la semilla que utilizaremos para la generación de números aleatorios
    Juego* juego;
    int cargar_partida {2};
    while(true){
            cout<<"Desea cargar una partida anterior? (1.Si / 2.No): ";
            cin>>cargar_partida;
            cout<<endl;

            if(cargar_partida == 1 || cargar_partida == 2){
                break;
            }else{
                cout<<"\033[1;31m"<<"Por favor ingrese una lo solicitado. Vueva a intentar."<<"\033[0m"<<endl;
            }
        }
    system("cls");

    if(cargar_partida == 1){
        juego = cargar_juego();
    }else{
        std::string nombre_j1, nombre_j2;

        cout<<"Ingrese el nombre del jugador 1 (sin espacios): ";
        cin>>nombre_j1;

        cout<<"Ingrese el nombre del jugador 2 (sin espacios): ";
        cin>>nombre_j2;

        int dimension;
        while(true){
            cout<<"Ingrese la dimension del tablero (Numero impar menor o igual a 9): ";
            cin>>dimension;
            cout<<endl;
            if(1<=dimension && dimension<=9 && dimension%2 != 0){
                break;
            }else{
                cout<<"\033[1;31m"<<"Por favor ingrese una dimension segun lo solicitado. Vueva a intentar."<<"\033[0m"<<endl;
            }
        }

        juego = new Juego(nombre_j1, nombre_j2, dimension, 9);
    }
    
    juego->jugar();
    delete juego;
}
