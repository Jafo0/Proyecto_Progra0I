#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(){}
Menu::~Menu(){}

int Menu::desplegar()
{
    int eleccion {0};

    cout <<"\n------------------Opciones Disponibles------------------"<<endl;
        cout << "1. Crecer jardin"<<endl;
        cout << "2. Regar una loseta"<<endl;
        cout << "3. Usar al jardinero"<<endl;
        cout << "4. Mover al panda"<<endl;
        cout << "5. Terminar el juego"<<endl;

        cout << "\nIndique la accion por realizar: ";

    while (true){
        cin >> eleccion; 

        if(1<=eleccion && eleccion<=5){ // Elección válida
            break;  
        }else{
            cout << "Opcion invalida. Vuelva a intentar" << endl;
            cout << "\nIndique la accion por realizar: ";
        }
    }
    return eleccion;
}