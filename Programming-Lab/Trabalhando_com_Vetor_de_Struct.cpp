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
  cin >> p[0].nome >> p[0].idade >> p[0].telefone;
  cin >> p[1].nome >> p[1].idade >> p[1].telefone;
  if(p[1].nome < p[0].nome){
    aux = p[0];
    p[0] = p[1];
    p[1] = aux;
  }
  cin >> p[2].nome >> p[2].idade >> p[2].telefone;
  if(p[2].nome < p[0].nome){
    aux = p[1];
    p[1] = p[0];
    p[0] = p[2];
    p[2] = aux;
  }else if(p[2].nome < p[1].nome){
    aux = p[1];
    p[1] = p[2];
    p[2] = aux;
  }
  for(int i = 0; i < 3; i++){
    cout << p[i].nome << " " << p[i].idade << " " << p[i].telefone << endl;
  }
  return 0;
}
