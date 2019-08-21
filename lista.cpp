
#include "lista.h"
using namespace std;


Lista::Lista()
{

    m_num_nodes = 0;
    m_head = NULL;


}


void Lista::add_head(int data_)
/**
 * Método para agregar elemento al inicio
 * @param data_
 */
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





void Lista::delete_head()
/**
 * Método para eliminar el primer elemento
 */
{
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



void Lista::print()
/**
 * Método para imprimir la lista
 */
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

