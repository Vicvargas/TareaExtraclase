
#ifndef TAREAEXTRACLASEI_LISTA_H
#define TAREAEXTRACLASEI_LISTA_H



#include <iostream>
#include <string>

#include "nodo.h"

using namespace std;



class Lista
{
public:
    Lista();
    ~Lista();


    void add_head(int);



    void print();
    void delete_head();

private:
    Nodo *m_head;
    int m_num_nodes;
};




#endif //TAREAEXTRACLASEI_LISTA_H
