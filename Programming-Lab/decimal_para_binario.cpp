#include <iostream>
using namespace std;

void dec2bin(int dec){
    if(dec < 2){
        printf("%d", dec);
        return;
    }else{
        dec2bin(dec/2);
    }
    printf("%d", dec % 2);
}

int main(){
    int n;
    cin >> n;
    dec2bin(n);
    cout << endl;
    return 0;
}
