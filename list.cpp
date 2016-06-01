//
// Created by Antony Alkmim on 13/03/16.
//

#include "list.h"

/**
 * Inicializa lista
 */
template <class T>
List<T>::List() {
    this->head = this->tail = NULL;
}

/**
 * Verifica se a lista esta vazia
 */
template <class T>
bool List<T>::isEmpty() {
    return (head==NULL);
}

/**
 * Insere elementos no final da lista
 */
template <class T>
bool List<T>::insert(T value) {

    Node<T> *elem = Node<T>::createNode(value);

    //verifica se conseguiu alocar novo node na memoria
    if(!elem) return false;

    //se lista estiver vazia
    if(!this->head){
        //insere novo elemento no head
        this->head = elem;

        // como e circular, o proximo elemento de head é ele mesmo
        this->head->next = this->head;

        //como existe apenas um elemento, head e tail apontam para o mesmo
        this->tail = this->head;

        //informa que inseriu com sucesso
        return true;
    }


    //insere sempre no tail(final)
    elem->next = this->head; //o proximo elemento depois do elemento criado sempre sera o head
    this->tail->next = elem; //proximo elemento depois de tail sera novo elemento criado
    this->tail = elem; //tail passa a apontar para novo elemento

    //informa que inseriu com sucesso
    return false;
}


template <class T>
bool List<T>::insert(vector<T> values) {
    for(T i : values)
        this->insert(i);
}


/**
 * Removera o node que conter value e retornada em (int *x)
 */
template <class T>
bool List<T>::remove(T value, T *x) {

    Node<T> *iterator;

    //verifica se lista esta vazia
    if(this->isEmpty()) return false;

    //iterator sempre apontara para o elemento aterior ao que estamos avaliando
    iterator = tail;

    do{
        if(iterator->next->value == value){

            //1. caso for o primeiro elemento da lista
            if(iterator->next == this->head) {

                //caso houver apenas um elemento
                if (this->head == this->tail) {
                    this->head = NULL;
                    this->tail = NULL;
                } else {
                    this->head = this->head->next; //passa a apontar para o proximo
                    this->tail->next = this->head; //atualiza o proximo do tail
                }

                //retorna o elemento encontrado e o remove da lista
                *x = Node<T>::deleteNode(iterator->next);
                return true;
            }

            //2. caso for o ultimo elemento da lista
            if(iterator->next == this->tail){

                //retorna o elemento encontrado
                *x = Node<T>::deleteNode(this->tail);

                //tail passa a apontar para o node anterior a ele
                this->tail = iterator;
                this->tail->next = this->head;

                //informa que removeu com sucesso
                return true;
            }

            Node<T> *aux = iterator->next; //salvar temporariamente o node a ser removido
            iterator->next = iterator->next->next;

            //retorna o elemento encontrado e o remove da lista
            *x = Node<T>::deleteNode(aux);
            return true;
        }

        iterator = iterator->next; //passa para o proximo elemento

    }while(iterator->next != this->head);

    //informa que nao encontrou o elemento
    return false;
}
