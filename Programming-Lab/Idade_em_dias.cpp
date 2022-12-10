#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int x, ano, mes, dias;
    cin >> x;
    ano = x / 365;
    mes = (x % 365) / 30;
    dias = ((x % 365) % 30);
    cout << ano << " ano(s)" << endl;
    cout << mes << " mes(es)" << endl;
    cout << dias << " dia(s)" << endl;
}