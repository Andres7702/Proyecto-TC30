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

//Menu principal de el programa.
void menu(){
    cout<<"Bienvenido! Selecciona una opción"<<endl;
    cout<<"1. Cliente "<<endl;
    cout<<"2. Empleado "<<endl;
    cout<<"3. Salir"<<endl;
}

//Menu de opciones que tiene el cliente.
void menu_cliente(){
    cout<<"1. Search "<<endl;
    cout<<"2. Productos Disponibles"<<endl;
}

//Menu de opciones que obtiene el cliente al seleccionar "Search" (opcion 2 de menu_cliente)
void menu_cliente_search(){
    cout<<"Deseas buscar por nombre o por categoria? "<<endl;
    cout<<"1. Nombre"<<endl;
    cout<<"2. Categoria"<<endl;
}

//Menu de opciones que obtiene el cliente al seleccionar la opcion "Categoria" (opcion 2 de menu_cliente_search)
void menu_cliente_searchCategoria(){
    cout<<"Categorias: "<<endl;
    cout<<"1. Videojuegos"<<endl;
    cout<<"2. Consolas"<<endl;
}

//Menu de opciones que tiene el empleado.
void menu_empleado(){
    cout<<"1. Agregar Videojuego "<<endl;
    cout<<"2. Agregar Consola "<<endl;
    cout<<"3. Agregar stock a un Articulo"<<endl;
    cout<<"4. Agregar plataforma a un videojuego"<<endl;
}

//Menu que se despliega automaticamente cuando estas viendo mas de un articulo disponible en el inventario.
void menu_compra(){
    cout<<"Desea comprar alguno de los articulos? "<<endl;
    cout<<"1. Si "<<endl;
    cout<<"2. No "<<endl;
}

//Menu que se despliega cuando estas viendo un articulo especifico del inventario
void menu_compra_search(){
    cout<<"Desea comprar este articulo? "<<endl;
    cout<<"1. Si "<<endl;
    cout<<"2. No "<<endl;
}

int main() {
    //Creamos nuestra tienda y crea algunos de los articulos del inventario
    Tienda Gameplanet;
    Gameplanet.crea_ejemplos();
    
    bool continuar = true;
        
    //Un ciclo do while para que el programa siempre este corriendo hasta que el usuario
    //diga que quiere salir. (Seleccionar opcion 3 para que continuar sea igual a false)
        do{
            //Definimos todas nuestras variables
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
            //Mandamos a llamar el menu principal solo se puede responder con numeros int
            //En todos los menus se contesta con numeros. Solo que el menu diga que escribas un nombre o oracion.
            menu();
            cin>>opcion;
            cout<<"\n"<<endl;
            //Si selecciono 1 llamamos al menu de cliente
            if(opcion == 1){
                menu_cliente();
                cin>>opcion;
                cout<<"\n"<<endl;
                //Si selecciono 1 en menu de cliente llamamos al menu de busqueda.
                if(opcion == 1){
                    menu_cliente_search();
                    cin>>opcion;
                    cout<<"\n"<<endl;
                    if(opcion == 1){
                        //Si selecciono 1 en menu de busqueda el usuario quiere buscar por nombre.
                        //Se le pide que escriba el nombre del producto
                        //Si el nombre tecleado no es exactamente igual al nombre en el inventario
                        //el programa no funcionara y te regresara al inicio
                        cout<<"Como se llama el producto que estas buscando?"<<endl;
                        getline(cin, nombre_search);
                        getline(cin, nombre_search);
                        cout<<"\n"<<endl;
                        //Verificamos que el articulo exista. SI existe desplegamos su informacion
                        //Y le damos la opcion de compra
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
                    //Si selecciono 2 en menu de busqueda el usuario quiere buscar por categora.
                    else if(opcion == 2){
                        //Llamamos al menu de categoria en donde se despligan las dos categoras
                        menu_cliente_searchCategoria();
                        cin>>opcion;
                        cout<<"\n"<<endl;
                        if(opcion == 1){
                            //Si escogio 1 quiere buscar videojuegos
                            //Se despliegan todos los videojuegos disponibles
                            Gameplanet.get_videojuegos();
                            //Se le pregunta al usuario si quiere comprar alguno de los videojuegos
                            menu_compra();
                            cin>>opcion;
                            cout<<"\n"<<endl;
                            //Si escogue que si le preguntamos cual
                            //Tiene que escribir el nombre de manera correcta o no funcionara
                            if (opcion == 1){
                                cout<<"Cual? Porfavor escribe el nombre sin faltas de ortografia."<<endl;
                                getline(cin,nombre_videojuego);
                                getline(cin,nombre_videojuego);
                                cout<<"\n"<<endl;
                                //Verificamos que exista, se despliegan sus datos  y se le pregunta otra ves si lo quiere comprar.
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
                            //Si escogio 2 quiere buscar consolas
                            //Se despliegan todos los consolas disponibles
                            Gameplanet.get_consolas();
                            //Se le pregunta al usuario si quiere comprar alguno de los videojuego
                            menu_compra();
                            cin>>opcion;
                            cout<<"\n"<<endl;
                            //Si escogue que si le preguntamos cual
                            //Tiene que escribir el nombre de manera correcta o no funcionara
                            if (opcion == 1){
                                cout<<"Cual? Porfavor escribe el nombre sin faltas de ortografia."<<endl;
                                getline(cin,nombre_consola);
                                getline(cin,nombre_consola);
                                cout<<"\n"<<endl;
                                //Verificamos que exista, se despliegan sus datos  y se le pregunta otra ves si lo quiere comprar.
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
                //Si escoge que 2 en menu_cliente se despligan todos los articulos que existen
                else if (opcion == 2){
                    Gameplanet.show_productos();
                    //Se le pregunta si quiere comprar alguno
                    menu_compra();
                    cin>>opcion;
                    cout<<"\n"<<endl;
                    //Si escoge si le preguntamos cual y lo tiene que escribir
                    //Tiene que escribirlo de manera correcta o no funcionara
                    if (opcion == 1){
                        cout<<"Cual? Porfavor escribe el nombre sin faltas de ortografia."<<endl;
                        cout<<"\n"<<endl;
                        getline(cin,nombre_producto);
                        getline(cin,nombre_producto);
                        //Se verifica que exista, se despliegan sus datos y se le pregunta de nuevo si lo quiere comprar
                        bool existe = Gameplanet.search(nombre_producto);
                        if(existe == true){
                            menu_compra_search();
                            cin>>opcion;
                            cout<<"\n"<<endl;
                            if (opcion == 1){
                                Gameplanet.Venta(nombre_producto);
                            }
                            else if(opcion == 2){}
                            else {cout<<"Esa opcion no existe "<<endl;}
                        }
                    }
                    else if (opcion == 2){}
                    else{ cout<<"Esa opcion no existe."<<endl;}
                }
                else{
                    cout<<"Esa opcion no existe"<<endl;
                }
            }
            else if(opcion == 2){
                //Si escoge 2 en el menu principal se despliega el menu de empleado
                menu_empleado();
                cin>>opcion;
                //Si escoge 1 en menu de empleado es por que quiere agregar un videojuego.
                //Se le preguntan todos los datos y se agrega al inventario
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
                    cout<<"En cuantas consolas esta disponible? "<<endl;
                    cout<<"\n"<<endl;
                    int c;
                    cin>>c;
                    cout<<"\n"<<endl;
                    Gameplanet.print_plataformas();
                    cout<<"\n"<<endl;
                    for(int i=0; i<c; i++){
                        int k;
                        cout<<"Escribe el numero de la plataforma que deseas agregar. "<<endl;
                        cout<<"\n"<<endl;
                        cin>>k;
                        if(k>=0 & k<=4){
                            Gameplanet.agrega_plataforma(nombre_videojuego, k);
                        }
                        else{
                            cout<<"Esa Plataforma no existe"<<endl;
                            cout<<"\n"<<endl;
                        }
                    }
                }
                else if(opcion == 2){
                    //Si escoge 2 en menu de empleado es por que quiere agregar una consola.
                    //Se le preguntan todos los datos y se agrega al inventario
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
                    //Si escoge 3 en menu de empleado es por que quiere agregar stock a un videojuego
                    //Se despliegan los videojuegos, se pide que escriban el nombre del que quieren
                    //y se pide que escriban cuantos quieren agregar
                    int s;
                    cout<<"\n"<<endl;
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
                else if (opcion == 4){
                    //Si escoge 4 en menu de empleados es porque quiere agregar una plataforma a un videojuego.
                    //Se despliegan todos los productos.
                    //Se le pide que escriba el nombre del videojuego de manera correcta.
                    //Se le pregunta cuantas plataformas desean agregar.
                    //se despliegan las plataformas disponibles y se le pide que escriba el numero de la que desea
                    //agregar
                    cout<<"\n"<<endl;
                    Gameplanet.show_productos();
                    cout<<"Nombre de Videojuego: "<<endl;
                    getline(cin,nombre_videojuego);
                    getline(cin,nombre_videojuego);
                    cout<<"\n"<<endl;
                    bool existe = Gameplanet.search(nombre_videojuego);
                    if (existe == true){
                        cout<<"Cuantas plataformas desea agregar? "<<endl;
                        cout<<"\n"<<endl;
                        int c;
                        cin>>c;
                        cout<<"\n"<<endl;
                        Gameplanet.print_plataformas();
                        cout<<"\n"<<endl;
                        for(int i=0; i<c; i++){
                            int k;
                            cout<<"Escribe el numero de plataforma que deseas agregar. "<<endl;
                            cout<<"\n"<<endl;
                            cin>>k;
                            if(k>=0 & k<=4){
                                Gameplanet.agrega_plataforma(nombre_videojuego, k);
                                cout<<"\n"<<endl;
                                cout<<"Agregado"<<endl;
                                cout<<"\n"<<endl;
                            }
                            else{
                                cout<<"Esa Plataforma no existe"<<endl;
                                cout<<"\n"<<endl;
                            }
                        }
                    }
                }
                else{
                    cout<<"Esa opcion no es valida"<<endl;
                }
            }
            else if(opcion == 3){
                cout<<"Gracias por su visita! "<<endl;
                continuar = false;
            }
            else{
                cout<<"Esa opcion no es valida"<<endl;
                cout<<"\n"<<endl;
            }
        }while(continuar==true);
    }

