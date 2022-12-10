#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int tam;
    cout.precision(2);
    cout.setf(ios::fixed);
    float s = 0, v = 0; 
    string ind;
    cin >> tam;
    cin >> ind;
    float mat[tam][tam];
    for(int i = 0; i < tam; i++){
        for(int k = 0; k < tam; k++){
            cin >> mat[i][k];
            if(k > i){
                s += mat[i][k];
                v++;
            }
        }
    }
    if(ind == "S"){
        cout << s << endl;
    }else{
        cout << s / v << endl;
    }
    
}