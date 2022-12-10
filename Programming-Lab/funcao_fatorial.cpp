#include <iostream>
using namespace std;

int fat(int x){
    if(x == 0){
        return 1;
    }
    else{
        return x * fat(x - 1);
    }
}

int main() {
    int n;

    cin >> n;
    cout << fat(n) << endl;

    return 0;
}
