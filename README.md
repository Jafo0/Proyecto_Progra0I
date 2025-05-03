# Proyecto_Progra0I
Proyecto programado #1:  TAKENOKO 

Estudiantes:
    -Alejandro Guerra Rodríguez C13451
    -Jose Loria Wong 
    -Jaffet Araya Góngora C4C537


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
    -Losetas:
        -> Una loseta no podrá tener más de 4 bambús.
    -Tablero:
        -> Se representará en una matriz estática de dimensiones 9x9
    -El código NO está hecho a prueba de errores en los que se solicita una entrada entera y el usuario ingresa una entrada de otro tipo.
    -Para el funcionamiento correcto del tablero, al ingresar la dimensión de este, debe ser un número impar.
    -El juego puede finalizar únicamente al inicio de cada ronda. Si ya la ronda empezó, los jugadores deberán terminar sus movimientos.
        


Pendiente:
    -Hacer cada switch case como una función aparte para luego únicamente llamar a la función y dejar más limpio el método "jugar".
    -Intentar hacer el código a prueba de errores.
    -Corregir el movimiento del panda/jardinero.
    -Crear un constructor para las clases: Carta objetivo, Jugador y loseta en la que se reciban todos sus atributos como parámetros (esto para luego poder cargar el archivo de texto)