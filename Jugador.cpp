#include <iostream>
#include <fstream>
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

   Jugador::Jugador(std::string _nombre, int _puntos, int _bambus_almacenados[], CartaObjetivo** _cartas_jugador){
    this->nombre = _nombre;
    this->puntos = _puntos;
    for(int i = 0; i < 3; i++){
        this->bambus_almacenados[i] = _bambus_almacenados[i];
    }
    this->cartas_jugador = _cartas_jugador;
}

Jugador::~Jugador(){
    for(int i = 0; i < 4; ++i) {
        delete cartas_jugador[i];  // Elimino cada objeto
    }
    delete[] cartas_jugador;       // Elimino el array de punteros
}

void Jugador::escribir_jugador(std::ofstream& archivo){
    archivo<<"Jugador,"<<this->nombre<<","<<
                         this->puntos<<","<<
                         this->bambus_almacenados[0]<<","<<
                         this->bambus_almacenados[1]<<","<<
                         this->bambus_almacenados[2]<<endl;
    for(int i=0; i<4; i++){
        this->cartas_jugador[i]->escribir_carta_objetivo(archivo);
    }
}

std::string Jugador::get_nombre(){return this->nombre;}
int Jugador::get_puntos(){return this->puntos;}
int* Jugador::get_bambus_almacenados(){return this->bambus_almacenados;}

void Jugador::imprimir(){
    cout<<"\n"<<"--------------------------------------"<<"Jugador: "<<this->nombre<<"--------------------------------------"<<endl;
    cout<<"Puntaje Acumulado: "<<this->puntos<<endl;
    cout<<"Bambus almacenados [";
    for (int i=0; i<3;i++){
        // Paso 1: Defino el color
        switch(i) {
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
       cout<<bambus_almacenados[i]<<"\033[0m";  // Cierro el formato del color 
       if (i < 2) {cout << ", ";}
    }
    cout<<"]\t\t\t\t\t\tEstructura: [\033[33m#bambu Amarillo, \033[35m#bambu Rosado, \033[32m#bambu Verde\033[0m]"<<endl;

    std::string nombre_carta;
    cout<<"Cartas: "<<endl;
    for(int i = 0; i < 4; i++){
        nombre_carta = "";
        nombre_carta = "C" + std::to_string(i+1);
        this->cartas_jugador[i]->imprimir(nombre_carta);
    }  
}
void Jugador::recolectar_bambu(int color){
        this->bambus_almacenados[color]++;  
}

int Jugador::get_bambu_por_color(int color){
    return bambus_almacenados[color];
}

void Jugador::evaluar_panda(){
    bool continuar_revisando = true;
    for (int c = 2; c < 4; c++){    // Reviso las cartas de panda
        for (int b = 0; b < 3; b++){    //Revisamos cada bambu de la carta
            if(continuar_revisando){    //Si todavía podemos completar la carta que estamos revisando
                if (this->cartas_jugador[c]->getBambuMeta()[b] > this->bambus_almacenados[b]){  // Si tenemos menos bambús de los necesarios
                    continuar_revisando = false;    // Ya no podemos cumplir la carta
                }
            }
        }
        if(continuar_revisando){    // Si tenemos todos los bambús que necesitamos para la carta  
            this->puntos += this->cartas_jugador[c]->getPuntaje();  // Sumamos el puntaje de la carta
            for(int i = 0; i < 3; i++){this->bambus_almacenados[i]-=this->cartas_jugador[c]->getBambuMeta()[i];}    //Eliminamos los bambús almacenados
            delete this->cartas_jugador[c];
            this->cartas_jugador[c] = new CartaObjetivo('P');
            c = 2;  // Al cumplir la carta, iniciamos la revisión otra vez
        } 
    }
}

void Jugador::evaluar_jardinero(Loseta* jardinero){
    for (int c = 0; c < 4; c++){
        if (this->cartas_jugador[c]->getTipo() == 'J'){
            if(jardinero->get_color() == this->cartas_jugador[c]->getBambuMeta()[1]){
                if(jardinero->get_cantidad_bambu() <= this->cartas_jugador[c]->getBambuMeta()[0]){
                    this->puntos += this->cartas_jugador[c]->getPuntaje();
                    CartaObjetivo* borrar = this->cartas_jugador[c];
                    this->cartas_jugador[c] = new CartaObjetivo('J');
                    this->cartas_jugador[c]-> ~CartaObjetivo();
                }
            }
        }
    }
}