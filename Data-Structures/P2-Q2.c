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

Lista* insertionSort(Lista *v, int n, int val){
    int i, j, aux;
    Lista *res = cria_lista();
    //int aux2 = 1;
    for(i = 1; i < val; i++){
        aux = v->dados[i];
        for(j = i; (j > 0) && (aux < v->dados[j - 1]); j--){
            v->dados[j] = v->dados[j - 1];
        }
        v->dados[j] = aux;
    }
    for(int ko = 0; ko < val; ko++){
        insere_lista_final(res, v->dados[ko]);
    }
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
    v = insertionSort(v, x - 1, y);
    for(int j = 0; j < y; j++){
        printf("%d ", v->dados[j]);
    }
    libera_lista(v);
    return 0;
}