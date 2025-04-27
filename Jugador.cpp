#include <iostream>
#include "Jugador.h" 
using std::cout; 
using std::endl;

Jugador::Jugador(std::string _nombre){
    this->nombre = _nombre;             //Defino el nombre
    this->puntos = 0;                   //Iniciamos sin puntos
    for(int i = 0; i < 3; i++){this->bambus_almacenados[i] = 0;}    //Iniciamos sin bambus almacenados

    //Definimos las cartas objetivos
    this->cartas_jugador = new CartaObjetivo*[4];
    this->cartas_jugador[0] =  new CartaObjetivo('J');     //2 cartas Jardinero
    this->cartas_jugador[1] =  new CartaObjetivo('J');
    this->cartas_jugador[2] =  new CartaObjetivo('P');     //2 cartas Panda
    this->cartas_jugador[3] =  new CartaObjetivo('P');  
}

Jugador::~Jugador(){
}

void Jugador::imprimir(){
    cout<<"\n---------------------------------------------------------"<<endl;
    cout<<"Jugador: "<<this->nombre<<endl;
    cout<<"Puntos: "<<this->puntos<<endl;
    cout<<"Cartas: "<<endl;

    for(int i = 0; i < 4; i++){
        std::string nombre_carta = "Carta";
        nombre_carta += std::to_string(i);
        (*this->cartas_jugador[i]).imprimir(nombre_carta);
    }   
}