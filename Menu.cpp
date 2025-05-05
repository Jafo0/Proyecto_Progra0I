#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(){}
Menu::~Menu(){}

int Menu::desplegar()
{
    int eleccion {0};

    while(true){
        cout <<"\n------------------Opciones Disponibles------------------"<<endl;
            cout << "1. Crecer jardin"<<endl;
            cout << "2. Regar una loseta"<<endl;
            cout << "3. Usar al jardinero"<<endl;
            cout << "4. Mover al panda"<<endl;

            cout << "\nIndique la accion por realizar: ";

            cin >> eleccion; 

            if(1<=eleccion && eleccion<=4){ // Elección válida
                break;  
            }else{
                cout<<"\n\033[1;31m"<<"Opcion invalida. Vuelva a intentar."<<"\033[0m"<<endl;
            }
        }
    return eleccion;
}