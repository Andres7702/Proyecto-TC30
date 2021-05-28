//Mi proyecto es de una tienda de videojuegos. En todas las preguntas aparezca un menu con opciones contestar con un numero.
//En las preguntas que pidan un nombre o algo por el estilo escribir de manera abierta.

//La tiende tiene un inventario ya creado con algunos articulos para que las funciones del programa puedan ser probadas.

#include <iostream>
using namespace std;

#include "Articulo.hpp"
#include "Videojuegos.hpp"
#include "Consolas.hpp"
#include "Plataforma.hpp"
#include "Tienda.hpp"
#include <string>

void menu(){
    cout<<"Bienvenido! Selecciona una opción"<<endl;
    cout<<"1. Cliente "<<endl;
    cout<<"2. Empleado "<<endl;
}

void menu_cliente(){
    cout<<"1. Search "<<endl;
    cout<<"2. Productos Disponibles"<<endl;
}

void menu_cliente_search(){
    cout<<"Deseas buscar por nombre o por categoria? "<<endl;
    cout<<"1. Nombre"<<endl;
    cout<<"2. Categoria"<<endl;
}

void menu_cliente_searchCategoria(){
    cout<<"Categorias: "<<endl;
    cout<<"1. Videojuegos"<<endl;
    cout<<"2. Consolas"<<endl;
}

void menu_empleado(){
    cout<<"1. Agregar Videojuego "<<endl;
    cout<<"2. Agregar Consola "<<endl;
    cout<<"3. Agregar stock a un Articulo"<<endl;
}

void menu_compra(){
    cout<<"Desea comprar alguno de los articulos? "<<endl;
    cout<<"1. Si "<<endl;
    cout<<"2. No "<<endl;
}

void menu_compra_search(){
    cout<<"Desea comprar este articulo? "<<endl;
    cout<<"1. Si "<<endl;
    cout<<"2. No "<<endl;
}

int main() {
    Tienda Gameplanet;
    Gameplanet.crea_ejemplos();
    
    bool continuar = true;
        
        do{
            int opcion;
            string nombre_search;
            string nombre_videojuego;
            string nombre_consola;
            string nombre_producto;
            string nombre_stock;
            string fecha;
            string bio;
            double precio;
            string modelo;
            int stock;
            menu();
            cin>>opcion;
            cout<<"\n"<<endl;
            if(opcion == 1){
                menu_cliente();
                cin>>opcion;
                cout<<"\n"<<endl;
                if(opcion == 1){
                    menu_cliente_search();
                    cin>>opcion;
                    cout<<"\n"<<endl;
                    if(opcion == 1){
                        cout<<"Como se llama el producto que estas buscando?"<<endl;
                        getline(cin, nombre_search);
                        getline(cin, nombre_search);
                        cout<<"\n"<<endl;
                        bool existe = Gameplanet.search(nombre_search);
                        cout<<"\n"<<endl;
                        if (existe==true){
                            menu_compra_search();
                            cin>>opcion;
                            cout<<"\n"<<endl;
                            if (opcion == 1){
                                Gameplanet.Venta(nombre_search);
                            }
                            else if(opcion == 2){}
                            else {cout<<"Esa opcion no existe "<<endl;}
                        }
                    }
                    else if(opcion == 2){
                        menu_cliente_searchCategoria();
                        cin>>opcion;
                        cout<<"\n"<<endl;
                        if(opcion == 1){
                            Gameplanet.get_videojuegos();
                            menu_compra();
                            cin>>opcion;
                            cout<<"\n"<<endl;
                            if (opcion == 1){
                                cout<<"Cual? Porfavor escribe el nombre sin faltas de ortografia."<<endl;
                                getline(cin,nombre_videojuego);
                                getline(cin,nombre_videojuego);
                                cout<<"\n"<<endl;
                                bool existe = Gameplanet.search(nombre_videojuego);
                                if(existe == true){
                                    menu_compra_search();
                                    cin>>opcion;
                                    cout<<"\n"<<endl;
                                    if (opcion == 1){
                                        Gameplanet.Venta(nombre_videojuego);
                                    }
                                    else if(opcion == 2){}
                                    else {cout<<"Esa opcion no existe "<<endl;}
                                }
                            }
                            else if (opcion == 2){}
                            else{ cout<<"Esa opcion no existe."<<endl;}
                        }
                        else if(opcion == 2){
                            Gameplanet.get_consolas();
                            menu_compra();
                            cin>>opcion;
                            cout<<"\n"<<endl;
                            if (opcion == 1){
                                cout<<"Cual? Porfavor escribe el nombre sin faltas de ortografia."<<endl;
                                getline(cin,nombre_consola);
                                getline(cin,nombre_consola);
                                cout<<"\n"<<endl;
                                bool existe = Gameplanet.search(nombre_consola);
                                if(existe == true){
                                    menu_compra_search();
                                    cin>>opcion;
                                    cout<<"\n"<<endl;
                                    if (opcion == 1){
                                        Gameplanet.Venta(nombre_consola);
                                    }
                                    else if(opcion == 2){}
                                    else {cout<<"Esa opcion no existe "<<endl;}
                            }
                            else if (opcion == 2){}
                            else{ cout<<"Esa opcion no existe."<<endl;}
                        }
                        else{
                            cout<<"Esa opcion no existe"<<endl;
                        }
                        }
                    }
                    else{
                        cout<<"Esa opcion no existe"<<endl;
                    }
                }
                else if (opcion == 2){
                    Gameplanet.show_productos();
                    menu_compra();
                    cin>>opcion;
                    cout<<"\n"<<endl;
                    if (opcion == 1){
                        cout<<"Cual? Porfavor escribe el nombre sin faltas de ortografia."<<endl;
                        cout<<"\n"<<endl;
                        getline(cin,nombre_producto);
                        getline(cin,nombre_producto);
                        Gameplanet.Venta(nombre_producto);
                    }
                    else if (opcion == 2){}
                    else{ cout<<"Esa opcion no existe."<<endl;}
                }
                else{
                    cout<<"Esa opcion no existe"<<endl;
                }
            }
            else if(opcion == 2){
                menu_empleado();
                cin>>opcion;
                if (opcion == 1){
                    cout<<"\n"<<endl;
                    cout<<"Nombre de Videojuego: "<<endl;
                    getline(cin,nombre_videojuego);
                    getline(cin,nombre_videojuego);
                    cout<<"\n"<<endl;
                    cout<<"Dia/Mes/Año"<<endl;
                    cout<<"Fecha de Lanzamiento: "<<endl;
                    getline(cin,fecha);
                    cout<<"\n"<<endl;
                    cout<<"Informacion del Videojuego: "<<endl;
                    getline(cin,bio);
                    cout<<"\n"<<endl;
                    cout<<"Precio: "<<endl;
                    cin>>precio;
                    cout<<"\n"<<endl;
                    cout<<"Cuantos hay disponibles: "<<endl;
                    cin>>stock;
                    cout<<"\n"<<endl;
                    
                    Gameplanet.add_videojuego(nombre_videojuego, fecha, bio, precio, stock);
                }
                else if(opcion == 2){
                    cout<<"\n"<<endl;
                    cout<<"Nombre de Consola: "<<endl;
                    getline(cin,nombre_consola);
                    getline(cin,nombre_consola);
                    cout<<"\n"<<endl;
                    cout<<"Dia/Mes/Año"<<endl;
                    cout<<"Fecha de Lanzamiento: "<<endl;
                    getline(cin,fecha);
                    cout<<"\n"<<endl;
                    cout<<"Informacion de Consola: "<<endl;
                    getline(cin,bio);
                    cout<<"\n"<<endl;
                    cout<<"Precio: "<<endl;
                    cin>>precio;
                    cout<<"\n"<<endl;
                    cout<<"Modelo: "<<endl;
                    getline(cin, modelo);
                    cout<<"Cuantos hay disponibles: "<<endl;
                    cin>>stock;
                    cout<<"\n"<<endl;
                    
                    Gameplanet.add_consola(nombre_consola, fecha, bio, precio, modelo, stock);
                }
                else if(opcion == 3){
                    int s;
                    Gameplanet.show_productos();
                    cout<<"Escribe el nombre del producto que deseas agregar stock. (Escribelo correctamente)"<<endl;
                    getline(cin, nombre_stock);
                    getline(cin, nombre_stock);
                    cout<<"\n"<<endl;
                    bool existe = Gameplanet.search(nombre_stock);
                    if (existe == true){
                    cout<<"Cuantos deseas agregar? (Si deseas quitar stock escribe un numero negativo)"<<endl;
                    cin>> s;
                    Gameplanet.agrega_stock(nombre_stock, s);
                    cout<<"\n"<<endl;
                    }
                }
                else{
                    cout<<"Esa opcion no es valida"<<endl;
                }
            }
        }while(continuar==true);
    }
