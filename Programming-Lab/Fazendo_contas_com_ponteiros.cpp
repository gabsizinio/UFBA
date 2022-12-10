#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int x, y, *p, *q;
    cin >> x;
    cin >> y;
    p = &x;
    q = &y;
    cout << (*p + *q) << endl;
    cout << (*p - *q) << endl;
    cout << (*p * *q) << endl;
    cout << (*p / *q) << endl;
    cout << (*p % *q) << endl;
   
}