#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    string pal;
    int cont = 0;
    getline(cin, pal);
    while(pal[cont] != NULL){
        if(pal[cont] > 90 && pal[cont] != 32){
            pal[cont] = pal[cont] - 32;
        }
        cont++;
    }
    cout << pal << endl;

}