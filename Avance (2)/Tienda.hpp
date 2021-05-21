//
//Proyecto de Andres Acevedo Caracheo
//A01706897
//

#include "Articulo.hpp"
#include "Videojuegos.hpp"
#include "Consolas.hpp"
#include "Inventario.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

#ifndef Tienda_hpp
#define Tienda_hpp

class Tienda {
public:
    Tienda();
    
    void Venta(Videojuego);
    
private:
    Inventario InventarioTienda();
};


#endif /* Tienda_hpp */
