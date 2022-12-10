#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int a1, a2, a3, aux;
    cin >> a1;
    cin >> a2;
    cin >> a3;
    if(a1 + a2 + a3 == 180){
        aux = 1;
    }else{
        aux = 0;
    }
    if(aux == 1){
        if(a1 == 90 || a2 == 90 || a3 == 90){
            cout << "Triangulo Retangulo!" << endl;
        }else if(a1 < 90 && a2 < 90 && a3 < 90){
            cout << "Triangulo Acutangulo!" << endl;
        }else if(a1 > 90 || a2 > 90 || a3 > 90){
            cout << "Triangulo Obtusangulo!" << endl;
        }
}else{
    cout << "Nao eh triangulo!" << endl;
}

    return 0;
}