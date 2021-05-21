//
//  main.cpp
//  Proyecto Tienda Videojuegos
//
//  Created by Andrés Acevedo on 19/05/21.
//

//Al proyecto aun le falta muchas cosas. Este avance solo es para demostrar que hay relaciones
//de herencia, que sus metodos de acceso funcionan correctamente al igual que su contructor.
//***La clase videojuego tiene una propiedad llamada "plataforma" que aun no he podido hacer que funcione

#include <iostream>
using namespace std;

#include "Articulo.hpp"
#include "Videojuegos.hpp"
#include "Consolas.hpp"
#include "Inventario.hpp"
#include <string>

int main() {
    string n,f,b,m;
    double p;
    
    cout << "Nombre de Videojuego: " << endl;
    cin >> n;
    cout <<"fecha de lanzamiento: "<<endl;
    cin>> f;
    cout <<"informacion del videojuego: "<<endl;
    cin>>  b;
    cout <<"precio: "<<endl;
    cin >>  p;
    
    Videojuegos juego(n,f,b,p);
    cout << "nombre: "<< juego.get_name() <<endl;
    cout << "Fehca de lanzamiento: " <<juego.get_releaseD() << endl;
    cout <<"Informacion: "<< juego.get_bio() << endl;
    cout << "Precio: "<<juego.get_price() << endl;
    
    cout << "Nombre de consola: " << endl;
    cin >> n;
    cout <<"fecha de lanzamiento: "<<endl;
    cin >>  f;
    cout <<"informacion del consola: "<<endl;
    cin >>  b;
    cout <<"precio: "<<endl;
    cin >>  p;
    cout << "Modelo: "<< endl;
    cin >>  m;
    
    Consolas consola(n,f,b,p,m);
    cout << "nombre: "<<consola.get_name() <<endl;
    cout << "Fehca de lanzamiento: "<< consola.get_releaseD() << endl;
    cout <<"Informacion: "<< consola.get_bio() << endl;
    cout << "Precio: "<< consola.get_price() << endl;
    cout << "Modelo: "<< consola.get_modelo() <<endl;
    
}
