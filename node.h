#ifndef NODE_H
#define NODE_H

template <class T>
class Node {

public:
    T value; //valor do elemento
    Node<T> *next; //valor do proximo elemento da cadeia

public:
    //cria um novo node e retorna o endereco de memoria dele
    static Node<T> *createNode(T value);
    //remove e retorna o valor do elemento do node do endereco de memoria informado
    static T deleteNode(Node<T> *node);
};

#endif // NODE_H