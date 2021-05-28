//
//  Plataforma.hpp
//  Proyecto Tienda Videojuegos
//
//  Esta clase es para plataformas que basicamente son etiquetas para los objetos de tipo Videojuego.
//  la clase ya esta completa pero estoy teniendo unos problemas implementandola en los objetos de Videojuego.

#include <stdio.h>
#include <string>

#ifndef Plataforma_hpp
#define Plataforma_hpp

class Plataforma {
public:
    Plataforma();
    Plataforma(string);
    
    void set_name(string);
    string get_name();
    
private:
    string name;
};

Plataforma::Plataforma(){
    name = "";
}

Plataforma::Plataforma(string n){
    name = n;
}

void Plataforma :: set_name(string n){
    name = n;
}

string Plataforma:: get_name(){
    return name ;
}

#endif /* Plataforma_hpp */
