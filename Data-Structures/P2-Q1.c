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

Lista* selectionSort(Lista *v, int n, int val){
    int i, j, menor, troca;
    Lista *res = cria_lista();
    //int aux = 0;
    for(i = 0; i < val; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v->dados[j] < v->dados[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v->dados[i];
            v->dados[i] = v->dados[menor];
            v->dados[menor] = troca;
        }
        /*
        if(aux < val - 1){
            for(int k = 0; k < n; k++){
                printf("%d ", v[k]);
            }
            printf("\n");
            aux++;
        }
        */
    }
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
    v = selectionSort(v, x - 1, y);
    for(int j = 0; j < x - 1; j++){
        printf("%d ", v->dados[j]);
    }
    libera_lista(v);
    return 0;
}