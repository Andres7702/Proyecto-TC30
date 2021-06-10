//
//Proyecto de Andres Acevedo Caracheo
//A01706897
//

//Clase Tienda que tiene un array de objetos tipo articulo, que a traves de polimorfismo podemos llenar con
//objetos de tipo Videojuego o Consola. Este array es nuestro inventario.
//Ademas la clase tiene funciones que nos permitiran añadir cosas al inventario o conseguir su informacion para que
//el usuario las pueda ver y decidir si quiere comprar algo.

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
    
    void agrega_plataforma(string, int);
    
    void print_plataformas();
    
private:
    Articulo *Inventario[100];
    int ID;
    Plataforma Plataformas[5];
    
};

//Constructor por Default
Tienda::Tienda(){
    ID = 0;
    Plataformas[0]= Plataforma("Switch");
    Plataformas[1]= Plataforma("PS4");
    Plataformas[2]= Plataforma("PS5");
    Plataformas[3]= Plataforma("Xbox One");
    Plataformas[4]= Plataforma("Xbox Series X/S");
}

//Esta funcion es para agregar un apuntador a un objeto tipo videojuego a nuestro inventario.
//El inventario tiene un ID que ira aumentando por cada articulo que agreguemos al inventario.
// La funcion recibe la informacion necesario para poder llamar al apuntador de videojuego y crear este objeto
//dentro del inventario por polimorifsmo

//@param string de nombre, string de fecha, string de bio, double de precio, int de stock
//@return

void Tienda:: add_videojuego(string n, string f, string b, double p, int s){
    Inventario[ID]= new Videojuegos(n,f,b,p,s,ID);
    ID++;
}
//Esta funcion es para agregar un apuntador a un objeto tipo consola a nuestro inventario.
//El inventario tiene un ID que ira aumentando por cada articulo que agreguemos al inventario.
// La funcion recibe la informacion necesario para poder llamar al apuntador de consola y crear este objeto
//dentro del inventario por polimorfismo

//@param string de nombre, string de fecha, string de bio, double de precio,string de modelo, int de stock
//@return

void Tienda:: add_consola(string n, string f, string b, double p, string m, int s){
    Inventario[ID]= new Consolas(n,f,b,p,m,s,ID);
    ID++;
}

//Esta funcion hace uso de la funcion virtual que definimos para la clase abstracta de articulo.
//Recorre el array de articulos y manda a llamar esta funcion, que dependiendo del tipo de objeto que sea,
//imprimira cosas diferentes.

//@param
//@return

void Tienda:: show_productos(){
    for(int i=0; i<ID; i++){
        Inventario[i]->imprime_datos();
    }
}

//Esta funcion hace uso de la funcion virtual que definimos para la clase abstracta de articulo.
//Recorre el array de articulos y si el objeto es de tipo videojuegos, imprime su informacion.

void Tienda:: get_videojuegos(){
    for(int i=0; i<ID; i++){
        if (Inventario[i]->get_tipo()=="Videojuego"){
            Inventario[i]->imprime_datos();
        }
    }
}

//Esta funcion hace uso de la funcion virtual que definimos para la clase abstracta de articulo.
//Recorre el array de articulos y si el objeto es de tipo consolas, imprime su informacion.

void Tienda:: get_consolas(){
    for(int i=0; i<ID; i++){
        if (Inventario[i]->get_tipo()=="Consola"){
            Inventario[i]->imprime_datos();
        }
    }
}

//Esta funcion hace uso de la funcion virtual que definimos para la clase abstracta de articulo.
//Esta funcion recibe el nombre de un articulo y si el nombre coinside con un nombre del inventario,
//imprime sus datos. Ademas, si el nombre coincide regresa un valor de true y si no regresa false.
//Esto es para que se pueda hacer validacion desde el main.

//@param string de nombre de articulo
//@return bool existe

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

//Esta funcion crea objetos desde el inicio para que el usuario ya tenga objetos creados y pueda probar todas las
//funciones desde el principio

void Tienda :: crea_ejemplos(){
    Inventario[ID]= new Videojuegos("Final Fantasy VII", "10/03/1996", "Remaster del juego original FFVII en PS1", 1000, 100,ID);
    agrega_plataforma("Final Fantasy VII", 0);
    agrega_plataforma("Final Fantasy VII", 1);
    agrega_plataforma("Final Fantasy VII", 2);
    agrega_plataforma("Final Fantasy VII", 3);
    ID++;
    Inventario[ID]= new Videojuegos("God of War", "10/05/2018", "Juego mas reciente de la serie de God of War", 1000, 100,ID);
    agrega_plataforma("God of War", 1);
    agrega_plataforma("God of War", 2);
    ID++;
    Inventario[ID]= new Videojuegos("Last of Us", "10/11/2013", "Primer Juego en PS4", 1000, 100,ID);
    agrega_plataforma("Last of Us", 1);
    agrega_plataforma("Last of Us", 2);
    ID++;
    Inventario[ID]= new Videojuegos("Legend of Zelda", "03/03/2017", "Juego mas reciente de la serie de Legend of Zelda", 1000, 100, ID);
    agrega_plataforma("Legend of Zelda", 0);
    ID++;
    Inventario[ID]= new Consolas("PS5", "17/11/2020", "Consola de ultima generacion Marca Sony", 13000,"Modelo con Disc Drive", 100,ID);
    ID++;
    Inventario[ID]= new Consolas("Nintendo Switch", "03/03/2017", "Consola Hibrida de Nintendo", 7000,"Hibrido Orignal V1.1", 100,ID);
    ID++;
    
}

//Esta funcion recibe el nombre de un articulo, si el nombre coincide con alguno del inventario, disminuye el stock
//del articulo en 1

//@param string de nombre
//@return

void Tienda::Venta(string n){
    cout<<"Gracias por su compra!"<<endl;
    cout<<"\n"<<endl;
    for(int i= 0; i<ID; i++){
        if (Inventario[i]->get_name()==n){
            Inventario[i]->agregar_stock(-1);
        }
}
}

//Esta funcion recibe el nombre de un articulo y el numero de stock que se desea agregar.
//si el nombre coincide con alguno del inventario se aumenta el numero que indico.

//@param string de  nombre, int de numero de stock a agregar
//@return

void Tienda::agrega_stock(string n, int s){
    for(int i= 0; i<ID; i++){
        if (Inventario[i]->get_name()==n){
            Inventario[i]->agregar_stock(s);
        }
    }
}

//Esta funcion es para agregar una plataforma a un objeto tipo videojuego.
//Recibe el nombre del videojuego y el numero correspondiente a la plataforma que se desea agregar.

//@param string de nombre, int de posicion de plataforma en array plataformas


void Tienda::agrega_plataforma(string n, int k){
    for(int i= 0; i<=ID; i++){
        if (Inventario[i]->get_name()==n){
            ((Videojuegos*)Inventario[i])->Agregar_Plataforma(Plataformas[k]);
        }
    }
}

//Esta funcion imprime las plataformas que se pueden agregar a un videojuego. Son las platformas de arary Plataformas
//en la clase tienda

//@param
//@return

void Tienda:: print_plataformas(){
    for(int i=0; i<5; i++){
        cout<<i<<". "<<Plataformas[i].get_name()<<endl;
    }
}
#endif /* Tienda_hpp */
