#ifndef LOSETA_H
#define LOSETA_H

#include <iostream>
#include <string>
#include <cstdlib>  //para rand
#include <ctime>    //para time

class Loseta{
private:                                // Jugador solo puede poner loseta 'N'
    char tipo_loseta;                   //el tipo: si es loseta normal 'N' o loseta estanque 'E' 
    int color{3};                       //Estructura: [loseta color 0, loseta color 1, loseta color 2, loseta color 3 estanque,
    bool irrigado;                
    int cantidad_bambu;                 // Todas inician sin bambu
public:
    Loseta(char);                //constructor loseta normal, recibe tipo y color este utimo es random
    Loseta(char, int, bool, int);
    ~Loseta();
    void escribir_loseta(std::ofstream&, int, int);

    Loseta* leer_loseta(std::string*);

    char get_tipo();
    int get_color();
    bool get_irrigado();
    int get_cantidad_bambu();

    void crecer_bambu();
    void decrecer_bambu();
    void irrigar();
    void imprimir_loseta(int, int, bool, bool, int);
};

#endif //LOSETA_H
