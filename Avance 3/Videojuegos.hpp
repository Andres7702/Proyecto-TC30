//
//  Videojuegos.hpp
//  Proyecto Tienda Videojuegos
//
//  Created by Andrés Acevedo on 19/05/21.
//
//Clase hijade Articulo que ademas de tener todos los atributos de su clase padre, tambien tiene un array de
//objetos tipo plataforma, que son etiquetas que dicen en que plataforma esta disponible este videojuego.


#include <string>
#include <iostream>
#include <stdio.h>
#include "Articulo.hpp"
#include "Plataforma.hpp"

#ifndef Videojuegos_hpp
#define Videojuegos_hpp

class Videojuegos: public Articulo{
public:
    
    
    Videojuegos():Articulo("","","",0,"Videojuego",0,0){}
    
    Videojuegos(string n, string f, string b, double p, int s, int i):Articulo(n,f,b,p,"Videojuego",s,i){
        contador = 0;
    }
    
    void Agregar_Plataforma(Plataforma);
    void Eliminar_Plataforma(int);
    void print_Plataformas();
    
    void imprime_datos();
    
private:
    Plataforma Plataformas[10];
    int contador;
};

void Videojuegos::print_Plataformas(){
    for (int i=0; i < contador+1 ; i++){
        cout<<i+1<<". "<<Plataformas[i].get_name()<<endl;
    }
}

void Videojuegos ::Agregar_Plataforma(Plataforma p){
    Plataformas[contador] = p;
    contador++;
}

void Videojuegos:: Eliminar_Plataforma(int a){
    Plataformas[a-1].set_name("");
    
    for (int i=0; i < 10; i++) {
        if(Plataformas[i].get_name() != ""){
        } else if (Plataformas[i].get_name() == ""){
            for(int k=i+1; k < 10; k++){
                if(Plataformas[k].get_name() != ""){
                    Plataformas[i].set_name(Plataformas[k].get_name());
                    Plataformas[k].set_name("");
                }
                break;
            }
        }
    }
    contador = 0;
    for (int i=0; i < 10; i++) {
        if(Plataformas[i].get_name() != ""){
            contador++;
        }
    }
}

void Videojuegos:: imprime_datos(){
    cout<<"ID: "<< get_ID()<<endl;
    cout<<"Nombre: "<< get_name() <<endl;
    cout<<"Precio: "<< get_price()<<endl;
    cout<<"Descripcion: "<< get_bio()<<endl;
    cout<< "Fecha de Lanzamiento: "<<get_releaseD()<<endl;
    cout<< "Stock: "<<get_stock()<<endl;
    if (contador != 0){
        cout<<"Disponible en siguientes las plataformas: "<<endl;
        print_Plataformas();
    }
    cout<<"\n"<<endl;
}

#endif /* Videojuegos_hpp */
