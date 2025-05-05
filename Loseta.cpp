#include "Loseta.h"
#include <iostream>
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
    /*
    Aquí va el constructor que recibe todos los atributos y los inicializa
    */
        
Loseta::~Loseta(){}

char Loseta::get_tipo(){return this->tipo_loseta;}

int Loseta::get_color(){return this->color;}

bool Loseta::get_irrigado(){return this->irrigado;}

int Loseta::get_cantidad_bambu(){return this->cantidad_bambu;}


void Loseta::set_esta_jardinero(bool nuevo_valor){this->esta_jardinero = nuevo_valor;}

void Loseta::set_esta_panda(bool nuevo_valor){this->esta_panda = nuevo_valor;}

//crecer y decrecer bambu
void Loseta::crecer_bambu() {
    if (this->tipo_loseta != 'E' && this->irrigado && this->cantidad_bambu < 4 && this->esta_jardinero){
        this->cantidad_bambu++;
    }
}

void Loseta::decrecer_bambu(){
    if (this->cantidad_bambu>0 && this->esta_panda){
        this->cantidad_bambu--;
    }
}

void Loseta::irrigar(){this->irrigado = true;}

void Loseta:: imprimir_loseta(int i, int j){
    /*
    Opciones:
        __ij__
        __ij*_
        _ij*4_
    */
   //Paso 0: Identifico si está el jardinero
   if(this->esta_jardinero){
        cout<<"\033[4m"; // Texto subrayado 
   }
   //Paso 1: Identifico si está el panda
   if(this->esta_panda){
    cout<<"\033[9m"; // Texto tachado
    }

   // Paso 2: Defino el color
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

   // Paso 3: Defino el contenido
   std::string texto = std::to_string(i) + std::to_string(j);
   if(this->tipo_loseta == 'E'){    //Si es la loseta estanque
        texto = "  " + texto + "  ";
   }else if(!this->irrigado){       //Si no está irrigada
        texto = "  " + texto + "  ";
   }else if(this->cantidad_bambu == 0){ //Irrigada pero sin bambú
        texto = "  " + texto + "* ";
   }else{   //Irrigada y con bambú
        texto = " " + texto + "*" + std::to_string(this->cantidad_bambu);
   }
   // Paso 4: Imprimo, cierro el color y/o cierro el panda/jardinero
   cout<<texto<<"\033[0m"; 
}