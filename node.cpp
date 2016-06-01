//
// Created by Antony Alkmim on 06/03/16.
//

#include <iostream>
#include "node.h"

/**
 * Cria um novo node e retorna o endereco de memoria dele
 */
template <class T>
Node<T> *Node<T>::createNode(T value) {

    //cria um ponteiro para node
    Node<T> *p;
    p = new Node<T>;

    //caso nao conseguir criar um novo node retorna null
    if(!p){
        return p;
    }

    p->value = value; //armazena o valor do elemento
    p->next = NULL; //novo node nao possui proximo node

    return p; //retorna o novo node criado
}


/**
 * Deleta e retorna o valor do elemento armazenado no node passado por parametro
 */
template <class T>
T Node<T>::deleteNode(Node<T> *node) {
    T val = node->value; //armazena o valor do elemento do node
    delete node; //remove o node da memoria
    return val; //retorna o valor que estava armazenado
}