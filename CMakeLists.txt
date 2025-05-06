cmake_minimum_required(VERSION 3.25)
project(nueva_carpeta)
set(CMAKE_CXX_STANDARD 17)

add_executable(nueva_carpeta
        main.cpp
        CartaObjetivo.cpp
        Loseta.cpp
        Jugador.cpp
        Menu.cpp
        Juego.cpp
)