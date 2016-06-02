#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "transpiler.h"

using namespace std;

int main(int argc, char* argv[]) {

    string filename = argc > 1 ? argv[1] : "index.php"; //nome do arquivo a ser convertido

    ifstream file(filename); //arquivo php a ser convertido
    ofstream outfile(filename + ".cpp"); //arquivo .cpp com codigo convertido de php para cpp

    transpiler tp;

    string token = "";
    char aux; //ler cada caractere

    vector<string> expression;

    if(file.is_open()){

        while(!file.eof()){

            file >> noskipws >> aux; //ler char por char

            /* Quando encontrar um espaco em branco identifica o final de um token */
            if(aux == ' ' || aux == '\n'){

                if(tp.isOperator(token)){ /* Operators */
                    if(!expression.empty()){
                        expression.push_back(token);

                        if(token == ")"){
                            for(string exp : expression)
                                cout << exp << " ";
                            expression.clear();
                        }
                    }
                    else{
                        cout << token << " ";
                    }
                }
                else if(tp.isKeyword(token)){ /* Keyword */
                    if(token == "<?php"){
                        cout << tp.getLibraries() << endl;
                        cout << "using namespace std;" << endl << endl;
                        cout << tp.keywords[token] << endl;
                    }
                    else if(token == "if" || !expression.empty()) {
                        expression.push_back(token);
                    }
                    else{
                        cout << tp.keywords[token] << " ";
                    }
                }
                else if(tp.isVariable(token)){ /* Variable */
                    expression.push_back(token.substr(1, token.length()));
                }
                else if(tp.isType(token)){ /* Final de expressao */
                    bool ioEXP = false;

                    //verificar se existe expressao IO
                    for(string exp : expression){
                        if(tp.isIO(exp)){
                            ioEXP = true;
                        }
                    }

                    if(ioEXP){
                        //prints: type varName;
                        cout << token.substr(2, token.length()) << " " << expression[0] << ";" << endl;

                        //prints: cin >> ...
                        cout << "cin >> " << expression[0] << ";" << endl;

                        expression.clear();
                    }else{
                        cout << token.substr(2, token.length()) << " ";
                        for(string exp : expression)
                            cout << exp << " ";

                        expression.clear();
                    }

                }
                else{
                    if(!expression.empty()){
                        expression.push_back(token);
                    }else{
                        cout << token << " ";
                    }

                }

//                cout << token << " ";
                if(aux == '\n') cout << endl;

                token.clear();
            }
            else if (aux == '"') { //string
                token.push_back(aux);

                file >> noskipws >> aux;
                token.push_back(aux);
                while (aux != '"') {
                    file >> noskipws >> aux;
                    token.push_back(aux);
                }

                if(!expression.empty()){
                    expression.push_back(token);
                }
                else{
                    cout << token << " ";
                }

                token.clear();
            }
            else {
                token.push_back(aux);
            }
        }
        file.close();
    }else{
        cout << "Erro ao tentar abrir arquivo: " << filename << endl;
    }


}