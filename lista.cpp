//
// Created by victoria on 20/8/19.
//

#include "lista.h"
using namespace std;

// Constructor por defecto

Lista::Lista()
{

    m_num_nodes = 0;
    m_head = NULL;


}

// Insertar al inicio

void Lista::add_head(int data_)
{
    Nodo *new_node = new Nodo(data_);
    Nodo *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

void delete_position(int pos)
{
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
}



void Lista::delete_head() {
    if(m_head == NULL){
        cout<< "La lista está vacía";
    }
    else{
        Nodo* temp = m_head;
        m_head = m_head -> getNext();
        delete temp;

        Nodo *aux = m_head;

    }


}




// Imprimir la Lista

void Lista::print()
{
    Nodo *temp = m_head ;
    if (!m_head){
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

Lista::~Lista() {

}

