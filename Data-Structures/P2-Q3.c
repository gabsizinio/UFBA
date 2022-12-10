#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct lista{
    int qtd;
    int dados[MAX];
};
typedef struct lista Lista;

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int insere_lista_final(Lista* li, int al){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == MAX){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

Lista* bubblesort(Lista *v, int n, int val){
    int i, aux, fim = n, aux2 = 0;
    Lista *res = cria_lista();
    //int continua
    do{
        for(i = 0; i < fim - 1; i++){
            if(v->dados[i] > v->dados[i + 1]){
                aux = v->dados[i];
                v->dados[i] = v->dados[i + 1];
                v->dados[i + 1] = aux;
                //continua = i;
            }
        }
        fim--;
        aux2++;
    }while(aux2 <= val - 1);
    res = v;
    return res;
}


int main(){
    int x, y, z;
    Lista *v = cria_lista();
    scanf("%d", &x);
    scanf("%d", &y);
    for(int i = 0; i < x - 1; i++){
        scanf("%d", &z);
        insere_lista_final(v, z);
    }
    v = bubblesort(v, x - 1, y);
    //insertionSort(v, x - 1, y);
    for(int j = 0; j < x - 1; j++){
        printf("%d ", v->dados[j]);
    }
    free(v);
    return 0;
}