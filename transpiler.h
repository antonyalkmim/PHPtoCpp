//
// Created by Antony Alkmim on 18/05/16.
//

#ifndef PHPTOCPP_TRANSPILER_H
#define PHPTOCPP_TRANSPILER_H

#include <iostream>
#include <map>
#include <string>
#include "list.h"

using namespace std;

class transpiler {
public:
    map<string, string> operators; // [+,-,/,*...]
    map<string, string> keywords; // if, echo
public:
    transpiler();
    bool isOperator(string token);
    bool isKeyword(string token);
    bool isVariable(string token);
};


#endif //PHPTOCPP_TRANSPILER_H
