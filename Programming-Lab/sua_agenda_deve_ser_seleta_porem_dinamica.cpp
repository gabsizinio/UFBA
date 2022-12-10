#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Agenda{
    char nome[15];
    char telefone[11];
}agenda;


int main(){
    int x, y, i, k;
    cin >> x;
    agenda* lista = (agenda*) malloc(sizeof(agenda) * x);
    for(i = 0; i < x; i++){
        cin >> lista[i].nome >> lista[i].telefone;
    }
    cin >> y;
    lista = (agenda*) realloc(lista, (x + y) * sizeof(agenda));
    for(k = x; k < x + y; k++){
        cin >> lista[k].nome >> lista[k].telefone;
    }
    cout << "inicial:" << endl;
    for(int l = 0; l < x; l++){
        cout << lista[l].nome << " " << lista[l].telefone << endl;
    }
    cout << "final:" << endl;
    for(int j = 0; j < x+y; j++){
        cout << lista[j].nome << " " << lista[j].telefone << endl;
    }
    return 0;
}
