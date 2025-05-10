# Proyecto_Progra0I
Proyecto programado #1:  TAKENOKO 

Estudiantes:
    -Alejandro Guerra Rodríguez C13451
    -Jose Loria Wong 
    -Jaffet Araya Góngora C4C537


Suposiciones realizadas/Consideraciones generales:
    -Se genera la semilla de números aleatorios en el main. Esta semilla la utiliza "CartaObjetivo" al crear los        puntajes y cartas objetivos.
    -Cada jugador siempre tendrá 2 cartas de cada tipo.
    -Colores:
        ->Color 0: Amarillo
        ->Color 1: Rosado
        ->Color 2: Verde
        ->Color 3: Azul
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
    -El juego NO está hecho a prueba de errores en cuánto a recepción de datos. Si pide un entero y se ingresa un string, por ejemplo, el código entra en un bucle infinito.
    -El juego SÍ está hecho a prueba de errores en cuanto a ingresar un valor no esperado PERO del mismo tipo de dato. Por ejemplo, el jugador no pierde su turno al intentar irrigar una loseta ya irrigada.
    -Al imprimir el tablero, la codificación es la siguiente: Primeros dos números son identificador de posición. El asterisco indica si la loseta está irrigada. El subrayado indica la posición del jardinero. El tachado indica la posición del panda. La loseta estanque es la azul. Las posiciones blancas corresponden a espacios vacíos, NO CONTIENEN LOSETAS. El resto de colores, son para el color de loseta generada.

    ->Sobre el tablero:
        -Máximo de 9x9
    ->Restricciones sobre los bambús:   
        -Una carta objetivo de tipo jardinero puede tener entre 1 y 5 bambús de un mismo color
        -Una carta objetivo de tipo panda puede tener entre 1 y 3 bambús de cada color
        -Una loseta puede tener máximo 9 bambús


        


Pendiente:
    -Hacer las limitaciones de movimiento del panda/jardinero.
    

Preguntas:
    -El código debe ser a prueba de errores en cuánto a la entrada de un dato de otro tipo?