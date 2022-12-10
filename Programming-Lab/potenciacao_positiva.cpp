#include <iostream>
using namespace std;

int pot(int base, int exp){
    if(exp == 0){
        return 1;
    }else{
        return base * pot(base, exp - 1);
    }
}

int main() {
    int x, e;

    cin >> x >> e;
    cout << pot(x,e) << endl;

    return 0;
}