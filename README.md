# Proyecto_Progra0I
Proyecto programado #1:  TAKENOKO 

Estudiantes:
    -Alejandro Guerra Rodríguez C13451
    -Jose Loria Wong C34430
    -Jaffet Araya Góngora C4C537

-------------------------------------------------------------------------------------------
Consideraciones/Suposiciones para cada clase:
-------------------------------------------------------------------------------------------
ArchivoJuego:
    Guarda en el siguiente orden: Jugador1, Jugador2, Juego. Utiliza el siguiente formato:
        -Si es Carta Jardinero: "CartaObjetivo, puntaje, tipo, cantidad, color"
        -Si es Carta Panda: "CartaObjetivo, puntaje, tipo, cantidad1, cantidad2, cantidad3"
        -Si es Jugador: "Jugador, nombre, puntaje, bambus1, bambus2, bambus2"
            Carta Jardinero 1...
            Carta Jardinero 2...
            Carta Panda 1...
            Carta Panda 2...
        -Si es Loseta: "Loseta, posicion, tipo, color, irrigacion, cantidad" 
        -Si es Juego: "Juego, dimension, puntos, ronda, ronda_completa, fin del juego, #accion jugador actual, jugador actual"
            Tablero: Imprime solo las losetas activas

CartaObjetivo:
    -General:
        -Puntaje entre 1 y 3.

    -Si es Panda:
        -Entre 1 y 3 bambús por cada color.
        -Estructura: [bambu color 0, bambu color 1, bambu color 2]

    -Si es Jardinero: 
            -Entre 1 y 5 bambús de un único color.
            -Estructura: [cantidad de bambu, color del bambu]

FuncionesComplementarias:
    -General:
        -Son funciones que desarrollamos en un archivo aparte y que necesita el código de Juego.
        -La función: 'std::string* lector(int, std::string)' lo que hace es leer un string y hacer un array de strings de la cantidad de espacios indicados donde cada elemento es el valor de la línea que está separado por comas.
        -El resto de funciones son para construir un jugador, loseta, juego y panda/jardinero a partir del formato del archivo de texto.

Juego:
    -General:
        -Se define un jugador activo.
        -Se evalúa si el jugador activo cumplió una carta de panda únicamente después de haber hecho un mov. válido de panda.
        -Para ambos jugadores, se evalúa si cumplieron una carta jardinero únicamente después de que alguno haya hecho un mov. válido de jardinero. El jardinero debe estar en la loseta.
        -Los puntos para finalizar el juego son 9.
        -El tablero es de máximo 9x9. 
        -Codificacion del tablero:
            -Las casillas blancas indican que NO HAY LOSETA
            -Las casillas de color:
                -El color indica el color de la loseta (azul para estanque)
                -Los primeros dos números son el identificador de la casilla
                -La P indica la posición del panda
                -La J indica la posición del jardinero
                -El * indica si hay irrigación
                -El último número indica la cantidad de bambús (solo se indica si es mayor a cero)
        -Después de cada acción, el juego se guarda automáticamente
    -Cargar Juego:
        -Para la primera partida se adjunta un archivo de juego de prueba

Jugador:
    -General:
        -Un jugador puede tener máximo 9 puntos. Si por alguna razón consigue una carta en la que se le sumarían más de 9 puntos, se le rebajan automáticamente a 9.

Loseta:
    -General:
        -Puede tener máximo 9 bambús.

Main:
    -Se genera la semilla de números aleatorios en el main a pesar de que otras clases las utilizen.

Otras consideraciones:
    -El código está hecho a prueba de errores del tipo valor fuera de rango.
    -El código NO está hecho a prueba de errores del tipo entrada de otro tipo. Por ejemplo, que pida un int y recibe un string.
    -La evaluación de los bambús recolectados en las cartas objetivo, se hará de manera ordenada. Es decir, se evalúa la primera, luego la segunda, luego la tercera y luego la cuarta.
    -El cargar una partida funciona solo si el archivo de ArchivoJuego.txt contiene información. Por eso, se adjunta el contenido de una partida inicial de prueba.



-------------------------------------------------------------------------------------------
Cómo compilar y ejecutar el código
-------------------------------------------------------------------------------------------
Paso 1: Debe tener todos los archivos en una misma carpeta y compilarlo de la siguiente manera:
    g++ .\CartaObjetivo.cpp .\FuncionesComplementarias.cpp .\Juego.cpp .\Jugador.cpp .\Loseta.cpp .\main.cpp
Paso 2: Debe seguir las instrucciones que se despliegan en pantalla.
    -En caso de ingresar una entrada errónea (por ejemplo un string cuando pedía int), el código generará un error y puede entrar en un loop infinito. Presione ctrl + c para cerrar el archivo. Vuelva a ejecutar el código y seleccione la opción de cargar desde archivo.
    -Si como primera acción se desea cargar una partida, se adjunta como texto de ArchivoJuego.txt la información de una primera partida de prueba.