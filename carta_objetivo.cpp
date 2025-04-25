#include <iostream>
#include "carta_objetivo.h"

Carta_objetivo::Carta_objetivo(std::string jugador_e)
{
    this->jugador = jugador_e;
    this->setPuntaje();
    this->setTipo();
}

Carta_objetivo::~Carta_objetivo()
{
    delete[] this->meta;
}

std::string Carta_objetivo::getJugador()
{
    return this->jugador;
}

void Carta_objetivo::setPuntaje()
{
    srand(time(NULL));
    this->puntaje = (rand() % 4) + 1;
}

int Carta_objetivo::getPuntaje()
{
    return this->puntaje;
}

void Carta_objetivo::setTipo()
{
    srand(time(NULL));
    int num = (rand() % 2);

    switch (num)
    {
        case 0:
            //tipo objetivo de jardinero
            this->tipo = 'J';
            break;
        case 1:
            //tipo objetivo de panda
            this->tipo = 'P';
            break;
        default:
            break;
    }
}

char Carta_objetivo::getTipo()
{
    return this->tipo;
}

void Carta_objetivo::setMeta()
{
    //Si es panda, unidades de bambu y más de un color
    //Si es jardinero, torres de bambu de un solo color
    this->meta = new int[3];
    srand(time(NULL));
    if (this->tipo == 'J')
    {
        for (int i = 0; i < 2; i++)
        {
            //meta[0] = bambu rosa, meta[1] = bambu amarillo, meta[2] = bambu verde
            this->meta[i] = (rand() % 5);
        }
    } else if (this->tipo == 'P')
    {
        //meta[0] = bambu rosa, meta[1] = bambu amarillo, meta[2] = bambu verde
        int num = (rand() % 3);
        switch (num)
        {
        case 0:
            //meta[0] = bambu rosa
            this->meta[0] = (rand() % 4) + 1;
            break;
        case 1:
            //meta[1] = bambu amarillo
            this->meta[1] = (rand() % 4) + 1;
            break;
        case 2:
            //meta[2] = bambu verde
            this->meta[2] = (rand() % 4) + 1;
            break;
        default:
            break;
        }
    }
}

bool Carta_objetivo::evaluar(/*Parametro*/){} //Metodo para evaluar si el jugador cumple los requerimientos
//No se como es el tablero, o los jugadores, asi que habra que trabajar en esto para despues

void Carta_objetivo::imprimir()
{
    if (this->tipo == 'J')
    {
        std::cout << "Objetivo torre: " << this->meta[0] << " de bambu rosa, " << this->meta[1] << " de bambu amarillo, "
        << this->meta[2] << " de bambu verde" <<std::endl;
    } else if (this->tipo == 'P')
    {
        std::cout << "Objetivo unidades en tablero: " << this->meta[0] << " de bambu rosa, " << this->meta[1] << " de bambu amarillo, "
        << this->meta[2] << " de bambu verde" <<std::endl;
    }
}