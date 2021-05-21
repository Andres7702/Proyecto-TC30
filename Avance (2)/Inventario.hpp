//
//Proyecto de Andres Acevedo Caracheo
//A01706897
//

#include "Articulo.hpp"
#include "Videojuegos.hpp"
#include "Consolas.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

#ifndef Inventario_hpp
#define Inventario_hpp

class Inventario {
public:
    Inventario();
    
    Videojuegos get_videojuegos();
    Consolas get_consolas();
    
    void add_videojuego(Videojuegos);
    void add_consola(Consolas);
    
    void eliminar_videojuego();
    void eliminar_consola();
    
    
private:
    Videojuegos VideojuegosDisp[100];
    Consolas ConsolasDisp[100];
};

Inventario::Inventario(){
    
}


#endif /* Inventario_hpp */
