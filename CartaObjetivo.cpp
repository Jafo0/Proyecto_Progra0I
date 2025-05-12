#include <iostream>
#include "CartaObjetivo.h"
#include <cstdlib>               //Para poder usar std::rand
#include <string>
#include <fstream>

using std::cout;
using std::endl;
                 
CartaObjetivo::CartaObjetivo(char _tipo){   //Constructor
    this->tipo = _tipo;                     //Defino el tipo de carta objetivo (panda/jardinero)
    this->puntaje = (rand() % 4) + 1;       //Defino mi puntaje aleatorio entre 1 y 4. La semilla se define en el main
    
    //Defino el bambu meta
    if(this->tipo == 'J'){      
        this->bambu_meta = new int[2];                  //Estructura: [cantidad de bambu, color del bambu]
        this->bambu_meta[0] = (rand() % 5) + 1;         //Entre 1 y 5 losetas de un mismo color
        this->bambu_meta[1] = (rand() % 3) + 0;         //Color aleatorio de los 3 que hay
    }else{      //(this->tipo == 'P')
        this->bambu_meta = new int[3];                  //Estructura: [bambu color 0, bambu color 1, bambu color 2]
        for(int i = 0; i < 3; i++){
            this->bambu_meta[i] = (rand() % 3) + 1;     //Entre 1 y 3 bambús por color
        }
    }
}
CartaObjetivo::CartaObjetivo(char tipo_e, int puntaje_e, int* bambu_meta_e)
    :tipo(tipo_e), puntaje(puntaje_e), bambu_meta(bambu_meta_e){}
    
CartaObjetivo::~CartaObjetivo(){            //Destructor
    delete[] this->bambu_meta;
};

void CartaObjetivo::escribir_carta_objetivo(std::ofstream& archivo){

    archivo<<"CartaObjetivo,";
    archivo<<this->puntaje<<","<<
             this->tipo<<","<<
             this->bambu_meta[0]<<","<<
             this->bambu_meta[1];
    if(this->tipo == 'P'){
        archivo<<","<<this->bambu_meta[2];
    }
    archivo<<endl;
}

char CartaObjetivo::getTipo(){return this->tipo;}

int CartaObjetivo::getPuntaje(){return this->puntaje;}

int* CartaObjetivo::getBambuMeta(){return this->bambu_meta;}

void CartaObjetivo::imprimir(std::string nombre_carta){
    //Encabezado
    cout<<"\t"<<nombre_carta<<":\tTipo:"<<this->tipo<<"\t\tPuntaje:"<<this->puntaje<<"\t Meta:";

    //Bambús meta
    if(this->tipo == 'J'){
        cout<<"[";
        switch(this->bambu_meta[1]) {
            case 0:
                cout<<"\033[33m"; // Amarillo
                break;
            case 1:
                cout<<"\033[35m"; // Rosado
                break;
            case 2:
                cout<<"\033[32m"; // Verde
                break;
        }
        cout<<this->bambu_meta[0]<<"\033[0m";
        cout<<", "<<this->bambu_meta[1]<<"]\t\tEstructura: [";
        switch(this->bambu_meta[1]) {
            case 0:
                cout<<"\033[33m"; // Amarillo
                break;
            case 1:
                cout<<"\033[35m"; // Rosado
                break;
            case 2:
                cout<<"\033[32m"; // Verde
                break;
        }
        cout<<"#bambu de este color\033[0m]"<<endl;
    }else{
        cout<<"[\033[33m"<<this->bambu_meta[0]<<", \033[35m"<<this->bambu_meta[1]<<", \033[32m"<<this->bambu_meta[2]<<"\033[0m]\t\tEstructura: [\033[33m#bambu Amarillo, \033[35m#bambu Rosado, \033[32m#bambu Verde\033[0m]"<<endl;
    }
}