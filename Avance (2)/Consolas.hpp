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

#ifndef Consolas_hpp
#define Consolas_hpp

class Consolas: public Articulo{
public:
    
    Consolas():Articulo(){
        Modelo = "";
    }
    Consolas(string n, string f, string b, double p, string m):Articulo(n,f,b,p){
        Modelo = "";
    }

    string get_modelo();
    void set_modelo(string);
    
private:
    string Modelo;
    
};

string Consolas:: get_modelo(){
    return Modelo;
}

void Consolas:: set_modelo(string m){
    Modelo = m;
}

#endif /* Consolas_hpp */
