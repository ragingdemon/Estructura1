#include "object.h"
#include "tdalist.h"
#include "dllnode.h"
#include "slinkedlist.h"
// Para tener la definición del NULL sin declarar más identificadores
// innecesarios
#include <stddef.h>
#include <iostream>
// Constructor por defecto de SLinkedList
SLinkedList::SLinkedList(){
    head = NULL;
}
// Super Destructor de SLinkedList, nótese que llamará al destructor
// de la clase DLLNode, que liberará todos los nodos siguientes...
SLinkedList::~SLinkedList(){
    if (head)
        delete head;
}
/*
* Inserción en la lista
* En esta operación se consideran cuatro casos generales de inserción:
* (A) La Lista está Vacía
* (B) Se desea Insertar antes de head (pos = 0)
* (C) Se desea Insertar en Medio de la Lista
* (D) Se desea Insertar al Final (pos = size)
*/
bool SLinkedList::insert(Object* data, int pos) {
    // Si se desa meter en una posición inválida
    if (pos < 0 || pos > size)
        return false; // Fracaso en esta Operación

    // Creación del Nodo que insertaremos en la lista
    DLLNode* neo = new DLLNode(data);

    if (!head) // La lista está vacía
        head = neo;
    else { // La Lista tiene elementos
        if (pos == 0){ // Desea insertar al principio de la lista
            // Enlace de neo a la lista
            neo->setNext(head);
            // Actualizar la cabeza
            head = neo;
        }else if (pos > 0 && pos < size){ // Desea Insertar en medio
            DLLNode* tmp = head;
            // Recorrer hasta la posición anterior a la que deseamos insertar
            for (int i=1; i<pos; i++)
                tmp = tmp->getNext();
            // Enlazar el Nodo neo
            neo->setNext(tmp->getNext());
            tmp->setNext(neo);
        }else { // Desea insertar al final
            DLLNode* tmp = head;
            // Recorrer la Lista hasta el final
            for (int i=1; i<pos; i++)
                tmp = tmp->getNext();
            // Enlazar el Nodo neo
            tmp->setNext(neo);
        }
    }
    // Incremento del tamaño
    size++;
    // Éxito en la operación
    return true;
}
/*
* Búsqueda del índice (posición) de un objeto
* Para que esta operación tenga éxito es necesario que los objetos que sean
* insertados en la lista tengan bien definido el método equals, pues es este
* método el que determinará la igualdad de un objeto con otro.
*/
int SLinkedList::indexOf(Object* other)const {
    DLLNode* tmp = head;
    for (int i=0; i < size; i++){
        // Compara cada uno de los elementos con el parámetro
        if (tmp->getData()->equals(other))
            return i;
        tmp = tmp->getNext();
    }
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posición válida
Object* SLinkedList::get(unsigned index)const {
    if (index < 0 || index >= size)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < index; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}
/*
* Borra un elemento de la lista, dada la posición del mismo. Se consideran
* tres casos:
* (A) El Elemento es la Cabeza
* (B) El Elemento es el Último
* (C) El Elemento está en Medio
* Es importante recalcar que para borrar un elemento es necesario primero
* desenlazarlo de la lista y luego liberar su memoria, pues en caso contrario
* liberaríamos todos los elementos siguiente a este elemento.
*/
Object* SLinkedList::remove(int pos) {
    Object *tmpObj = NULL;
    // Si es una posición Inválida
    if (pos < 0 || pos >= size)
        return false; // Indicar fracaso en la operación
    DLLNode* tmp;
    if (pos == 0){ // Desea Borrar la Cabeza
        // Desenlazar
        tmp = head->getNext();
        head->setNext(NULL);
        // Liberar Memoria
        size--;
        tmpObj = head->getData();
        delete head;
        // Actualizar head
        head = tmp;
        return tmpObj;
    }else if (pos == size - 1){ // Desea Borrar el último
        // Recorrer hasta el final
        tmp = head;
        for (int i=1; i<pos; i++)
            tmp = tmp->getNext();
        // Desenlazar
        DLLNode* toErase = tmp->getNext();
        tmp->setNext(NULL);
        // Liberar Memoria
        size--;
        tmpObj = toErase->getData();
        delete toErase;
        return tmpObj;
    }else { // Desea Borrar de enmedio
        // Recorrer hasta el nodo anterior al que se desea borrar
        tmp = head;
        for (int i=1; i<pos; i++)
            tmp = tmp->getNext();
        // Desenlazar
        DLLNode* toErase = tmp->getNext();
        tmp->setNext(toErase->getNext());
        toErase->setNext(NULL);
        // Liberar Memoria
        size--;
        tmpObj = toErase->getData();
        delete toErase;
        return tmpObj;
    }
    return NULL; // Indicar Éxito
}
// Retorna el anterior a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int SLinkedList::prev(int pos) const {
    return pos - 1;
}
// Retorna el siguiente a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int SLinkedList::next(int pos) const {
    return pos + 1;
}
// Elimina todos los elementos de la lista, coloca size en cero, y la cabeza
// en NULL, o sea que hace un poco más que el destructor.
void SLinkedList::clear() {
    if (head)
    {
        DLLNode* tmp = NULL;
        for (int i = 0; i < size; ++i) {
            if (head) {
                tmp = head->getNext();
                // Liberar Memoria
                delete head->getData();
                delete head;
                // Actualizar head
                head = tmp;
            }
        }
    }
    size = 0;
}
// Retorna el primer elemento de la lista, si es que hay alguno
Object* SLinkedList::first()const {
    if (head)
        return head->getData();
    return NULL;
}
// Retorna el último elemento de la lista, si es que hay alguno
Object* SLinkedList::last()const {
    if (!head)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < size - 1; i++)
    {
        tmp = tmp->getNext();
        //std::cout<<"index "<<i<<'='<<tmp->getData()->toString()<<std::endl;
    }
    return tmp->getData();
}
// Imprime cada uno de los elementos que hay en la lista, llamando al método
// print de cada nodo.
void SLinkedList::print()const {
    DLLNode* tmp = head;
    for (int i=0; i < size; i++){
        tmp->print();
        tmp = tmp->getNext();
    }
}
// Retorna si la lista está llena, como nunca es así, retorna false siempre.
bool SLinkedList::isFull()const {
    return false;
}
