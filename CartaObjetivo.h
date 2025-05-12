#ifndef CARTAOBJETIVO_H
#define CARTAOBJETIVO_H

#include <string>

class CartaObjetivo{
    
private:
    char tipo;       //'J' si es de objetivo de jardinero, 'P' si es de objetivo de panda
    int puntaje;     //Entre 1 y 4 puntos
    int* bambu_meta; //Los objetivos a cumplir. Varía según si es Panda o Jardinero

public:
    CartaObjetivo(char); //Constructor de la carta. Recibe el tipo panda/jardinero
    CartaObjetivo(char, int, int*);
    ~CartaObjetivo();    //Destructor de la carta
    void escribir_carta_objetivo(std::ofstream&);
    CartaObjetivo* leer_carta_objetivo(std::string*);

    char getTipo();
	int* getBambuMeta();
    int getPuntaje();

    void imprimir(std::string); //Recibe el nombre de la carta
};

#endif //CARTAOBJETIVO_H