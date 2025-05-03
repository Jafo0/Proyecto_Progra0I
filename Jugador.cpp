#include <iostream>
#include "Jugador.h" 
using std::cout; 
using std::endl;

Jugador::Jugador(std::string _nombre): nombre(_nombre){
    for(int i = 0; i < 3; i++){this->bambus_almacenados[i] = 0;}    //Iniciamos sin bambus almacenados

    //Definimos las cartas objetivos
    this->cartas_jugador = new CartaObjetivo*[4];
    this->cartas_jugador[0] =  new CartaObjetivo('J');     //2 cartas Jardinero
    this->cartas_jugador[1] =  new CartaObjetivo('J');
    this->cartas_jugador[2] =  new CartaObjetivo('P');     //2 cartas Panda
    this->cartas_jugador[3] =  new CartaObjetivo('P');  
}

Jugador::~Jugador(){
    for(int i = 0; i < 4; ++i) {
        delete cartas_jugador[i];  // Elimino cada objeto
    }
    delete[] cartas_jugador;       // Elimino el array de punteros
}

std::string Jugador::get_nombre(){return this->nombre;}

void Jugador::imprimir(){
    cout<<"\n"<<"--------------------------------------"<<"Jugador: "<<this->nombre<<"--------------------------------------"<<endl;
    cout<<"Puntaje Acumulado: "<<this->puntos<<endl;

    std::string nombre_carta;
    cout<<"Cartas: "<<endl;
    for(int i = 0; i < 4; i++){
        nombre_carta = "";
        nombre_carta = "C" + std::to_string(i+1);
        this->cartas_jugador[i]->imprimir(nombre_carta);
    }  
}