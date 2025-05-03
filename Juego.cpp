#include "Juego.h"
#include "Jugador.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

Juego::Juego(int dimension): dimension_tablero(dimension){
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

Juego::~Juego(){}

void Juego::imprimir_tablero(){
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

void Juego::crecer_jardin(){
    std::string posicion;
    int i,j;

    cout<<"Ingrese la casilla en la que desea agregar una loseta: ";
    cin>>posicion;

    i = posicion[0] - '0';
    j = posicion[1] - '0';
    
    if((this->tablero[i][j] != nullptr) || (i == this->dimension_tablero && j == this->dimension_tablero)){ //Si hay loseta definida o es la loseta estanque
        // No hacer nada
    }else{
        this->tablero[i][j] = new Loseta('N');
    }
}

void Juego::regar_loseta(){
    std::string posicion;
    int i,j;

    cout<<"Ingrese la casilla en la que desea irrigar una loseta: ";
    cin>>posicion;

    i = posicion[0] - '0';
    j = posicion[1] - '0';

    if(this->tablero[i][j] != nullptr){ //Si ya hay loseta creada
        this->tablero[i][j]->irrigar();
    }
}

void Juego::usar_jardinero(){
    std::string posicion;
    int i,j;

    cout<<"Ingrese la casilla a la que desea mover el jardinero: ";
    cin>>posicion;

    i = posicion[0] - '0';
    j = posicion[1] - '0';
    if((i == this->jardinero[0] && j == this->jardinero[1]) || this->tablero[i][j] == nullptr){} // Si la posicion es la misma o la loseta no está irrigada, no hacer nada
    else{
        this->tablero[this->jardinero[0]][this->jardinero[1]]->set_esta_jardinero(false);   // Elimino la posición actual del jardinero
        
        this->jardinero[0] = i;     // Defino la nueva posición del jardinero
        this->jardinero[1] = j;
        
        this->tablero[this->jardinero[0]][this->jardinero[1]]->set_esta_jardinero(true);    // Le indico a la loseta que ahora tiene un jardinero
        this->tablero[this->jardinero[0]][this->jardinero[1]]->crecer_bambu();
    }
}

void Juego::usar_panda(){
    std::string posicion;
    int i,j;

    cout<<"Ingrese la casilla a la que desea mover el panda: ";
    cin>>posicion;

    i = posicion[0] - '0';
    j = posicion[1] - '0';
    if((i == this->panda[0] && j == this->panda[1]) || this->tablero[i][j] == nullptr){} // Si la posicion es la misma o la loseta no está irrigada, no hacer nada
    else{
        this->tablero[this->panda[0]][this->panda[1]]->set_esta_panda(false);   // Elimino la posición actual del jardinero
        
        this->panda[0] = i;     // Defino la nueva posición del panda
        this->panda[1] = j;
        
        this->tablero[this->panda[0]][this->panda[1]]->set_esta_panda(true);    // Le indico a la loseta que ahora tiene un jardinero
        this->tablero[this->panda[0]][this->panda[1]]->decrecer_bambu();
    }
}

void Juego::jugar(std::string nombre_j1, std::string nombre_j2){
    Jugador* j1 = new Jugador(nombre_j1);
    Jugador* j2 = new Jugador(nombre_j2);
    while(true){
        j1->imprimir();
        j2->imprimir();
        imprimir_tablero();

        int eleccion = this->menu->desplegar();

        switch(eleccion) 
            case 1: {// Crecer Jardin. 
                crecer_jardin();
                break;
            case 2: // Regar loseta
                regar_loseta();
                break;
            case 3: // Usar jardinero
                usar_jardinero();
                break;
            case 4: // Mover panda
                usar_panda();
                break;
            case 5: //Terminar juego
                cout << "Fin del juego" << endl;
                return;
            // No ocupamos caso default porque la función de desplegar ya se asegura obtener un valor entre el 1 y el 5
        }
    }
}