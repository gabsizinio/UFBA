#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int n, s, hom = 0, mul = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == 1){
            hom++;
        }
        if(s == 2){
            mul++;
        }
    }
    cout << hom << endl;
    cout << mul << endl;

    return 0;
}