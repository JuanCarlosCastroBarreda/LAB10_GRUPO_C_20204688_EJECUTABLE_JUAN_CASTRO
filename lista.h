#include <iostream>
#include <string>
#include <time.h>
#include "Nodo.h"
using namespace std;
 
template <class T>
class Lista{
    public:
        Lista();
        ~Lista();
        void Inicio(T);
        void Fin(T);
        void Eliminar(int);
        void Elementos(int);
        void Descendente();
        void Ascendente();
        void Imprimir();
    private:
        Nodo<T> *m_cabeza;
        int m_num_nodos;
};

template<typename T>
Lista<T>::Lista(){
    m_num_nodos=0;
    m_cabeza=NULL;
}
 
template<typename T>
void Lista<T>::Inicio(T dato_){
    Nodo<T> *new_nodo=new Nodo<T> (dato_);
    Nodo<T> *temp=m_cabeza;
 	if(!m_cabeza){
        m_cabeza=new_nodo;
    }
	else{
        new_nodo->next=m_cabeza;
        m_cabeza=new_nodo;
        while(temp){
            temp=temp->next;
        }
    }
    m_num_nodos++;
}

template<typename T>
void Lista<T>::Fin(T dato_){
    Nodo<T> *new_nodo=new Nodo<T>(dato_);
    Nodo<T> *temp=m_cabeza;
    if(!m_cabeza){
        m_cabeza=new_nodo;
    }
	else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_nodo;
    }
    m_num_nodos++;
}

template<typename T>
void Lista<T>::Eliminar(int pos){
    Nodo<T> *temp=m_cabeza;
    Nodo<T> *temp1=temp->next;
    if(pos<1||pos>m_num_nodos){
        cout<<"Fuera de rango"<<endl;
    }
	else if(pos==1){
        m_cabeza=temp->next;
    } 
	else{
        for(int i=2;i<=pos;i++){
            if(i==pos){
                Nodo<T> *aux_nodo=temp1;
                temp->next=temp1->next;
                delete aux_nodo;
                m_num_nodos--;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
    }
}
 
template<typename T>
void Lista<T>::Elementos(int dim){
    T n;
    for(int i=0;i<dim;i++){
        cout<<"Ingresa el elemento "<<i+1<<": ";
        cin>>n;
        Fin(n);
    }
} 
 
template<typename T>
void ordenamiento(T a[],int size){
    T temp;
    for(int i=0;i<size;i++){
        for(int j=i-1;j>=0&&a[j+1]<a[j];j--){
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
        }
    }
}
 
template<typename T>
void Lista<T>::Descendente(){
    Nodo<T> *ant=NULL;
    Nodo<T> *next=NULL;
    Nodo<T> *temp=m_cabeza;
    while(temp){
        next=temp->next;
        temp->next=ant;
        ant=temp;
        temp=next;
    }
    m_cabeza=ant;
}

template<typename T>
void Lista<T>::Ascendente(){
    T temp_dato;
    Nodo<T> *aux_nodo=m_cabeza;
    Nodo<T> *temp=aux_nodo;
    while(aux_nodo){
        temp=aux_nodo;
        while(temp->next){
            temp=temp->next;
            if(aux_nodo->dato>temp->dato){
                temp_dato=aux_nodo->dato;
                aux_nodo->dato=temp->dato;
                temp->dato=temp_dato;
            }
        }
        aux_nodo=aux_nodo->next;
    }
}

template<typename T>
void Lista<T>::Imprimir(){
    Nodo<T> *temp=m_cabeza;
    if(!m_cabeza){
        cout<<"La Lista está vacía"<<endl;
    }
	else{
        while(temp){
            temp->imprimir();
            if(!temp->next)cout<<"NULL";
                temp=temp->next;
        }
  }
  cout<<endl<<endl;
}

template<typename T>
Lista<T>::~Lista() {}
