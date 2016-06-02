//
// Created by Antony Alkmim on 18/05/16.
//

#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>
#include "transpiler.h"

using namespace std;

transpiler::transpiler() {

    //types
    types = {"//int","//float","//string","//double","//char", "//bool"};

    //LIBS
    libs = {
            "#include <iostream>",
            "#include <string>",
            "#include <cmath>",
            "#include <cstdio>",
            "#include <ctime>",
            "#include <cstdlib>"};


    //KEYWORDS
    keywords["<?php"] = "int main(){";
    keywords["?>"] = "}";
    keywords["if"] = "if";
    keywords["echo"] = "cout << ";
    keywords["$_REQUEST"] = "cin >> ";
    keywords["$_GET"] = "cin >> ";
    keywords["$_POST"] = "cin >> ";
    keywords["true"] = "true";
    keywords["false"] = "false";
}

bool transpiler::isOperator(string token) {
    vector<string> ops = {"+","-","/","%","*",
                          "*=","+=","-=", "/=",
                          ">","<","=","!",
                          "&&", "||", "==", "!=", "<=", ">=",
                          "(",")","{","}"};

    return  find(ops.begin(), ops.end(), token) != ops.end();
}

bool transpiler::isKeyword(string token) {
    return (keywords.find(token) != keywords.end());
}

bool transpiler::isVariable(string token) {
    regex variable("\\$(_|[a-zA-Z])+[a-zA-Z0-9]+");
    return regex_match(token, variable);
}

string transpiler::getLibraries() {
    string aux = "";

    for(string i : libs)
        aux.append(i).append("\n");

    return aux;
}

bool transpiler::isType(string token) {
    return  find(types.begin(), types.end(), token) != types.end();
}

bool transpiler::isIO(string token) {
    regex io("\\$(_POST|_GET|_REQUEST)\\[(\'[0-9a-zA-Z]+\')\\]");
    return regex_match(token, io);
}















