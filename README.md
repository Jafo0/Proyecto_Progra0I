# Proyecto_Progra0I
Proyecto programado #1:  TAKENOKO 

Estudiantes:
    -Alejandro Guerra Rodríguez - C13451
    -Jose Loria Wong - 
    -Jaffet


Suposiciones realizadas/Consideraciones generales:
    -Se genera la semilla de números aleatorios en el main. Esta semilla la utiliza "CartaObjetivo" al crear los        puntajes y cartas objetivos.
    -Cada jugador siempre tendrá 2 cartas de cada tipo.
    -Cartas Objetivo:  
        ->Panda: 
            -Entre 1 y 3 bambús por cada color.
            -Estructura: [bambu color 0, bambu color 1, bambu color 2]
        ->Jardinero: 
            -Máximo 4 bambús de un único color.
            -Estructura: [cantidad de bambu, color del bambu]
        ->La evaluación de los bambús recolectados en las cartas objetivo, se hará de manera ordenada. Es decir, se evalúa la primera, luego la segunda, luego la tercera y luego la cuarta.
    -Los colores se trabajarán como enteros. Es decir: color 0, color 1 y color 2.


Pendiente:
    -Corregir el destructor de la clase "Jugador".
    -Mejorar la documentación.

