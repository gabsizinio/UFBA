#include <iostream>
#include <stdlib.h>

using namespace std;


int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        num += catalan(i) * catalan(n - i - 1);
    }
    return num;
}

int main(){
    int n, x, pos, res = 0;
    cin >> n;
    cin >> x;
    int vet[n];
    for(int i = 0; i < n; i++){
        vet[i] = catalan(i);
    }
    for(int k = 0;k < n; k++){
        if(vet[k] == x){
            res = 1;
            pos = k + 1;
        }
    }
    if(res == 1){
    cout << x << " esta na posicao " << pos;
    }else{
        cout << x << " nao existe" << endl;
    }
}