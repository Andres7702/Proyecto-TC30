//
//  Videojuegos.hpp
//  Proyecto Tienda Videojuegos
//
//  Created by Andrés Acevedo on 19/05/21.
//
//Clase hija de Articulo que ademas de todos los atributos de la clase padre tambien tiene una variable
//de tipo string que dice cual es el modelo de la consola.

#include <string>
#include <iostream>
#include <stdio.h>
#include "Articulo.hpp"
#include "Plataforma.hpp"

#ifndef Consolas_hpp
#define Consolas_hpp

class Consolas: public Articulo{
public:
    
    Consolas():Articulo("","","",0,"Consola",0,0){
        Modelo = "";
    }
    Consolas(string n, string f, string b, double p, string m, int s, int i):Articulo(n,f,b,p,"Consola",s,i){
        Modelo = m;
    }

    string get_modelo();
    void set_modelo(string);
    void imprime_datos();
    
private:
    string Modelo;
    
};

string Consolas:: get_modelo(){
    return Modelo;
}

void Consolas:: set_modelo(string m){
    Modelo = m;
}

void Consolas:: imprime_datos(){
    cout<<"ID: "<< get_ID()<<endl;
    cout<<"Nombre: "<< get_name() <<endl;
    cout<<"Precio: "<< get_price()<<endl;
    cout<<"Descripcion: "<< get_bio()<<endl;
    cout<< "Fecha de Lanzamiento: "<<get_releaseD()<<endl;
    cout<<"Modelo: "<<get_modelo()<<endl;
    cout<< "Stock: "<<get_stock()<<endl;
    cout<<"\n"<<endl;
}

#endif /* Consolas_hpp */
