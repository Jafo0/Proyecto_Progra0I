#include <iostream>
#include "CartaObjetivo.h"
#include <cstdlib>              //Para poder usar std::rand

using std::cout;
using std::endl;
                 

CartaObjetivo::CartaObjetivo(char _tipo){   //Constructor
    this->tipo = _tipo;                     //Defino el tipo de carta objetivo (panda/jardinero)
    this->puntaje = (rand() % 4) + 1;       //Defino mi puntaje aleatorio entre 1 y 4. La semilla se define en el main
    
    //Defino el bambu meta
    if(this->tipo == 'J'){      
        this->bambu_meta = new int[2];                  //Estructura: [cantidad de bambu, color del bambu]
        this->bambu_meta[0] = (rand() % 4) + 1;         //Entre 1 y 4 losetas de un mismo color
        this->bambu_meta[1] = (rand() % 3) + 0;         //Color aleatorio de los 3 que hay
    }else{      //(this->tipo == 'P')
        this->bambu_meta = new int[3];                  //Estructura: [bambu color 0, bambu color 1, bambu color 2]
        for(int i = 0; i < 3; i++){
            this->bambu_meta[i] = (rand() % 3) + 1;     //Entre 1 y 2 losetas por color
        }
    }
}

CartaObjetivo::~CartaObjetivo(){            //Destructor
    delete[] this->bambu_meta;
};

char CartaObjetivo::getTipo(){
    return this->tipo;
}

int CartaObjetivo::getPuntaje(){
    return this->puntaje;
}

void CartaObjetivo::imprimir(std::string nombre_carta){
    //Encabezado
    cout.fill('-'); cout.width(20); cout <<"";
    cout << nombre_carta;
    cout.fill('-'); cout.width(20); cout <<""<<endl;

    //Tipo y puntaje
    cout<<"Tipo : "<<this->tipo;
    cout <<"\t\t| ";
    cout<<"Puntaje : "<< this->puntaje<<"\n"<<endl;

    //Bambús meta
    if(this -> tipo == 'J'){
        std::cout<<"Cantidad de Bambu : "<<this->bambu_meta[0]<<"\t| Color : "<<this->bambu_meta[1]<<std::endl;
    }else{
        for(int i = 0; i < 3; i++){
            std::cout<<"Cantidad de Bambu : "<<this->bambu_meta[i]<<"\t| Color : "<<i<<std::endl;
        }
    }
}

