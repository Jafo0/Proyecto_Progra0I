#include "Juego.h"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

Juego::Juego(std::string nombre_j1, std::string nombre_j2, int dimension): dimension_tablero(dimension){
    this->j1 = new Jugador(nombre_j1);
    this->j2 = new Jugador(nombre_j2);

    //Creo mi tablero
    this->tablero = new Loseta**[dimension];
    for(int i = 0; i<dimension; i++){
        this->tablero[i] = new Loseta*[dimension];
        for(int j = 0; j<dimension; j++){
            this->tablero[i][j] = nullptr;
        }
    }

    this->tablero[dimension/2][dimension/2] = new Loseta('E');  //Inicializo loseta estanque
    this->menu = new Menu();

    this->panda[0] = dimension/2;
    this->panda[1] = dimension/2;
    this->jardinero[0] = dimension/2;
    this->jardinero[1] = dimension/2;

    this->menu = new Menu();
} 

/*
Aquí va el constructor que recibe todos los atributos y los inicializa
*/

Juego::~Juego(){}

void Juego::mostrar_estado_del_juego(){
    // Información de los jugadores: 
    this->j1->imprimir();
    this->j2->imprimir();
    cout<<endl;
    
    // Información del tablero:
    cout<<"\n"<<"----------------------------------------------"<<"Tablero"<<"----------------------------------------------"<<endl;
    for(int i = 0; i < this->dimension_tablero; i++){                   // Recorremos filas
        if(i%2 != 0){cout<<"   ";}
        for(int j = 0; j < this->dimension_tablero; j++){               // Recorremos columnas
            if (this->tablero[i][j] == nullptr) {            // Loseta no definida
                cout<<"  "<<std::to_string(i)<<std::to_string(j)<<"  ";
            }else{
                this->tablero[i][j]->imprimir_loseta(i,j);
            }
        }
        cout<<endl;
    }
}

void Juego::definir_fin_del_juego(){
    int decision;
    cout<<"\nDesea finalizar el juego(1.Si / 2.No)?: ";
    cin>>decision;
    if(decision == 1){this->fin_del_juego = true;}

}

bool Juego::crecer_jardin(int i, int j){
    if (i == this->dimension_tablero/2 && j == this->dimension_tablero/2){ // Si es la loseta estanque
        cout<<"\n\033[1;31m"<<"La casilla ingresada corresponde a la estanque. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(this->tablero[i][j] != nullptr){  // Ya hay una loseta en ese espacio
        cout<<"\n\033[1;31m"<<"La casilla ingresada ya contiene una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else{
        this->tablero[i][j] = new Loseta('N');
        return true;
    }
}

bool Juego::regar_loseta(int i, int j){

    if(this->tablero[i][j] == nullptr){ //Si ya hay loseta creada
        cout<<"\n\033[1;31m"<<"La casilla ingresasda no contiene una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(this->tablero[i][j]->get_irrigado()){
        cout<<"\n\033[1;31m"<<"La casilla ingresasda ya contiene una loseta irrigada. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else{
        this->tablero[i][j]->irrigar();
        return true;
    }
}

bool Juego::usar_jardinero(int i, int j){
    if(i == this->jardinero[0] && j == this->jardinero[1]){     // La posicion del jardinero no cambia
        cout<<"\n\033[1;31m"<<"El jardinero no fue movido. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(this->tablero[i][j] == nullptr){      // No hay una loseta
        cout<<"\n\033[1;31m"<<"La casilla ingresada no contiene una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else{
        this->tablero[this->jardinero[0]][this->jardinero[1]]->set_esta_jardinero(false);   // Elimino la posición actual del jardinero
        
        this->jardinero[0] = i;     // Defino la nueva posición del jardinero
        this->jardinero[1] = j;
        
        this->tablero[this->jardinero[0]][this->jardinero[1]]->set_esta_jardinero(true);    // Le indico a la loseta que ahora tiene un jardinero
        this->tablero[this->jardinero[0]][this->jardinero[1]]->crecer_bambu();
        return true;
    }
}

bool Juego::usar_panda(int i, int j){
    if(i == this->panda[0] && j == this->panda[1]){     // La posicion del panda no cambia
        cout<<"\n\033[1;31m"<<"El panda no fue movido. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(this->tablero[i][j] == nullptr){      // No hay una loseta
        cout<<"\n\033[1;31m"<<"La casilla ingresada no contiene una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else{
        this->tablero[this->panda[0]][this->panda[1]]->set_esta_panda(false);   // Elimino la posición actual del panda
        
        this->panda[0] = i;     // Defino la nueva posición del panda
        this->panda[1] = j;
        
        this->tablero[this->panda[0]][this->panda[1]]->set_esta_panda(true);    // Le indico a la loseta que ahora tiene un panda
        this->tablero[this->panda[0]][this->panda[1]]->decrecer_bambu();
        return true;
    }
    /*
    Aquí se llama a la función de recolectar bambú
    */

    /*
    Aquí se llama a la función de evaluar carta objetivo con bambu recolectado
    */
}

bool Juego::realizar_accion(){
    int eleccion = this->menu->desplegar();

    int posicion, i, j;

    cout<<"\nIngrese la casilla de la accion a realizar: ";
    cin>>posicion;

    i = posicion/10;
    j = posicion%10;

    if(i<0||this->dimension_tablero-1<i||j<0||this->dimension_tablero-1<j){  // La entrada se sale de las dimensiones del tablero
        cout<<"\n\033[1;31m"<<"La casilla se sale de las dimensiones del tablero. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    }  
        
    switch(eleccion) 
        case 1: {// Crecer Jardin. 
            return crecer_jardin(i, j);
        case 2: // Regar loseta
            return regar_loseta(i, j);
        case 3: // Usar jardinero
            return usar_jardinero(i, j);
        case 4: // Mover panda
            return usar_panda(i, j);
        // No ocupamos caso default porque la función de desplegar ya se asegura obtener un valor entre el 1 y el 5
    }
}

void Juego::jugar(){
    int ronda = 1;

    while(!this->fin_del_juego){
        system("cls");    // Limpio la terminal
        mostrar_estado_del_juego();
        definir_fin_del_juego();
        if(!this->fin_del_juego){
            // mostrar_estado_del_juego();
            for(int i = 1; i < 3; i++){
                system("cls");    // Limpio la terminal
                mostrar_estado_del_juego();
                cout<<"\nRonda: "<<ronda<<"\t|\tTurno de: "<<this->j1->get_nombre()<<"\t|\tAccion #: "<<i<<endl;
                while(!realizar_accion());
                // mostrar_estado_del_juego();
            }
            for(int j = 1; j < 3; j++){
                system("cls");    // Limpio la terminal
                mostrar_estado_del_juego();
                cout<<"\nRonda: "<<ronda<<"\t|\tTurno de: "<<this->j2->get_nombre()<<"\t|\tAccion #: "<<j<<endl;
                while(!realizar_accion());
                // mostrar_estado_del_juego();
            }
            ronda++;
        }
    }
}