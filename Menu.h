#ifndef MENU_H
#define MENU_H

class Menu{

private:
    int eleccion_actual = -1;
public:
    Menu();
    void setEleccion_actual(int);
    int getEleccion_actual();
    int desplegar();
}

#endif //MENU_H
