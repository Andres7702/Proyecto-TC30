//
//Proyecto de Andres Acevedo Caracheo
//A01706897
//
//Esta es la clase Articulo que es una clase abstracta Padre de Consola y Videojuego. Esta tiene todos los
//getters y setters de las variables que tienen en comun con Consola y Videojuego.
//Ademas tiene un funcion virtual para imprimir todos sus datos, que despues sera redefinida por sus dos clases hjias.

#include <iostream>
#include <stdio.h>
#include <string>
#include "Plataforma.hpp"

#ifndef Articulo_hpp
#define Articulo_hpp

class Articulo {
public:
    Articulo();
    Articulo(string, string, string, double,string,int,int);
    
    //Metodos
    string get_name();
    string get_releaseD();
    string get_bio();
    double get_price();
    string get_tipo();
    int get_stock();
    int get_ID();
    
    void set_name(string);
    void set_date(string);
    void set_bio(string);
    void set_price(double);
    void agregar_stock(int);

    virtual void imprime_datos()=0;
    
private:
    //Declaro mis variables
    string tipo;
    string nombre, fecha_lanzamiento, bio;
    double precio;
    int stock, ID;
};

// Constructor por Default
Articulo::Articulo(){
    nombre = " ";
    fecha_lanzamiento = " ";
    bio = " ";
    precio = 0;
    tipo = "";
    stock= 0;
    ID=0;
}

// Constructor
Articulo::Articulo(string n, string f, string b, double p, string t, int s,int i){
    nombre = n;
    fecha_lanzamiento = f;
    bio = b;
    precio = p;
    tipo = t;
    stock = s;
    ID=i;
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

string Articulo:: get_tipo(){
    return tipo;
}

int Articulo :: get_stock(){
    return stock;
}

void Articulo:: agregar_stock(int s){
    stock = stock + s;
}

int Articulo:: get_ID(){
    return ID;
}


#endif /* Articulo_hpp */
