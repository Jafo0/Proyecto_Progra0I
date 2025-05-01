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
    int color{0};                 //Estructura: [loseta color 0 estanque, loseta color 1, loseta color 2, loseta color 3, 
    bool irrigado;                
    int cantidad_bambu;
public:
    Loseta(char tipo_e);        //constructor loseta normal, recibe tipo y color este utimo es random
    ~Loseta();
    void crecer_bambu();
    void decrecer_bambu();
};

#endif //LOSETA_H
