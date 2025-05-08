#include <iostream>
#include "CartaObjetivo.h"
#include <cstdlib>               //Para poder usar std::rand

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
CartaObjetivo::CartaObjetivo(char tipo_e, int puntaje_e, int* bambu_meta_e)
    :tipo(tipo_e), puntaje(puntaje_e), bambu_meta(bambu_meta_e){}
    
CartaObjetivo::~CartaObjetivo(){            //Destructor
    delete[] this->bambu_meta;
};

char CartaObjetivo::getTipo(){
    return this->tipo;
}

int CartaObjetivo::getPuntaje(){
    return this->puntaje;
}

int* CartaObjetivo::getBambuMeta(){ return this->bambu_meta;}

void CartaObjetivo::imprimir(std::string nombre_carta){
    //Encabezado
    cout<<"\t"<<nombre_carta<<":\tTipo:"<<this->tipo<<"\t\tPuntaje:"<<this->puntaje<<"\t Meta:";

    //Bambús meta
    if(this -> tipo == 'J'){
        cout<<"["<<this->bambu_meta[0]<<", "<<this->bambu_meta[1]+1<<"]\t\tEstructura: [#bambu, color de bambu]"<<endl;
    }else{
        cout<<"["<<this->bambu_meta[0]<<", "<<this->bambu_meta[1]<<", "<<this->bambu_meta[2]<<"]\t\tEstructura: [#bambu color 1, #bambu color 2, #bambu color 3]"<<endl;
    }
}