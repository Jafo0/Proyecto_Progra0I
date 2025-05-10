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
int Menu::menu_mov(){
    int movimiento{0};
    while(true){
        cout << "\n------------------Opciones Movimiento------------------" << endl;
        cout << "1. Arriba-izquierda" << endl;
        cout << "2. Arriba-derecha" << endl;
        cout << "3. Abajo-izquierda" << endl;
        cout << "4. Abajo-derecha" << endl;
        cout << "5. Abajo" << endl;
        cout << "6. Arriba" << endl;
        cout << "\nIndique movimiento a realizar (1-6): ";
        cin >> movimiento;int posiciones;
        cout << "\nAhora indique cuántas posiciones se desea mover en esa dirección: ";

        if(1<=movimiento && movimiento<=6){ // Elección válida
            break;  
        }else{
            cout<<"\n\033[1;31m"<<"Opcion invalida. Vuelva a intentar."<<"\033[0m"<<endl;
        }
    }
    return movimiento;
}