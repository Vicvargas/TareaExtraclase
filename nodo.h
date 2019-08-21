
#ifndef TAREAEXTRACLASEI_NODO_H
#define TAREAEXTRACLASEI_NODO_H

#include <iostream>

using namespace std;

class Nodo {

public:

    Nodo *next;
    int data;
    int index;

    int Key;
    Nodo * Left;
    Nodo * Right;
    Nodo * Parent;

    Nodo();
    Nodo(int);
    void print();

    Nodo * getNext();

};



#endif //TAREAEXTRACLASEI_NODO_H
