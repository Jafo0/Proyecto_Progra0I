#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(){}

void Menu::setEleccion_actual(int eleccion_nueva){this->eleccion_actual = eleccion_nueva;}

int Menu::getEleccion_actual(){return this->eleccion_actual;}

int Menu::desplegar()
{
    int acciones = 0;
    int entrada = 0;

    while (acciones < 1)
    {
                cout <<"\n---------------------------------------------------------"<<endl;
        cout << "Tiene 2 acciones este turno. Elija su opcion preferida: "<<endl;
        cout << "1. Crecer jardin"<<endl;
        cout << "2. Regar una loseta"<<endl;
        cout << "3. Usar al jardinero"<<endl;
        cout << "4. Mover al panda"<<endl;

        cin >> entrada;
        try
        {
            switch (entrada)
            {
            case 1: setEleccion_actual(entrada);
                acciones++;
                break;
            case 2: setEleccion_actual(entrada);
                acciones++;
                break;
            case 3: setEleccion_actual(entrada);
                acciones++;
                break;
            case 4: setEleccion_actual(entrada);
                acciones++;
                break;
            default: cout << "Opcion invalida. Vuelva a intentar" << endl;
                break;
            }

        }catch (exception ex)
        {
            cout << "Opcion invalida. Vuelva a intentar" << endl;
        }
    }

    return entrada;
}

