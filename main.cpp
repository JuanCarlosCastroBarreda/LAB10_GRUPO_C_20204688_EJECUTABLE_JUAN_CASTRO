#include <iostream>
#include <string>
#include <time.h>
#include "lista.h"

using namespace std;
 
int main(){
    Lista<int> lista_1;
    int n,tam,pos;
    
    cout<<"Ingresa tamanio de la lista: "<<endl;
	cin>>tam;
	lista_1.Elementos(tam);
    lista_1.Imprimir();
	
    cout<<"\nIngrese el elemente que desea aumentar al comienzo de la lista: "<<endl;
	cin>>n;
	lista_1.Inicio(n);
	lista_1.Imprimir();
	
    cout<<"\nIngrese el elemente que desea aumentar al final de la lista: "<<endl;
	cin>>n;
	lista_1.Fin(n);
	lista_1.Imprimir();
    
    cout<<"\nEliminando el ultimo elemento de la lista: "<<endl;
    lista_1.Eliminar(tam+2);
    lista_1.Imprimir();

    cout<<"\nEliminando el primer elemento de la lista: "<<endl;
    lista_1.Eliminar(1);
    lista_1.Imprimir();    

    cout<<"\nIngrese la posicion del elemento que desea eliminar: "<<endl;
	cin>>pos;
	lista_1.Eliminar(pos);
	lista_1.Imprimir();

    cout<<"\nLista ordenada ascendentemente: "<<endl;
	lista_1.Ascendente();
	lista_1.Imprimir();
			
	cout<<"\nLista ordenada descendentemente: "<<endl;
	lista_1.Descendente();
	lista_1.Imprimir();
	
	
    return 0;
}