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

    string inLine; //Cada de linha do arquivo php
    string outLine; //cada linha CPP convertida

    if(file.is_open()){

        while(getline(file, inLine)){
            cout << inLine << endl;

            /** TODO Identificar os tokens da linha atual
             *  Identificar operacao:
             *   :=> declaracao de variavel
             *   :=> aritimetica
             *   :=> condicional
             *   :=> entrada de dados (atraves de $_GET/$_POST/$_REQUEST)
             *   :=> impressao de dados
             *   :=> remover comentarios
             *
             *   TIPOS DE DADOS ESTARAO ESPECIFICADOS COM COMENTARIOS APOS A SUA DECLARACAO
             *   EX:
             *      $str = "foo"; //string
             *      $integer = 1; //int
             *      $floatVar = 1.2; //float
             *      $doubleVar = 1.123456789; //double
             */
        }

        file.close();
    }


}