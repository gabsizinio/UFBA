#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int l1, l2, l3, l4, x, aux1 = 0, aux2 = 0;
    cin >> l1 >> l2;
    cin >> l3 >> l4;
    cin >> x;
    if((x > l1 && x <= l2) && !(x >= l3 && x < l4)){
        cout << "Primeiro intervalo!" << endl;
    }else if(x >= l3 && x < l4 && !(x > l1 && x <= l2)){
        cout << "Segundo intervalo!" << endl;
    }else if((x > l1 && x <= l2) && (x >= l3 && x < l4)){
        cout << "Ambos!" << endl;
    }else{
        cout << "Nenhum!" << endl;
    }

    return 0;
}