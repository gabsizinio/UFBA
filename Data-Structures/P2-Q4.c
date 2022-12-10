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
    li = (Lista*) malloc(sizeof(struct lista) * 20);
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

void troca(Lista *v, int p1, int p2){
    int aux = v->dados[p1];
    v->dados[p1] = v->dados[p2];
    v->dados[p2] = aux;
}

Lista* particiona(Lista *v, int ini, int fim, int pos){
    int j, pivo, aux2 = 0;
    pivo = v->dados[pos];
    Lista *aux = cria_lista();
    for(int con = 0; con < fim + 1; con++){
        if(v->dados[con] < pivo){
            aux->dados[aux2] = v->dados[con];
            aux->qtd++;
            aux2++;
        }
    }
    aux->dados[aux2] = pivo;
    aux2++;
    for(int con2 = 0; con2 < fim + 1; con2++){
        if(v->dados[con2] > pivo){
            aux->dados[aux2] = v->dados[con2];
            aux->qtd++;
            aux2++;
        }
    }
    for(int xx = 0; xx < fim + 1; xx++){
        if(aux->dados[xx] == pivo){
            j = xx;
        }
    }
    printf("%d %d ", aux->dados[0], aux->dados[j + 1]);
    return aux;
}

void quicksort2(Lista *v, int ini, int fim){
    int i, j, x, y;
    i = ini;
    j = fim;
    x = v->dados[ini];
    //printf("%d ", x);
    while(i <= j) {
        while(v->dados[i] < x && i < fim) {
            i++;
        }
        while(v->dados[j] > x && j > ini) {
            j--;
        }
        if(i <= j) {
            y = v->dados[i];
            v->dados[i] = v->dados[j];
            v->dados[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > ini) {
        quicksort2(v, ini, j);
    }
    if(i < fim) {
        quicksort2(v, i, fim);
    }
}



int main(){
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    Lista *v = cria_lista();
    for(int i = 0; i < x - 1; i++){
        scanf("%d", &z);
        insere_lista_final(v, z);
    }
    v = particiona(v, 0, x - 2, y);
    quicksort2(v, 0, x - 2);
    for(int j = 0; j < x - 1; j++){
        printf("%d ", v->dados[j]);
    }
    libera_lista(v);
    return 0;
}