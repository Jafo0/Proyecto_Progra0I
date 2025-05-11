#include "Juego.h"
#include "Menu.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

Juego::Juego(std::string nombre_j1, std::string nombre_j2, int dimension, int puntos): dimension_tablero(dimension), puntos_juego(puntos){
    this->j1 = new Jugador(nombre_j1);
    this->j2 = new Jugador(nombre_j2);
    this->jugador_actual = this->j1;

    if(this->dimension_tablero>9){this->espacio_texto = 8;}    //Necesario a la hora de imprimir el tablero

    //Creo mi tablero
    this->tablero = new Loseta**[dimension];
    for(int i = 0; i<dimension; i++){
        this->tablero[i] = new Loseta*[dimension];
        for(int j = 0; j<dimension; j++){
            this->tablero[i][j] = nullptr;
        }
    }

    this->tablero[dimension/2][dimension/2] = new Loseta('E');  //Inicializo loseta estanque

    this->panda[0] = dimension/2;
    this->panda[1] = dimension/2;
    this->jardinero[0] = dimension/2;
    this->jardinero[1] = dimension/2;


    guardar_en_archivo();
} 

// Juego::Juego(Jugador* ja, Jugador* jb, int dimension, int panda_x, int panda_y, int jardinero_x, int jardinero_y, Jugador* j_actual, Loseta*** t): j1(ja), j2(jb), dimension_tablero(dimension), jugador_actual(j_actual), tablero(t){
// 	this->panda[0] = panda_x;
// 	this->panda[1] = panda_y;
// 	this->jardinero[0] = jardinero_x;
// 	this->jardinero[1] = jardinero_y;
// }
/*
Aquí va el constructor que recibe todos los atributos y los inicializa
*/

Juego::~Juego(){}

void Juego::alternar_jugador(){
    if(this->jugador_actual == this->j2){
        this->ronda++;
        this->ronda_completa = true;
    }else{
        this->ronda_completa = false;
    }
    this->jugador_actual = (this->jugador_actual == this->j1)? this->j2 : this->j1;
    this->accion_jugador_actual = 1;
}

void Juego::imprimir_tablero(){
    // Información del tablero:
    cout<<"----------------------------------------------"<<"Tablero"<<"----------------------------------------------"<<endl;
    
    // Imprimimos la tapa superior: -----------------------------------------------------------------------
    for(int i = 0; i < this->dimension_tablero; i++) {    
        cout<<" "<<std::string(this->espacio_texto, '_')<<std::string(this->espacio_texto, ' ')<<" ";
    }
    cout<<endl;

    for(int i = 0; i < this->dimension_tablero; i++){       // Recorremos filas. Por cada fila, hacer lo siguiente: 
        // Imprimimos el lado superior con la información de la loseta: ---------------------------------------
        for(int j = 0; j < this->dimension_tablero; j++){               // Recorremos columnas
            if(i%2 != 0){       // Si la fila es impar
                if(j == 0){     
                    cout<<"\\";     // Agregamos un '\' solo para el elemento de la primera columna
                }
                cout<<std::string(this->espacio_texto, '_');}    

            if (this->tablero[i][j] == nullptr) {                       // Loseta no definida
                cout<<"/";
                std::string texto = std::to_string(i)+std::to_string(j);
                cout << std::left << std::setw(this->espacio_texto) << std::setfill(' ') << texto;
                cout<<"\\";
            }else{
                bool jardinero = false;
                bool panda = false;
                cout<<"/";
                if(i == this->jardinero[0] && j == this->jardinero[1]){jardinero = true;}
                if(i == this->panda[0] && j == this->panda[1]){panda = true;}
                this->tablero[i][j]->imprimir_loseta(i,j, jardinero, panda, this->espacio_texto);
                cout<<"\\";
            }
            if(i%2 == 0){   // Si la fila es par
                cout<<std::string(this->espacio_texto, '_');
                if((j == this->dimension_tablero-1) && (i != 0)){   
                cout<<"/";  // Agregamos un '\' solo para el elemento de la última columna
                }   
            }
        }
        cout<<endl; 
    }
    // Imprimimos la tapa inferior: -----------------------------------------------------------------------
    for(int i = 0; i < this->dimension_tablero; i++) {    
        cout<<"\\"<<std::string(this->espacio_texto, '_')<<"/"<<std::string(this->espacio_texto, ' ');
    }
    cout<<endl;
}

void Juego::mostrar_estado_del_juego(){
    // Información de los jugadores: 
    this->j1->imprimir();
    this->j2->imprimir();
    cout<<endl;
    imprimir_tablero();
    cout<<"\nPuntos por alcanzar: "<<this->puntos_juego<<"\t\t|\t"<<"Ronda: "<<this->ronda<<"\t|\tTurno de: "<<this->jugador_actual->get_nombre()<<"\t|\tAccion #: "<<this->accion_jugador_actual<<endl;
}


void Juego::guardar_en_archivo(){
    std::ofstream archivo {"ArchivoJuego.txt"};
    archivo<<"Juego,"<<this->puntos_juego<<","<<this->dimension_tablero<<","<<this->ronda<<","<<this->jugador_actual->get_nombre()<<endl;

    this->j1->escribir_jugador(archivo);
    this->j2->escribir_jugador(archivo);

    archivo<<"\t\tTablero:"<<endl;
    for(int i = 0; i < this->dimension_tablero; i++) {
        for(int j = 0; j < this->dimension_tablero; j++) {
            if(this->tablero[i][j] != nullptr){this->tablero[i][j]->escribir_loseta(archivo,i,j);}
        }
    }
}



bool Juego::comprobar_adyacencia(int i, int j, bool irrigacion){            //metodo para saber si tengo una loseta adyacente. 'Irrigacion' me dice si estoy buscando que haya loseta adyacente irrigada
    int adyacentes_i[6], adyacentes_j[6];                  //me define cuales son adyacentes para cada posicion
    int aux_i[6]={-1, -2, -1, 1, 2, 1};

    if((i%2 == 0 && j%2 == 0) || (i%2 == 0 && j%2 != 0)){ //(P,P)=(P,I) con p par e i impar
        int aux_j[6]= {0, 0, -1, 0, 0, -1};
        for(int m = 0; m < 6; m++){
            adyacentes_i[m]=aux_i[m];
            adyacentes_j[m]=aux_j[m];
        }
    }else{                                                //(I.I)=(I,P)
        int aux_j[6]= {1, 0, 0, 1, 0, 0};
        for(int m = 0; m < 6; m++){
            adyacentes_i[m]=aux_i[m];
            adyacentes_j[m]=aux_j[m];
        }
    }
    for(int m=0; m<6;m++){                               //comprobar vecinos de esta loseta
        int nuevo_i = i + adyacentes_i[m];
        int nuevo_j = j + adyacentes_j[m];
        if(0<=nuevo_i && nuevo_i<this->dimension_tablero && 0<=nuevo_j && nuevo_j< this->dimension_tablero){    //Solo para elementos dentro del tablero
            if(irrigacion){ // Si buscamos adyacencia de irrigacion
                if(this->tablero[nuevo_i][nuevo_j] != nullptr && this->tablero[nuevo_i][nuevo_j]->get_irrigado()==true){    // Hay loseta adyacente irrigada
                    return true;
                }
            } else{ // Si buscamos solo adyacencia
                if(this->tablero[nuevo_i][nuevo_j] != nullptr){return true;}    // Hay loseta adyacente
            }
        }
    }
    return false;
}

/*
bool Juego::movimiento_general(int posiciones, int movimiento,int i, int j){
    int i_actual = this->panda[0];
    int j_actual = this->panda[1];
    
}
*/

bool Juego::crecer_jardin(int i, int j){
    if (i == this->dimension_tablero/2 && j == this->dimension_tablero/2){ // Si es la loseta estanque
        cout<<"\n\033[1;31m"<<"La casilla ingresada corresponde a la estanque. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(this->tablero[i][j] != nullptr){  // Ya hay una loseta en ese espacio
        cout<<"\n\033[1;31m"<<"La casilla ingresada ya contiene una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(!comprobar_adyacencia(i,j,false)){
        cout<<"\n\033[1;31m"<<"La casilla ingresada no es adyacente a una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } 
    else{
        this->tablero[i][j] = new Loseta('N');
        return true;
    }
}

bool Juego::regar_loseta(int i, int j){
    if(this->tablero[i][j] == nullptr){ //Si no hay loseta creada
        cout<<"\n\033[1;31m"<<"La casilla ingresada no contiene una loseta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    } else if(this->tablero[i][j]->get_irrigado()){
        cout<<"\n\033[1;31m"<<"La casilla ingresada ya contiene una loseta irrigada. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    }else if(!comprobar_adyacencia(i,j,true)){
        cout<<"\n\033[1;31m"<<"La Loseta no puede ser irrigada pues ninguna a su alrededor lo esta. Vuelva a intentar."<<"\033[0m"<<endl;
        return false;
    }else {
        this->tablero[i][j]->irrigar();
        return true;
    }
}
void Juego::nueva_posicion_jardinero(int i, int j){    //En este punto, la posición indicada sí contiene una loseta
    this->jardinero[0] = i;     // Defino la nueva posición del jardinero
    this->jardinero[1] = j;
    
    if(this->tablero[this->jardinero[0]][this->jardinero[1]]->get_cantidad_bambu() == 9){
        cout<<"\n\033[1;31m"<<"El jardinero fue movido pero no crecio bambu, porque el maximo por loseta es de 9."<<"\033[0m"<<endl;
        cout<<"\n\033[1;31m"<<"Presione lo que sea para continuar: "<<"\033[0m";    //Esto es para darle tiempo al usuario de leer y entender
        std::string basura;
        cin>>basura;
    } else{ //Si tiene menos de 9 bambús, crece uno
        this->tablero[this->jardinero[0]][this->jardinero[1]]->crecer_bambu();
    }
}
bool Juego::nueva_posicion_panda(int i, int j){
    this->panda[0] = i;     // Defino la nueva posición del panda
    this->panda[1] = j;
    int color = this->tablero[i][j]->get_color();                           // Veo el color de la loseta
    if(color != 3){ //Si no es la loseta estanque
        if(this->tablero[this->panda[0]][this->panda[1]]->get_cantidad_bambu() > 0){   //La loseta a la que movimos el panda tiene bambu
            this->tablero[this->panda[0]][this->panda[1]]->decrecer_bambu();    // Reduzco un bambu
            this->jugador_actual->recolectar_bambu(color);      // Le sumo un bambu al jugador
            /*
            Aquí se llama a la función de evaluar carta objetivo con bambu recolectado
            */
        } 
    }    

}

bool Juego::mover_personaje(int cantidad, int sentido, int i_temp, int j_temp, int mov_realizados, bool es_jardinero){
    if(cantidad == mov_realizados){ //Cumplimos la cantidad de movimientos
        if(es_jardinero){nueva_posicion_jardinero(i_temp, j_temp);}
        else{nueva_posicion_panda(i_temp, j_temp);}
        return true;
    }else{  //No hemos completado la cantidad de movimientos
        int i_siguiente, j_siguiente;   //Defino la casilla del próximo movimiento
        switch (sentido) {
            case 1: // Arriba izquierda
                if(i_temp%2 != 0){  //Estoy en fila impar
                    i_siguiente = i_temp - 1;
                    j_siguiente = j_temp;
                }else{  // Estoy en fila par
                    i_siguiente = i_temp - 1;
                    j_siguiente = j_temp - 1;
                }
                break;
            case 2: // Arriba
                i_siguiente = i_temp - 2;
                j_siguiente = j_temp;
                break;
            case 3: // Arriba derecha
                if(i_temp%2 != 0){  //Estoy en fila impar
                    i_siguiente = i_temp - 1;
                    j_siguiente = j_temp + 1;
                }else{  // Estoy en fila par
                    i_siguiente = i_temp - 1;
                    j_siguiente = j_temp;
                }
                break;
            case 4: // Abajo izquierda
                if(i_temp%2 != 0){  //Estoy en fila impar
                    i_siguiente = i_temp + 1;
                    j_siguiente = j_temp;
                }else{  // Estoy en fila par
                    i_siguiente = i_temp + 1;
                    j_siguiente = j_temp - 1;
                }
                break;
            case 5: // Abajo
                i_siguiente = i_temp + 2;
                j_siguiente = j_temp;
                break;
            case 6: // Abajo derecha
                if(i_temp%2 != 0){  //Estoy en fila impar
                    i_siguiente = i_temp + 1;
                    j_siguiente = j_temp + 1;
                }else{  // Estoy en fila par
                    i_siguiente = i_temp + 1;
                    j_siguiente = j_temp;
                }
                break;
        }
        //Casos para terminar o continuar la recursión
        if(0<=i_siguiente && i_siguiente<this->dimension_tablero && 0<=j_siguiente && j_siguiente<this->dimension_tablero){ //Estaré dentro del tablero
            if(this->tablero[i_siguiente][j_siguiente] == nullptr){ // En el movimiento siguiente no hay loseta
                cout<<"\n\033[1;31m"<<"Esa cantidad de espacios para este movimiento no se puede porque llegamos a una loseta nula. Vuelva a intentar."<<"\033[0m"<<endl;
                return false;
            }else{  // En el movimiento siguiente sí hay loseta
                return mover_personaje(cantidad, sentido, i_siguiente, j_siguiente, mov_realizados+1, es_jardinero);
            }
        }else{  // Estaré fuera del tablero
            cout<<"\n\033[1;31m"<<"Esa cantidad de espacios para este movimiento se sale de las dimensiones del tablero. Vuelva a intentar."<<"\033[0m"<<endl;
            return false;
        }
    }
}

bool Juego::realizar_accion(){
    int accion = desplegar();   //Escogemos la acción que vamos a realizar
    int direccion_mov, cant, posicion, i, j;    //Variables necesarias
    if(accion == 5){    // Fin del juego
        this->fin_del_juego = true;
        return true;
    }else { // Cualquier acción que no sea finalizar el juego
        if(accion == 3 || accion==4){  // Movemos jardinero/panda
            direccion_mov = menu_mov();
            while(true){
                cout<<"\nIngrese la cantidad de espacios que desea moverse en esa direccion: ";
                cin>>cant;
                if(cant<1){
                    cout<<"\nIngrese una cantidad de espacios mayor a cero";
                }else{break;}
            }
            if(accion == 3){return mover_personaje(cant, direccion_mov, this->jardinero[0], this->jardinero[1], 0, true);}
            else{return mover_personaje(cant, direccion_mov, this->panda[0], this->panda[1], 0, false);} 
        }else{  //Crear/Irrigar loseta
            cout<<"\nIngrese la casilla de la accion a realizar: ";
            cin>>posicion;

            i = posicion/10;
            j = posicion%10;

            if(i<0||this->dimension_tablero-1<i||j<0||this->dimension_tablero-1<j){  // La entrada se sale de las dimensiones del tablero
                cout<<"\n\033[1;31m"<<"La casilla se sale de las dimensiones del tablero. Vuelva a intentar."<<"\033[0m"<<endl;
                return false;
            }  
            if(accion == 1){return crecer_jardin(i, j);}    //Crecer jardín
            else{return regar_loseta(i, j);}    // Regar loseta
        }
    }
}

void Juego::revisar_ganador(){
    if(this->j1->get_puntos() >= this->puntos_juego || this->j2->get_puntos() >= this->puntos_juego){
        this->fin_del_juego = true;
        if(this->j1->get_puntos() == this->j2->get_puntos()){
            cout<<"El juego terminó en empate"<<endl;
        }else if(this->j1->get_puntos() > this->j2->get_puntos()){
            cout<<"El jugador: "<<this->j1->get_nombre()<<", ha ganado. Felicidades!"<<endl;
        }else {
            cout<<"El jugador: "<<this->j2->get_nombre()<<", ha ganado. Felicidades!"<<endl;
        }
    }  
}

void Juego::jugar(){
    while(!this->fin_del_juego){
        
        system("cls");    // Limpio la terminal
        mostrar_estado_del_juego();
        while(!realizar_accion());
        guardar_en_archivo();
        this->accion_jugador_actual++;
        if(accion_jugador_actual == 3){
            alternar_jugador();
        }
        if(this->ronda_completa){   // Si terminamos una ronda
            revisar_ganador();
        }
    }
}