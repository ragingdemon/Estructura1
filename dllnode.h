#ifndef DLLNODE_H
#define DLLNODE_H
#include "object.h"
#include <iostream>
/*
* Esta clase sirve para representar un nodo de listas doblemente enlazadas   *
* Como lo dice el nombre de la clase:                                        *
* Doble                                                                      *
* Linked                                                                     *
* List                                                                       *
* Node                                                                       *
* Los miembros de la clase sirven para las diferentes partes del nodo        *
* [   PREV    ]             Es el puntero al nodo anterior                   *
* [   DATA    ]             Es el puntero al Objeto que contiene los datos   *
* [   NEXT    ]             Es el puntero al nodo siguiente                  *
* ----------------------------------------------------------------------------
* NOTAS:                                                                     *
* En esta implementaci�n se coloca un m�todo print, que lo �nico que har�    *
* es llamar al m�todo print de data.                                         *
* En esta implementaci�n el destructor de esta clase destruir� cualquier     *
* cosa que est� enlazada con el nodo, de la misma manera que una cadena se   *
* suelta al cortar un eslab�n.                                               *
*/

class DLLNode
{
    Object* data;
    DLLNode* prev;
    DLLNode* next;
  public:
    DLLNode();
    DLLNode(Object*);
    DLLNode(Object*, DLLNode*, DLLNode*);
    ~DLLNode();
    void print()const;
    DLLNode* getNext()const;
    DLLNode* getPrev()const;
    void setNext(DLLNode*);
    void setPrev(DLLNode*);
    Object* getData()const;
    void setData(Object*);
};

#endif
