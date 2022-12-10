#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int tam, x, y, aux;
    cin >> tam;
    int vet[tam];
    for(int i = 0; i < tam; i++){
        cin >> vet[i];
    }
    cin >> x;
    cin >> y;
    if(tam % x == 0 && tam != x){
        for(int step = 0; step < tam; step++){
            for(int k = 0; k < (tam / x * 2) - 1; k++){
                if(k >= (tam / x) && k <= (tam / x * 2) - 1){
                    if(vet[k] > vet[k + 1]){
                        int aux = vet[k];
                        vet[k] = vet[k + 1];
                        vet[k + 1] = aux;
                    }
                }
            }
        }
    for(int lol = 0; lol < tam; lol++){
        cout << vet[lol] << " ";
    }
}else{
    cout << "Impossivel!" << endl;
}
return 0;

}