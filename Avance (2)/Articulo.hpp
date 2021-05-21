//
//Proyecto de Andres Acevedo Caracheo
//A01706897
//

#include <iostream>
#include <stdio.h>
#include <string>

#ifndef Articulo_hpp
#define Articulo_hpp

class Articulo {
public:
    Articulo();
    Articulo(string, string, string, double);
    
    //Metodos
    string get_name();
    string get_releaseD();
    string get_bio();
    double get_price();
    
    void set_name(string);
    void set_date(string);
    void set_bio(string);
    void set_price(double);

private:
    //Declaro mis variables
    string nombre, fecha_lanzamiento, bio;
    double precio;
};

Articulo::Articulo(){
    nombre = " ";
    fecha_lanzamiento = " ";
    bio = " ";
    precio = 0;
}

Articulo::Articulo(string n, string f, string b, double p){
    nombre = n;
    fecha_lanzamiento = f;
    bio = b;
    precio = p;
}

string Articulo :: get_name(){
    return nombre;
}

string Articulo::get_releaseD(){
    return fecha_lanzamiento;
}

string Articulo:: get_bio(){
    return bio;
}

double Articulo:: get_price(){
    return precio;
}

void Articulo:: set_name(string n){
    nombre = n;
}

void Articulo:: set_date(string f){
    fecha_lanzamiento = f;
}

void Articulo:: set_bio(string b){
    bio = b;
}

void Articulo:: set_price(double p){
    precio = p;
}

#endif /* Articulo_hpp */
