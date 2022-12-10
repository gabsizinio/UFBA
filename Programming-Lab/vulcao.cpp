#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int t, p, aux = 0;
    cin >> t;
    for(;;){
        cin >> p;
        if(p > t){
            aux++;
        }
        if(p == 0){
            break;
        }
    }
    if(aux > 0){
        cout << "ALARME" << endl; 
    }else{
        cout << "O Havai pode dormir tranquilo" << endl;
    }

    return 0;
}