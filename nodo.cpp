//
// Created by victoria on 20/8/19.
//

#include "nodo.h"

Nodo::Nodo()
{;
    next = NULL;
    index = 0;
    data = NULL;
}

Nodo* Nodo::getNext() {return next;}

Nodo::Nodo(int data_)
{
    data = data_;
    next = NULL;
}
// Imprimir un Nodo

void Nodo::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << data << "-> ";
}
