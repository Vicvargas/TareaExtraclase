

#include "nodo.h"


Nodo::Nodo()

{;
    next = NULL;
    index = 0;
    data = NULL;
}

Nodo* Nodo::getNext()
/**
 *
 * @return el siguiente nodo
 */
{
    return next;
}


Nodo::Nodo(int data_)

{
    data = data_;
    next = NULL;
}



void Nodo::print()
{
    cout << data << " " ;
}
