#include <iostream>
using namespace std;
 
template <class T>
class Nodo{
    public:
        Nodo();
        Nodo(T);
        ~Nodo();
        Nodo *next;
        T dato;
        void imprimir();
};
 
template<typename T>
Nodo<T>::Nodo(){
    dato=NULL;
    next=NULL;
}
 
template<typename T>
Nodo<T>::Nodo(T dato_){
    dato=dato_;
    next=NULL;
}

template<typename T>
void Nodo<T>::imprimir(){
    cout<<dato<<"-> ";
}
 
template<typename T>
Nodo<T>::~Nodo() {}
