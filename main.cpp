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
    string line = "";
    char aux; //ler cada caractere

    if(file.is_open()){

        while(!file.eof()){

            file >> noskipws >> aux; //ler char por char

            /* Quando encontrar um espaco em branco identifica o final de um token */
            if(aux == ' ' || aux == '\n'){

                /**
                 * Avaliar a o que o token se refere
                 *  Variavel
                 *  Operador
                 *  Symbolo
                 *  Palavra Chave
                 */

                /* Operators */
                if(tp.isOperator(token)){
                    cout << " /* operador */ ";
                }

                /* Keyword */
                if(tp.isKeyword(token)){
                    cout << " /* Keyword */ ";
                }

                /* Variable */
                if(tp.isVariable(token)){
                    cout << " /* var */ ";
                }

                cout << token << " ";
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

                cout << token << " ";
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