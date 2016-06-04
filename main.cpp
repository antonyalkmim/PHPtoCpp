#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "transpiler.h"

using namespace std;

int main(int argc, char* argv[]) {

    //string filename = argc > 1 ? argv[1] : "index.php"; //nome do arquivo a ser convertido
    string filename = "/home/antonyalkmim/workspace/PHPtoCpp/index.php";
    ifstream file(filename); //arquivo php a ser convertido
    ofstream outfile(filename + ".cpp"); //arquivo .cpp com codigo convertido de php para cpp

    transpiler tp;

    string token = "";
    char aux; //ler cada caractere

    vector<string> expression;
//    vector<string> outExpression;

    if(file.is_open() && outfile.is_open()){

        while(!file.eof()){

            file >> noskipws >> aux; //ler char por char

            /* Quando encontrar um espaco em branco identifica o final de um token */
            if(aux == ' ' || aux == '\n' || aux == '\0'){

                if(tp.isOperator(token)){ /* Operators */
                    if(!expression.empty()){
                        expression.push_back(token);

                        if(token == ")"){
                            for(string exp : expression)
                                outfile << exp << " ";
                            expression.clear();
                        }
                    }
                    else{
                        outfile << token << " ";
                    }
                }
                else if(tp.isKeyword(token)){ /* Keyword */
                    if(token == "<?php"){
                        outfile << tp.getLibraries() << endl;
                        outfile << "using namespace std;" << endl << endl;
                        outfile << tp.keywords[token] << endl;
                    }
                    else if(token == "if" || !expression.empty()) {
                        expression.push_back(token);
                    }
                    else if(token == "echo"){
                        expression.push_back(tp.keywords[token]);
                    }
                    else{
                        outfile << tp.keywords[token] << " ";
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
                        outfile << token.substr(2, token.length()) << " " << expression[0] << ";" << endl;

                        //prints: cin >> ...
                        outfile << "cin >> " << expression[0] << ";" << endl;

                        expression.clear();
                    }else{
                        outfile << token.substr(2, token.length()) << " ";
                        for(string exp : expression)
                            outfile << exp << " ";

                        expression.clear();
                    }
                }
                else{
                    if(!expression.empty()){
                        expression.push_back(token);
                    }
                    else{
                        outfile << token << " ";
                    }

                    if(token == ";" && expression[0] == tp.keywords["echo"]){
                        for(string exp : expression)
                            outfile << exp << " ";
                        expression.clear();
                    }


                }

                if(aux == '\n')
                    outfile << endl;

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
                    outfile << token << " ";
                }

                token.clear();
            }
            else {
                token.push_back(aux);
            }
        }
        cout << "File " << filename << " was convert to PHP in " << filename << ".cpp" << endl;
        file.close();
    }else{
        cout << "Erro ao tentar abrir arquivo: " << filename << endl;
    }


}