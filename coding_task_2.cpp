/*--------------------------------------------------
autor: Edson Silva 

Este programa recebe como argumento da cli um
conjunto de numeros separados por espaços, 
mostra estes numeros formatados como um array e 
em seguida mostra um array reorganizado segundo 
a seguinte regra:

a1 <= a2 >= a3 <= a4 >= a5....

O programa faz um tratamento da entrada e não acei-
tará nad além de int como argumento. Estes numeros
são concatenados em  array e modificados segundo a 
regra acima.
---------------------------------------------------*/

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// função que itera através do array
void sort_array(int arg[], int length);

// função que faz comparação entre os elementos
int* comparator(int arg[], int length, int curr);

// função para exibir os elementos do array
void show_array(int arg[], int length);

int main(int argc, char const **argv){

    // codigo para receber e tratar argumentos da linha de comando
    if(argc > 1){

        size_t pos;
        int arr[argc-1];
        for(int i = 1; i < argc; i++){

            string arg = argv[i];
            try{
                
                int x = stoi(arg, &pos);
                if (pos < arg.size()){
                    cerr << "Caracteres vazios apos o numero " << arg << endl;
                    return 0;
                }

                arr[i-1] = x;

            } catch(invalid_argument const &ex) {
                cerr << "Numero invalido: " << arg << '\n';
                return 0;
            } catch (out_of_range const &ex) {
                cerr << "Numero fora da faixa aceitavel: " << arg << '\n';
                return 0;
            }

        }

        cout << "seu array inicial: " ;
        show_array(arr, argc-1);
        cout << "array reorganizado: ";
        sort_array(arr, argc-1);

    }

    return 0;


}


void sort_array(int arg[], int length){

    int *aux = arg;

    if(length > 1){

        for(int i=0; i<length; i++){
        aux = comparator(aux, length, i);
        
        }
    }

    show_array(arg, length);

}


int* comparator(int arg[], int length, int curr){

    int aux;
    if(curr == (length-1)){
        return arg;
    }

    if(curr % 2 == 0){
        // modifica se elementos não forem a1 >= a2
        if(arg[curr] < arg[curr+1]){
            aux = arg[curr];
            arg[curr] = arg[curr+1];
            arg[curr+1] = aux;
        }
            
    }

    else if(curr % 2 != 0){
        // modifica se elementos não forem a2 <= a3
        if(arg[curr] > arg[curr+1]){
            aux = arg[curr];
            arg[curr] = arg[curr+1];
            arg[curr+1] = aux;
        }
    }

    return arg;

}

void show_array(int arg[], int length){
    cout << "[";
    for(int i=0; i<length; i++){
        cout << arg[i];

        if(i != length-1)
            cout << ", ";

    }
    cout << "]" <<  endl;

}