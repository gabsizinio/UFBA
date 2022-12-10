#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct elemento{
    char* dados;
    struct elemento *prox;
};
typedef struct elemento elem;

struct Lista{
    elem* inicio;
};
typedef struct Lista lista;

void criaLista(lista* l){
    l->inicio = NULL;
}

void inserirLista(lista *l, char* pal){
    elem *aux = (elem*) malloc(sizeof(elem));
    aux->dados = (char*) malloc(strlen(pal) + 1);
    strcpy(aux->dados, pal);
    if(l->inicio == NULL){
        l->inicio = aux;
        aux->prox = NULL;
    }else{
        elem *aux2 = (elem*) malloc(sizeof(elem));
        aux2 = l->inicio;
        while(aux2->prox != NULL){
            aux2 = aux2->prox;
        }
        aux2->prox = aux;
        aux->prox = NULL;
    }
}

void imprimeLista(lista *l){
    elem *aux = (elem*) malloc(sizeof(elem));
    aux = l->inicio;
    while(aux != NULL){
        printf("%s ", aux->dados);
        aux = aux->prox;
    }
}

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF % TABLE_SIZE);
}

int valorString(char *str){
    int i, valor = 0;
    int tam = strlen(str);
    for(i = 0; i < tam; i++){
        valor = valor + (((int) str[i]) % 32);
    }
    return valor;
}

void insereHash(lista *l, char* pal, int tam){
    int chave = valorString(pal);
    //printf("%d\n", chave);
    int pos = chaveDivisao(chave, tam);
    //printf("%d\n", pos);
    inserirLista(&l[pos], pal);
}

int main(){
    int x, y, z;
    char* pal = (char*) malloc(sizeof(char) * 40);
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    lista *l = (lista*) malloc(sizeof(lista) * y);
    for(int k = 0; k < y; k++){
        l[k].inicio = NULL;
    }
    for(int i = 0; i < x - 2; i++){
        scanf("%s", pal); 
        insereHash(l, pal, y);
    }
    imprimeLista(&l[z]);
   return 0;
}
