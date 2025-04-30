#ifndef LOSETA_H
#define LOSETA_H
#include <iostream>
#include <string>
#include <cstdlib>  //para rand
#include <ctime>    //para time

const int N = 30;
class Loseta{
private:                          //Jugador solo puede poner loseta 'N'
    char tipo_loseta;             //el tipo: si es loseta normal 'N' o loseta estanque 'E'  
    int color{0};            //Estructura: [loseta color 0 estanque, loseta color 1, loseta color 2, loseta color 3, 
    bool irrigado;                
    int cantidad_bambu;
    
    Loseta* superior{nullptr};
    Loseta* inferior{nullptr};
    Loseta* izquierda_arriba{nullptr};
    Loseta* izquierda_abajo{nullptr};
    Loseta* derecha_arriba{nullptr};
    Loseta* derecha_abajo{nullptr};
public:
    Loseta(char tipo_e);        //constructor loseta normal, recibe tipo y color este utimo es random
    //~Loseta();
    void crecer_bambu();
    void decrecer_bambu();
    void conectar_superior(Loseta* loseta);
    void conectar_inferior(Loseta* loseta);
    void conectar_izquierda_arriba(Loseta* loseta);
    void conectar_izquierda_abajo(Loseta* loseta);
    void conectar_derecha_arriba(Loseta* loseta);
    void conectar_derecha_abajo(Loseta* loseta);
    //void iniciar_centro();
    //void agregar_loseta();
    //void mostrar_matriz();
    
};

#endif //LOSETA_H
