//
//  Videojuegos.hpp
//  Proyecto Tienda Videojuegos
//
//  Created by Andrés Acevedo on 19/05/21.
//
#include <string>
#include <iostream>
#include <stdio.h>
#include "Articulo.hpp"

#ifndef Videojuegos_hpp
#define Videojuegos_hpp

class Videojuegos: public Articulo{
public:
    
    
    Videojuegos():Articulo(){
    }
    Videojuegos(string n, string f, string b, double p):Articulo(n,f,b,p){
    }
    
    string get_Plataformas();
    
    void Agregar_Plataforma(string);
    string Eliminar_plataforma(int);
    
private:
    char Plataformas[10];
};

string Videojuegos::get_Plataformas(){
    return Plataformas;
}


#endif /* Videojuegos_hpp */
