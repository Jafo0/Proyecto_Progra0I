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

Juego::~Juego(){}

void Juego::mostrar_estado_del_juego(){
    system("cls");      // Limpio la pantalla
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
    cout<<"Desea finalizar el juego(1.Si / 2.No)?: ";
    cin>>decision;
    if(decision == 1){this->fin_del_juego = true;}

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

void Juego::realizar_accion(){
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
        // No ocupamos caso default porque la función de desplegar ya se asegura obtener un valor entre el 1 y el 5
    }

}

void Juego::jugar(){
    int ronda = 1;

    while(!this->fin_del_juego){
        definir_fin_del_juego();
        if(!this->fin_del_juego){
            cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"                                                Ronda: "<<ronda<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
            for(int i = 1; i < 3; i++){
                mostrar_estado_del_juego();
                cout<<"\nTurno de: "<<this->j1->get_nombre()<<"\t|\tAccion #: "<<i<<endl;
                realizar_accion();
            }
            for(int j = 1; j < 3; j++){
                mostrar_estado_del_juego();
                cout<<"\nTurno de: "<<this->j2->get_nombre()<<"\t|\tAccion #: "<<j<<endl;
                realizar_accion();

            }
            ronda++;
        }
    }
}