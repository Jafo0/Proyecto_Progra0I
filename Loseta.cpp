#include "Loseta.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;

Loseta::Loseta(char tipo_e): tipo_loseta(tipo_e){

    if (this->tipo_loseta == 'E') {                 
        this->irrigado = true;           
        this->color= 3;                         // 3 para gris (estanque)
        this->cantidad_bambu = 0;               // Las losetas Estanque no permiten el crecimiento de bambú
        this->esta_jardinero = true;
        this->esta_panda = true;
    } else {
        this->irrigado = false;                 // Las losetas normales no están irrigadas inicialmente
        this->cantidad_bambu = 0;               // inicia en 0 debido a que el Jardinero no ha estado
        this->color = (std::rand() % 3) + 0;    // El color es algún número entre el 0 y el 2
    }
}
Loseta::Loseta(char tipo_e, int color_e, bool irrigado_e, int cantidad_bambu_e, bool esta_jardinero_e, bool esta_panda_e)
    :   tipo_loseta(tipo_e), 
        color(color_e), 
        irrigado(irrigado_e), 
        cantidad_bambu(cantidad_bambu_e), 
        esta_jardinero(esta_jardinero_e), 
        esta_panda(esta_panda_e){}  
        
Loseta::~Loseta(){}

char Loseta::get_tipo(){return this->tipo_loseta;}

int Loseta::get_color(){return this->color;}

bool Loseta::get_irrigado(){return this->irrigado;}

int Loseta::get_cantidad_bambu(){return this->cantidad_bambu;}

bool Loseta::get_esta_panda(){return this->esta_panda;}

void Loseta::set_esta_jardinero(bool nuevo_valor){this->esta_jardinero = nuevo_valor;}

void Loseta::set_esta_panda(bool nuevo_valor){this->esta_panda = nuevo_valor;}

//crecer y decrecer bambu
void Loseta::crecer_bambu() {
    if (this->tipo_loseta != 'E' && this->irrigado && this->cantidad_bambu < 4){
        this->cantidad_bambu++;
    }
}

void Loseta::decrecer_bambu(){
    if (this->cantidad_bambu>0){
        this->cantidad_bambu--;
    }
}

void Loseta::irrigar(){this->irrigado = true;}

void Loseta:: imprimir_loseta(int i, int j, bool jardinero, bool panda, int espacio_texto){
    std::string texto = "";
    // Paso 0: Compruebo panda y/o jardinero
    if(jardinero){texto += "J";}
    if(panda){texto += "P";}

    // Paso 1: Defino el color
    switch(this->color) {
        case 0:
        cout<<"\033[33m"; // Amarillo
            break;
        case 1:
        cout<<"\033[35m"; // Rosado
            break;
        case 2:
        cout<<"\033[32m"; // Verde
            break;
        case 3:
        cout<<"\033[34m"; // Azul
            break;
        default:
        cout<<"\033[97m"; // Blanco
    }

    // Paso 2: Defino el contenido
    texto += std::to_string(i) + std::to_string(j);
    if(tipo_loseta == 'E'){  // Si no es la estanque
            // Hacer nada
    }else{
        if(this->irrigado){   // Si está irrigada
            texto += "*";
            if(this->cantidad_bambu>0){ // Si tiene bambús
                texto += std::to_string(this->cantidad_bambu);
            }
        }
    }

    // Paso 3: Imprimo el contenido, cierro el formato
    cout << std::left << std::setw(espacio_texto) << std::setfill(' ') << texto;
    cout<<"\033[0m\033[0m"; 
}