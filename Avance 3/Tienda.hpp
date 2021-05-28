//
//Proyecto de Andres Acevedo Caracheo
//A01706897
//

//Clase Tienda que tiene un array de objetos tipo articulo, que a traves de polimorfismo podemos llenar con
//objetos de tipo Videojuego o Consola.
//Ademas la clase tiene funciones que nos permitiran añadir cosas al inventario o conseguir su informacion para que
//el usuario las pueda ver.

#include "Articulo.hpp"
#include "Videojuegos.hpp"
#include "Consolas.hpp"
#include "Plataforma.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

#ifndef Tienda_hpp
#define Tienda_hpp

class Tienda {
public:
    Tienda();
    
    void crea_ejemplos();
    void crea_plataformas();
    
    void add_videojuego(string,string,string,double,int);
    void add_consola(string,string,string,double,string,int);
    
    void show_productos();
    void get_videojuegos();
    void get_consolas();
    
    bool search(string);
    
    void Venta(string);
    
    void agrega_stock(string, int);
    
    void agrega_plataforma(Articulo, Plataforma);
    
private:
    Articulo *Inventario[100];
    int ID;
    Plataforma *Plataformas[5];
    
};

Tienda::Tienda(){
    ID = 0;
}

void Tienda:: add_videojuego(string n, string f, string b, double p, int s){
    Inventario[ID]= new Videojuegos(n,f,b,p,s,ID);
    ID++;
}

void Tienda:: add_consola(string n, string f, string b, double p, string m, int s){
    Inventario[ID]= new Consolas(n,f,b,p,m,s,ID);
    ID++;
}

void Tienda:: show_productos(){
    for(int i=0; i<ID; i++){
        Inventario[i]->imprime_datos();
    }
}

void Tienda:: get_videojuegos(){
    for(int i=0; i<ID; i++){
        if (Inventario[i]->get_tipo()=="Videojuego"){
            Inventario[i]->imprime_datos();
        }
    }
}

void Tienda:: get_consolas(){
    for(int i=0; i<ID; i++){
        if (Inventario[i]->get_tipo()=="Consola"){
            Inventario[i]->imprime_datos();
        }
    }
}

bool Tienda :: search(string n){
    bool existe = false;
    for(int i= 0; i<ID; i++){
        if (Inventario[i]->get_name()==n){
            existe = true;
            Inventario[i]->imprime_datos();
        }
    }
    if(existe==false){
        cout<<"No hay resultados para este articulo. "<<endl;
        cout<<"\n"<<endl;
    }
    return existe;
}

void Tienda :: crea_ejemplos(){
    Inventario[ID]= new Videojuegos("Final Fantasy VII", "10/03/1996", "Remaster del juego original FFVII en PS1", 1000, 100,ID);
    ID++;
    Inventario[ID]= new Videojuegos("God of War", "10/05/2018", "Juego mas reciente de la serie de God of War", 1000, 100,ID);
    ID++;
    Inventario[ID]= new Videojuegos("Last of Us", "10/11/2013", "Primer Juego en PS4", 1000, 100,ID);
    ID++;
    Inventario[ID]= new Videojuegos("Legend of Zelda", "03/03/2017", "Juego mas reciente de la serie de Legend of Zelda", 1000, 100, ID);
    ID++;
    Inventario[ID]= new Consolas("PS5", "17/11/2020", "Consola de ultima generacion Marca Sony", 13000,"Modelo con Disc Drive", 100,ID);
    ID++;
    Inventario[ID]= new Consolas("Nintendo Switch", "03/03/2017", "Consola Hibrida de Nintendo", 7000,"Hibrido Orignal V1.1", 100,ID);
    ID++;
    
}

void Tienda:: crea_plataformas(){
    int cont = 0;
    Plataformas[cont]= new Plataforma("Switch");
    cont++;
    Plataformas[cont]= new Plataforma("Playstation 4");
    cont++;
    Plataformas[cont]= new Plataforma("Playstation 5");
    cont++;
    Plataformas[cont]= new Plataforma("Xbox One");
    cont++;
    Plataformas[cont]= new Plataforma("Xbox Series X/S");
    cont++;
}

void Tienda::Venta(string n){
    cout<<"Gracias por su compra!"<<endl;
    cout<<"\n"<<endl;
    for(int i= 0; i<ID; i++){
        if (Inventario[i]->get_name()==n){
            Inventario[i]->agregar_stock(-1);
        }
}
}

void Tienda::agrega_stock(string n, int s){
    for(int i= 0; i<ID; i++){
        if (Inventario[i]->get_name()==n){
            Inventario[i]->agregar_stock(s);
        }
}
}

void agrega_plataforma(Videojuegos *v, Plataforma pl){
    string n = v->get_name();
    string f = v->get_releaseD();
    string b = v->get_bio();
    double p = v->get_price();
    int i = v->get_ID();
    int s = v->get_stock();
    Videojuegos v2 (n,f,b,p,i,s);
    v2.Agregar_Plataforma(pl);
    *v = v2;
}
#endif /* Tienda_hpp */
