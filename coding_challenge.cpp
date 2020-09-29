/*-------------------------------------------------
autor: Edson Silva

Este programa recebe como argumento uma string
contendo um conjuno de parenteses abertos e fechados,
por meio de argumentos da cli ou input durante 
a runtime, retorna uma saída na linha de comando
"true" ou "false" dependendo da correta abertura 
e fechamento dos parenteses. 

O programa desconsidera outros caracteres na string
pois usa codigo ascii na comparação. Utilizo um objeto
pilha (stack) para manter registro dos parenteses abertos,
a cada abertura, um elemento é empilhado, a cada fechado
um é desempilhado, ao fim a função verifica se a pilha 
está vazia.
-------------------------------------------------*/

#include <iostream>
#include <string>
#include <stack>

// definição dos caracteres de abertura
// e fechamento de parenteses em ascii
#define opening_par 40
#define closing_par 41

using namespace std;

bool check_parentheses(string s);


int main(int argc, char const **argv){

    string input = "";
    bool is_valid = false;

    if(argc > 1){
        input = argv[1];

        is_valid = check_parentheses(input);
        if(is_valid){
            cout << "true" << endl;
        } else 
            cout << "false" << endl;
    }

    else {

        do
        {
            cout << "digite o input ou (enter) para sair: ";
            getline(cin, input);
            is_valid = check_parentheses(input);
            if(is_valid){
                cout << "true" << endl;
            } else 
                cout << "false" << endl;

        } while (static_cast<int>(input[0]) != 0);
            
    }

    
}


bool check_parentheses(string s){

    stack<int> checker;
    int layers = 0;

    if(s.size() == 0)
        return false;

    for (int i=0; i<s.size(); i++){
        //cout << "testing char: ";
        //cout << s[i] << endl;
        if(static_cast<int>(s[i]) == opening_par){
            layers++;
            checker.push(layers);
        }

        if(static_cast<int>(s[i]) == closing_par){
            if (checker.empty()){
                return false;
            }
            

            layers--;
            checker.pop();
        }

        //cout << layers << endl;
            
    }

    return checker.empty();

}