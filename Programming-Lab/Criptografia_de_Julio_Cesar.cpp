#include <iostream>

using namespace std;

int main(){
    int k, aux, aux2, v = 0, tam = 0;
    string pal;
    string alf = "abcdefghijklmnopqrstuvxwyz";
    cin >> k >> pal;
    while(pal[tam] != '\0'){
        tam++;
    }
    aux = 26 - k;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < 26; j++){
            if(pal[i] == alf[j]){
                if(j >= aux){
                    aux2 = (j + k) - 26; 
                    pal[i] = alf[aux2];
                    break;
                }else{  
                    pal[i] = alf[j + k];
                    break;
                }
            }
        }
    }
    cout << pal;
    /*
        for(int i = 0; i < tam; i++){
      cout << pal[i] - 'a' << endl;
      pal[i] = 'a' + (pal[i] - 'a' + k) % 26;

    }
    */

    return 0;

}