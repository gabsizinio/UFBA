#include <iostream>

using namespace std;

int calcula(int* dd, int* mm, int* aaaa){
    int idade, diaAtual = 18, mesAtual = 10, anoAtual = 2020;
    int tot1 = anoAtual * 360 + mesAtual * 30 + diaAtual;
    int tot2 = *aaaa * 360 + *mm * 30 + *dd;
    int tot = tot1 - tot2;
    idade =  tot / 360;
    *mm = tot / 30;
    *dd = tot;
    return idade;
}


int main(){
    int dia, mes, ano;

    cin >> dia >> mes >> ano;
    ano = calcula(&dia, &mes, &ano);
    cout << ano << " anos OU " << mes << " meses OU " << dia << " dias" << endl;
    return 0;
}