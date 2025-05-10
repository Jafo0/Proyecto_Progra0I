#include <iostream>
#include "Jugador.h" 
using std::cout; 
using std::endl;

Jugador::Jugador(std::string _nombre): nombre(_nombre){
    for(int i = 0; i < 3; i++){this->bambus_almacenados[i] = 0;}    //Iniciamos sin bambus almacenados

    //Definimos las cartas objetivos
    this->cartas_jugador = new CartaObjetivo*[4];
    this->cartas_jugador[0] =  new CartaObjetivo('J');     //2 cartas Jardinero
    this->cartas_jugador[1] =  new CartaObjetivo('J');
    this->cartas_jugador[2] =  new CartaObjetivo('P');     //2 cartas Panda
    this->cartas_jugador[3] =  new CartaObjetivo('P');  
}

   Jugador::Jugador(std::string _nombre, int _puntos, int _bambus_almacenados[], CartaObjetivo** _cartas_jugador){
    this->nombre = _nombre;
    this->puntos = _puntos;
    for(int i = 0; i < 3; i++){
        this->bambus_almacenados[i] = _bambus_almacenados[i];
    }
    this->cartas_jugador = _cartas_jugador;
}

Jugador::~Jugador(){
    for(int i = 0; i < 4; ++i) {
        delete cartas_jugador[i];  // Elimino cada objeto
    }
    delete[] cartas_jugador;       // Elimino el array de punteros
}

std::string Jugador::get_nombre(){return this->nombre;}

void Jugador::imprimir(){
    cout<<"\n"<<"--------------------------------------"<<"Jugador: "<<this->nombre<<"--------------------------------------"<<endl;
    cout<<"Puntaje Acumulado: "<<this->puntos<<endl;
    cout<<"Bambus almacenados [";
    for (int i=0; i<3;i++){
       cout<<bambus_almacenados[i];
       if (i < 2) cout << ", ";
    }
    cout<<"]\t\t\t\t\t\tEstructura: [#bambu color 1, #bambu color 2, #bambu color 3]"<<endl;

    std::string nombre_carta;
    cout<<"Cartas: "<<endl;
    for(int i = 0; i < 4; i++){
        nombre_carta = "";
        nombre_carta = "C" + std::to_string(i+1);
        this->cartas_jugador[i]->imprimir(nombre_carta);
    }  
}
void Jugador::recolectar_bambu(int color){
    if (color >= 0 && color < 3){
        if(bambus_almacenados[color]<3){
            bambus_almacenados[color]++; 
        }
    }
}
int Jugador::get_bambu_por_color(int color){
    return bambus_almacenados[color];
}
void Jugador::evaluar_panda(Loseta*** tablero, int dimension_tablero)
{
    //Revisa solamente la loseta que tiene el panda
    for (int i = 0; i < dimension_tablero; i++)
    {
        for (int j = 0; j < dimension_tablero; j++)
        {
            if (tablero[i][j]->get_esta_panda() == true)
            {
                int color = tablero[i][j]->get_color();
                switch (color)
                {
                    case 0:
                        this->bambus_almacenados[0]++;
                        break;
                    case 1:
                        this->bambus_almacenados[1]++;
                        break;
                    case 2:
                        this->bambus_almacenados[2]++;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    for (int c = 0; c < 4; c++)
    {
        if (this->cartas_jugador[c]->getTipo() == 'P')
        {
            for (int b = 0; b < 3; b++)
            {
                if (this->cartas_jugador[c]->getBambuMeta()[b] <= this->bambus_almacenados[b])
                {
                    this->puntos += this->cartas_jugador[c]->getPuntaje();
                }
            }
        }
    }
}