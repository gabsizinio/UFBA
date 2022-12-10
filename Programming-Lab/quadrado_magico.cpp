#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int mat[3][3];
    int l1 = 0, l2 = 0, l3 = 0, c1 = 0, c2 = 0, c3 = 0, dp = 0, ds = 0;
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            cin >> mat[i][k];
            if(i == 0){
                l1 += mat[i][k];
            }
            if(i == 1){
                l2 += mat[i][k];
            }
            if(i == 2){
                l3 += mat[i][k];
            }    
            if(k == 0){
                c1 += mat[i][k];
            }
            if(k == 1){
                c2 += mat[i][k];
            }
            if(k == 2){
                c3 += mat[i][k];
            }
            if(i == k){
                dp += mat[i][k];
            }
            if(i + k == 2){
                ds += mat[i][k];
            }
        }
    }
    
    if(l1 == l2 && l2 == l3 && l3 == c1 && c1 == c2 && c2 == c3 && c3 == dp && dp == ds){
        cout << "eh um quadrado magico" << endl;
    }else{
        cout << "nao eh um quadrado magico" << endl;
    }
    
}