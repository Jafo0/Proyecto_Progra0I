#include "FuncionesComplementarias.h"
#include "Juego.h"
#include "CartaObjetivo.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;


int desplegar()
{
    int eleccion {0};

    while(true){
        cout <<"\n------------------Opciones Disponibles------------------"<<endl;
        cout << "1. Crecer jardin"<<endl;
        cout << "2. Regar una loseta"<<endl;
        cout << "3. Usar al jardinero"<<endl;
        cout << "4. Mover al panda"<<endl;
        cout << "5. Finalizar el juego"<<endl;

        cout << "\nIndique la accion por realizar: ";

        cin >> eleccion; 

        if(1<=eleccion && eleccion<=5){ // Elección válida
            break;  
        }else{
            cout<<"\n\033[1;31m"<<"Opcion invalida. Seleccione una dentro del rango indicado. Vuelva a intentar."<<"\033[0m"<<endl;
        }
    }
    return eleccion;
}
int menu_mov(){
    int movimiento{0};
    while(true){
        cout << "\n------------------Opciones Movimiento------------------" << endl;
        cout << "1. Arriba-izquierda" << endl;
        cout << "2. Arriba" << endl;
        cout << "3. Arriba-derecha" << endl;
        cout << "4. Abajo-izquierda" << endl;
        cout << "5. Abajo" << endl;
        cout << "6. Abajo-derecha" << endl;
        
        
        cout << "\nIndique movimiento a realizar (1-6): ";
        cin >> movimiento;

        if(1<=movimiento && movimiento<=6){ // Elección válida
            break;  
        }else{
            cout<<"\n\033[1;31m"<<"Opcion invalida. Seleccione una dentro del rango indicado. Vuelva a intentar."<<"\033[0m"<<endl;
        }
    }
    return movimiento;
}


std::string* lector(int cantidad, std::string linea){

    //Crea el arreglo
    std::string* arreglo = new std::string[cantidad];
    int contador = 0;

    //Separa las lineas por comas y las pone en otro string
    std::stringstream ss(linea);
    std::string elem;

    while (std::getline(ss, elem, ',') && contador < cantidad){
        //Pone un elemento en el arreglo de strings
        arreglo[contador] = elem;
        contador++;
    }
    return arreglo;
}

Jugador* leer_jugador(std::ifstream& archivo){
    std::string linea_temp;
    std::string* datos;

    std::getline(archivo, linea_temp);  
    datos = lector(6, linea_temp);

    //Datos del jugador
    std::string nombre = datos[1];
    int puntos = datos[2][0] - '0';     //Leo el string, lo convierto a char y luego a int
    int bambus_almacenados[3] = {datos[3][0] - '0' ,datos[4][0] - '0', datos[5][0] - '0'};      //Leo el string, lo convierto a char y luego a int
    CartaObjetivo** cartas_jugador = new CartaObjetivo* [4];

    //Para leer las cartas
    for(int i = 0; i < 4; i++){ //Leo las próximas 4 líneas de las cartas objetivos del jugador
        int cantidad;
        int puntaje;
        char tipo;
        int* bambu_meta;
        if(i<2){    //Estamos en cartas jardinero
            cantidad = 5;
            std::getline(archivo, linea_temp);

            std::string* array_cartas_temp = lector(cantidad, linea_temp);
            puntaje = array_cartas_temp[1][0] - '0';        //Leo el string, lo convierto a char y luego a int
            tipo = array_cartas_temp[2][0];                //Leo el string y lo convierto a char
            bambu_meta = new int[2] {array_cartas_temp[3][0] - '0',array_cartas_temp[4][0] - '0'}; //Leo el string, lo convierto a char y luego a int
        }else{  // Estamos en cartas panda
            cantidad = 6;
            std::getline(archivo, linea_temp);

            std::string* array_cartas_temp = lector(cantidad, linea_temp);
            puntaje = array_cartas_temp[1][0] - '0';         //Leo el string, lo convierto a char y luego a int
            tipo = array_cartas_temp[2][0];                 //Leo el string y lo convierto a char
            bambu_meta = new int[3] {array_cartas_temp[3][0] - '0', array_cartas_temp[4][0] - '0', array_cartas_temp[5][0] - '0'};  //Leo el string, lo convierto a char y luego a int
        }
        cartas_jugador[i] = new CartaObjetivo(tipo, puntaje, bambu_meta);
    }

    // Ya con toda la información
    Jugador* jugador = new Jugador(nombre, puntos, bambus_almacenados, cartas_jugador);

    delete[] datos;
    return jugador;
}

int* leer_personaje(std::ifstream& archivo){
    std::string linea;
    std::string* datos;

    std::getline(archivo, linea);  
    datos = lector(3, linea);

    int* posicion = new int [2] {datos[1][0] - '0', datos[2][0] - '0'};

    delete[] datos;
    return posicion;
}


Loseta* leer_loseta(std::string* datos){
    char tipo = datos[2][0];
    int color = datos[3][0] - '0';
    bool irrigado = ((datos[4][0] - '0') == 1)? true:false;
    int cantidad_bambu = datos[5][0] - '0';

    Loseta* loseta = new Loseta(tipo, color, irrigado, cantidad_bambu);
    return loseta;
}


Juego* leer_juego(std::ifstream& archivo, Jugador* j1, Jugador* j2, int* panda, int* jardinero){
    std::string linea_temp;
    std::string* datos;

    std::getline(archivo, linea_temp);  
    datos = lector(8, linea_temp);

    int dimension_tablero = datos[1][0] - '0'; //Leo el string, lo convierto a char y luego a int
    int puntos_por_alcanzar = (datos[2][0] - '0'); //Leo el string, lo convierto a char y luego a int
    int ronda = datos[3][0] - '0'; //Leo el string, lo convierto a char y luego a int
    bool ronda_completa = ((datos[4][0] - '0') == 1)? true:false;
    bool fin_del_juego = ((datos[5][0] - '0') == 1)? true:false;
    int accion_jugador_actual = datos[6][0] - '0'; //Leo el string, lo convierto a char y luego a int

    Jugador* jugador_actual = ((datos[7][0] - '0') == 1)? j1:j2; 

    
    delete[] datos;
    std::getline(archivo, linea_temp);  // Leo el encabezado de tablero

    //Creo mi tablero
    Loseta*** tablero = new Loseta**[dimension_tablero];
    for(int i = 0; i<dimension_tablero; i++){
        tablero[i] = new Loseta*[dimension_tablero];
        for(int j = 0; j<dimension_tablero; j++){
            tablero[i][j] = nullptr;
        }
    }

    while(std::getline(archivo, linea_temp)){
        datos = lector(6, linea_temp);

        tablero[datos[1][0] - '0'][datos[1][1] - '0'] = leer_loseta(datos);
        delete[] datos;
    }

    Juego* juego = new Juego(panda, jardinero, dimension_tablero, puntos_por_alcanzar, ronda, ronda_completa, fin_del_juego, accion_jugador_actual, j1, j2, jugador_actual, tablero);
    return juego;
}

Juego* cargar_juego(){
    std::ifstream archivo{"ArchivoJuego.txt"};  // Abre el archivo para lectura
    Juego* juego;

    if (archivo) {
        Jugador* j1 = leer_jugador(archivo);
        Jugador* j2 = leer_jugador(archivo);

        int* panda = leer_personaje(archivo);
        int* jardinero = leer_personaje(archivo);
        
        juego = leer_juego(archivo, j1, j2, panda, jardinero);


    } else{ // Error al abrir el archivo
        std::cerr << "Error al abrir el archivo." << std::endl;
        perror("Detalle del error");
    }

    return juego;
}