#include <iostream>
#include <stdlib.h>

using namespace std;

 struct dado{
  string nome;
  int idade;
  string telefone;
};

int main(){
  typedef struct dado dados;
  dados p[3];
  dados aux;
  string nome;
  cin >> p[0].nome >> p[0].idade >> p[0].telefone;
  cin >> p[1].nome >> p[1].idade >> p[1].telefone;
  cin >> p[2].nome >> p[2].idade >> p[2].telefone;
  cin >> nome;
  for(int i = 0; i < 3; i++){
    if(p[i].nome == nome){
        aux = p[i];
    }
  }
    cout << aux.nome << " " << aux.idade << " " << aux.telefone << endl;

  return 0;
}
