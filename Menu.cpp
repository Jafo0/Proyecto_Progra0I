#include "Menu.h"
#include <iostream>

using namespace std;


int desplegar()
{
    int eleccion {0};

    while(true){
        cout <<"\n------------------Opciones Disponibles------------------"<<endl;
        cout << "1. Crecer jardin"<<endl;
        cout << "2. Regar una loseta"<<endl;
        cout << "3. Usar al jardinero"<<endl;
        cout << "4. Mover al panda"<<endl;
        cout << "5. Finalizar el juego"<<endl;

        cout << "\nIndique la accion por realizar: ";

        cin >> eleccion; 

        if(1<=eleccion && eleccion<=5){ // Elección válida
            break;  
        }else{
            cout<<"\n\033[1;31m"<<"Opcion invalida. Seleccione una dentro del rango indicado. Vuelva a intentar."<<"\033[0m"<<endl;
        }
    }
    return eleccion;
}
int menu_mov(){
    int movimiento{0};
    while(true){
        cout << "\n------------------Opciones Movimiento------------------" << endl;
        cout << "1. Arriba-izquierda" << endl;
        cout << "2. Arriba" << endl;
        cout << "3. Arriba-derecha" << endl;
        cout << "4. Abajo-izquierda" << endl;
        cout << "5. Abajo" << endl;
        cout << "6. Abajo-derecha" << endl;
        
        
        cout << "\nIndique movimiento a realizar (1-6): ";
        cin >> movimiento;

        if(1<=movimiento && movimiento<=6){ // Elección válida
            break;  
        }else{
            cout<<"\n\033[1;31m"<<"Opcion invalida. Seleccione una dentro del rango indicado. Vuelva a intentar."<<"\033[0m"<<endl;
        }
    }
    return movimiento;
}