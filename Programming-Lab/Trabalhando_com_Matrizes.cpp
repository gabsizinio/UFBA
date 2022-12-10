#include <iostream>

using namespace std;

int main(){
    int mat[3][3];
    int maio = 0, col, som = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
            if(mat[i][j] > maio){
                maio = mat[i][j];
            }
        }
    }
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            if(mat[a][b] == maio){
                col = b;
            }
        }
    }
    for(int l = 0; l < 3; l++){
        for(int k = 0; k < 3; k++){
            if(k == col){
                som += mat[l][k];
            }
        }
    }
    cout << som << endl;

    return 0;
}