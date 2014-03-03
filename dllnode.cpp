#include "dllnode.h"
#include "object.h"
#include <iostream>
using std::cout;
using std::endl;
// Definici�n de los m�todos de la clase DLLNode

// Constructor por Defecto de la Clase. Raramente Usado
DLLNode::DLLNode(){
    next = prev = NULL;
    data = NULL;
}
// Constructor especial de la Clase. Este es el m�s utilizado
DLLNode::DLLNode(Object* aData){
    next = prev = NULL;
    data = aData;
}
// Constructor especial de la Clase. Raramente Usado
DLLNode::DLLNode(Object* aData, DLLNode* aPrev, DLLNode* aNext){
    data = aData;
    next = aNext;
    prev = aPrev;
}
/*
* Destructor S�per Poderoso de la Clase                                       *
* Este destructor liberar� la memoria que est� ocupando la data a la que      *
* apunte el nodo, de la misma manera, liberar� al nodo siguiente, en el caso  *
* de que hubiera alguno. De esta manera se libera todo lo que tenga el nodo y *
* sus siguientes.                                                             *
* Este destructor es muy �til, sin embargo hay que tener cuidado al querer    *
* s�lo liberar un nodo, pues este deber� estar suelto.                        *
*/
DLLNode::~DLLNode(){
    std::cout<<"destructor de nodo"<<endl;
    next = prev = NULL;
    data = NULL;
}
// Impresi�n del Nodo, s�lo manda a imprimir el contenido de la data.
void DLLNode::print()const{
    data->print();
}
// M�todo Accesor de Next
DLLNode* DLLNode::getNext()const{
    return next;
}
// M�todo Accesor de Prev
DLLNode* DLLNode::getPrev()const{
    return prev;
}
// M�todo Mutador de Next
void DLLNode::setNext(DLLNode* aNext){
    next = aNext;
}
// M�todo Mutador de Prev
void DLLNode::setPrev(DLLNode* aPrev){
    prev = aPrev;
}
// M�todo Accesor de Data
Object* DLLNode::getData()const{
    return data;
}
// M�todo Mutador de Data
void DLLNode::setData(Object* aData){
    data = aData;
}

