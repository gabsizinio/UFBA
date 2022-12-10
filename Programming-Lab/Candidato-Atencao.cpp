#include <iostream>
#include <cmath>

using namespace std;

void calcEsfera(float *area, float raio, float *volume){
    *area = 4 * 3.14 * pow(raio, 2);
    *volume = (4  * 3.14 * pow(raio, 3)) / 3;
}

int main(){

    float area, volume, raio;

    cin >> raio;

    calcEsfera(&area, raio, &volume);
    cout.precision(5);
    cout << area << endl;
    cout << volume << endl;

    return 0;

}
