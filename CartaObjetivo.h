#ifndef CARTAOBJETIVO_H
#define CARTAOBJETIVO_H

class CartaObjetivo{
    
private:
    char tipo;       //'J' si es de objetivo de jardinero, 'P' si es de objetivo de panda
    int puntaje;     //Entre 1 y 4 puntos
    int* bambu_meta; //Los objetivos a cumplir. Varía según si es Panda o Jardinero

public:
    CartaObjetivo(char); //Constructor de la carta. Recibe el tipo panda/jardinero
    ~CartaObjetivo();    //Destructor de la carta
    char getTipo();
    int getPuntaje();
    void imprimir(std::string); //Recibe el nombre de la carta
};

#endif //CARTAOBJETIVO_H