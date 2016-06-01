#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class List {

public:
    Node<T> *head; //aponta para primeiro elemento da lista
    Node<T> *tail; //aponta para o final da lista
public:
    List();
    bool insert(T value);
    bool insert(vector<T> values);
    bool remove(T value, T *x);
    bool isEmpty();
};

#endif // LIST_H