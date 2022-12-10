#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct elemento{
    int dados;
    struct elemento *prox;
    char* nome;
};
typedef struct elemento elem;

typedef struct elemento* lista;

lista* cria_lista(){
    lista* li = (lista*) malloc(sizeof(lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(lista* li){
    if((*li) != NULL){
        elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho_lista(lista* li){
    if((*li) == NULL){
        return 0;
    }
    int cont = 0;
    elem* no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no != (*li));
    return cont;
}

int lista_vazia(lista* li){
    if((*li) == NULL){
        return 1;
    }else{
        return 0;
    }
}

char* copiar(char* nom){ 
    char *nom2 = (char*) malloc(12);
    char *p1, *p2;
    p1 = nom;
    p2 = nom2;
    while(*p1 != '\0'){
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';
    return nom2;
}

int insere_lista_inicio(lista* li, int al, char* nom){
    elem *no = (elem*) malloc(sizeof(elem));
    no->dados = al;
    no->nome = copiar(nom);
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int insere_lista_final(lista* li, int al, char* nom){
    elem *no = (elem*) malloc(sizeof(elem));
    no->dados = al;
    no->nome = copiar(nom);
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int remove_lista_inicio(lista* li){
    if((*li) == NULL){
        return 0;
    }
    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    elem *atual = *li;
    while(atual->prox != (*li)){
        atual = atual->prox;
    }
    elem *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(lista* li){
    if((*li) == NULL){
        return 0;
    }
    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    elem *ant, *no = *li;
    while(no->prox != (*li)){
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

void imprime(lista* li){
    elem *no = *li;
    for(int i = 0; i < tamanho_lista(li); i++){
        printf("%s %d\n", no->nome, no->dados);
        no = no->prox;
    }
}

char* fmab(lista* li, char* nom){
    elem *no = *li;
    int con = 0, res = 0;
    while(no->prox != *li){
        con = con + no->dados;
        no = no->prox;
    }
    con = con + no->dados;
    no = *li;
    while(strcmp(nom, no->nome) != 0){
        no = no->prox;
    }
    while(res != con){
        res++;
        no = no->prox;
    }
    return no->nome;
}

int main(){
    int x, y;
    lista *li = cria_lista();
    scanf("%d", &x);
    char *n1 = (char*) malloc(12 * sizeof(char));
    char *n2 = (char*) malloc(12 * sizeof(char));
    char *n3 = (char*) malloc(12 * sizeof(char));
    for(int i = 0; i < x - 1; i++){
        scanf("%s", n1);
        scanf("%d", &y);
        insere_lista_final(li, y, n1);
    }    
    scanf("%s", n2);
    n3 = fmab(li, n2);
    printf("%s\n", n3);
    libera_lista(li);
    free(n1);
    free(n2);
    free(n3);

    return 0;
    
}


