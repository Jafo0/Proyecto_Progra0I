#include "Loseta.h"
#include <iostream>

Loseta::Loseta(char tipo_e): tipo_loseta(tipo_e){

    if (this->tipo_loseta == 'E') {                 
        this->irrigado = true;           
        this->color= 0;                    //0 para gris (estanque)
        this->cantidad_bambu = 0;          // Las losetas Estanque no permiten el crecimiento de bambú
    } else {
        this->irrigado = false;            // Las losetas normales no están irrigadas inicialmente
        this->cantidad_bambu = 0;          // inicia en 0 debido a que el Jardinero no ha estado
        this->color = (std::rand() % 3) + 1;
    }
    
}   
//Loseta::~Loseta(){}

//crecer y decrecer bambu
void Loseta::crecer_bambu() {
    if (this->tipo_loseta != 'E'){
        this->cantidad_bambu++;
    }
}

void Loseta::decrecer_bambu(){
    if (this->cantidad_bambu<0 && this->tipo_loseta != 'E'){
        this->cantidad_bambu--;
    }
}
//conecciones de loseta
void Loseta::conectar_superior(Loseta* loseta_superior){
    if (this == loseta_superior) return;                 //ya hay conexion 
    if (this->superior != nullptr){                      //sin conexion con la central
        this->superior->inferior = nullptr;
    }
    this->superior = loseta_superior;
    if (loseta_superior != nullptr){
        loseta_superior->inferior = this;                //conexion con loseta central
    }
}
void Loseta::conectar_inferior(Loseta* loseta_inferior){
    if (this == loseta_inferior) return;
    if (this->inferior != nullptr){
        this->inferior->superior = nullptr;
    }
    this->inferior = loseta_inferior;
    if (loseta_inferior != nullptr){
        loseta_inferior->superior = this;
    }
}
void Loseta::conectar_izquierda_arriba(Loseta* loseta_izquierda_arriba){
    if (this == loseta_izquierda_arriba) return;
    if(this->izquierda_arriba!= nullptr){
        this->izquierda_arriba->derecha_abajo = nullptr;
    }
    this->izquierda_arriba = loseta_izquierda_arriba;
    if (loseta_izquierda_arriba != nullptr){
        loseta_izquierda_arriba->derecha_abajo = this;
    }
}
void Loseta::conectar_izquierda_abajo(Loseta* loseta_izquierda_abajo) {
    if (this == loseta_izquierda_abajo) return;
    if (this->izquierda_abajo != nullptr) {
        this->izquierda_abajo->derecha_arriba = nullptr;
    }
    this->izquierda_abajo = loseta_izquierda_abajo;
    if (loseta_izquierda_abajo != nullptr) {
        loseta_izquierda_abajo->derecha_arriba = this;
    }
}
void Loseta::conectar_derecha_arriba(Loseta* loseta_derecha_arriba) {
    if (this == loseta_derecha_arriba) return;
    if (this->derecha_arriba != nullptr) {
        this->derecha_arriba->izquierda_abajo = nullptr;
    }
    this->derecha_arriba = loseta_derecha_arriba;
    if (loseta_derecha_arriba != nullptr) {
        loseta_derecha_arriba->izquierda_abajo = this;
    }
}
void Loseta::conectar_derecha_abajo(Loseta* loseta_derecha_abajo) {
    if (this == loseta_derecha_abajo) return;
    if (this->derecha_abajo != nullptr) {
        this->derecha_abajo->izquierda_arriba = nullptr;
    }
    this->derecha_abajo = loseta_derecha_abajo;
    if (loseta_derecha_abajo != nullptr) {
        loseta_derecha_abajo->izquierda_arriba = this;
    }
}
/*
void Loseta::iniciar_centro(){
    int fila_centro = N/2;
    int col_centro = N/2;
    if (matriz[fila_centro][col_centro] == nullptr) {
        matriz[fila_centro][col_centro] = new Loseta('E');  //HICE UN NEW
    }
}


void Loseta::agregar_loseta(){
    int fila_a, col_a;
    char eleccion;

    std::cout << "Indica la fila de la loseta desde donde agregar: ";     //buscar loseta desde donde agregar
    std::cin >> fila_a;
    std::cout << "Indica la columna de la loseta desde donde agregar: ";
    std::cin >> col_a;

    if (fila_a < 0 || fila_a >= N || col_a < 0 || col_a >= N || matriz[fila_a][col_a] == nullptr) {
        std::cout << "No hay loseta en esa posición.\n";
        return;
    }
    std::cout << "Indique la direccion en la que vas a agregar la nueva loseta \n";
    std::cout << "A= arriba ( "<<fila_a-1<<" , "<<col_a<<" )\n";
    std::cout << "B= arriba derecha ( "<<fila_a-1<<" , "<<col_a+1<<" )\n";
    std::cout << "C= arriba izquierda ( "<<fila_a-1<<" , "<<col_a-1<<" )\n";
    std::cout << "D= abajo ( "<<fila_a+1<<" , "<<col_a<<" )\n";
    std::cout << "E= abajo derecha ( "<<fila_a+1<<" , "<<col_a+1<<" )\n";
    std::cout << "F= abajo izquierda ( "<<fila_a+1<<" , "<<col_a-1<<" )\n";

    std::cout<<"Elige una opcion de A-F: "<<std::endl;
    std::cin >> eleccion;
    switch(eleccion){
        case 'A': case 'a':
            fila_a -= 1;
            break;
        case 'B': case 'b':
            fila_a -=1;
            col_a +=1;
            break;
        case 'C': case 'c':
            fila_a -=1;
            col_a -=1;
            break;
        case 'D': case 'd':
            fila_a += 1;
            break;
        case 'E': case 'e':
            fila_a += 1;
            col_a +=1;
            break;
        case 'F': case 'f':
            fila_a += 1;
            col_a -=1;
            break;
        default:
            std::cout << "Opción inválida"<<std::endl;
            return;
    }
    if (fila_a >= 0 && fila_a < N && col_a >= 0 && col_a < N && matriz[fila_a][col_a] == nullptr) {
        matriz[fila_a][col_a] = new Loseta('N');       // New loseta normal
        std::cout << "Loseta agregada en (" << fila_a << ", " << col_a << ")\n";
    } else {
        std::cout << "Esa posición ya está ocupada o fuera de la matriz.\n";
    }
}
void Loseta::mostrar_matriz(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] != nullptr) {             //Muestro tipo( deberia mostrar tambien irrigado, cantbambu?)
                std::cout << "[" << matriz[i][j]->tipo_loseta << "] ";  
            } else {
                std::cout << "[ ] ";                   // Espacio vacío si no hay loseta
            }
        }
        std::cout << std::endl;                        // Nueva línea al final de cada fila
    }
}
*/