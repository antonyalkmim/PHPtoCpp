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
    vector<string> keys = {"if","echo","$_REQUEST","$_POST","$_GET"};
    return  find(keys.begin(), keys.end(), token) != keys.end();
}

bool transpiler::isVariable(string token) {
    regex variable("\\$(_|[a-zA-Z])+[a-zA-Z0-9]+");
    return regex_match(token, variable);
}









