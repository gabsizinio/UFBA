#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct fila fila;

struct elemento{
    int dados;
    struct elemento *prox;
};
typedef struct elemento elem;

fila* cria_fila(){
    fila* fi = (fila*) malloc(sizeof(fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void libera_fila(fila* fi){
    if(fi != NULL){
        elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(fila* fi){
    if(fi == NULL) return 0;
    int cont = 0;
    elem* no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_vazia(fila* fi){
    if(fi == NULL) return 1;
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;         
}

int insere_fila(fila* fi, int al){
    if(fi == NULL) return 0;
    elem *no = (elem*) malloc(sizeof(elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;
    }else{
        fi->final->prox = no;
    }
    fi->final = no;
    return 1;
}

int remove_fila(fila* fi){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL){
        return 0;
    }
    elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->final = NULL;
    }
    free(no);
    return 1;
}

void imprime_fila(fila *fi){
    elem* no = fi->inicio;
    while(no != NULL){
        printf("%d ", no->dados);
        no = no->prox;
    }
    printf("\n");
}


typedef struct elemento* pilha;

int * getElements(char *line, int *tamanho){
	int *elementos = (int *) malloc (0*sizeof(int));
	int i = 0;
	
	char* token = strtok(line, " ");
	while (token) {
		i += 1;
		elementos = (int *) realloc (elementos, sizeof(int)*i);
		elementos[i-1] = atoi(token);
		token = strtok(NULL, " ");
        }

	*tamanho = i;
	free(token);
	return (elementos);

}

pilha* cria_pilha(){
    pilha* pi = (pilha*) malloc(sizeof(pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void libera_pilha(pilha* pi){
    if(pi != NULL){
        elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanho_pilha(pilha* pi){
    if(pi == NULL){
        return 0;
    }
    int cont = 0;
    elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int pilha_vazia(pilha* pi){
    if(pi == NULL){
        return 1;
    }
    if(*pi == NULL){
        return 1;
    }
    return 0;
}

int insere_pilha(pilha* pi, int al){
    if(pi == NULL){ 
        return 0;
    }
     elem *no = (elem*) malloc(sizeof(elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

void imprime_pilha(pilha *pi){
    elem *no = (elem*) malloc(sizeof(elem));
    no = *pi;
    while(no != NULL){
        printf("%d ", no->dados);
        no = no->prox;
    }
    printf("\n");
}

int remove_pilha(pilha* pi){
    if(pi == NULL){ 
        return 0;
    }
    if((*pi) == NULL){
         return 0;
    }
    elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int consulta_topo_pilha(pilha* pi, int *al){
    if(pi == NULL){ 
        return 0;
    }
    if((*pi) == NULL){
         return 0;
    }
    *al = (*pi)->dados;
    return 1;
}

pilha* jojo(pilha *p1, pilha *p2){
    pilha *p3 = cria_pilha();
    for(int i = 0; tamanho_pilha(p1); i++){
        insere_pilha(p3, (*p1)->dados);
        remove_pilha(p1);
    }
    for(int k = 0; tamanho_pilha(p2); k++){
        insere_pilha(p3, (*p2)->dados);
        remove_pilha(p2);
    }
    return p3;
}

void pilha_fila(pilha *p, fila *f){
    for(int i = 0; tamanho_pilha(p); i++){
        insere_fila(f, (*p)->dados);
        remove_pilha(p);
    }
}

fila* intercala(fila *f1, fila *f2){
    fila *f3 = cria_fila();
    elem *no = f1->inicio, *no1 = f2->inicio;
    int aux;
    if(tamanho_fila(f1) >= tamanho_fila(f2)){
        aux = tamanho_fila(f2);
    }else if(tamanho_fila(f1) < tamanho_fila(f2)){
        aux = tamanho_fila(f1);
    }
    for(int i = 0; i < aux; i++){
        insere_fila(f3, no->dados);
        insere_fila(f3, no1->dados);
        no = no->prox;
        no1 = no1->prox;
    }
    if(tamanho_fila(f1) >= tamanho_fila(f2)){
        for(int k = 0; k < tamanho_fila(f1) - aux; k++){
            insere_fila(f3, no->dados);
            no = no->prox;
        }
    }else if(tamanho_fila(f1) < tamanho_fila(f2)){
        for(int ll = 0; ll < tamanho_fila(f2) - aux; ll++){
            insere_fila(f3, no1->dados);
            no1 = no1->prox;
        }
    }
    return f3;
}


int main(){
    pilha **mat = (pilha **) malloc(3 * sizeof(pilha*));
    for(int ll = 0; ll < 3; ll++){
        mat[ll] = cria_pilha();
    }
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	int total_linhas = atoi(line);

	for(int j = 0; j < total_linhas; j++){
	
		int *tamanho = (int *) malloc (1*sizeof(int));

		line = NULL;
		len = 0;
		getline(&line, &len, stdin);
		int* elementos = getElements(line, tamanho);

		for(int i = *tamanho - 1; i >= 0; i--){
			insere_pilha(mat[j], elementos[i]);
		}
		free(elementos);
		free(tamanho);
	}
    imprime_pilha(mat[0]);
    imprime_pilha(mat[1]);
    fila *f1 = cria_fila();
    fila *f2 = cria_fila();
    pilha_fila(mat[0], f1);
    pilha_fila(mat[1], f2);
    imprime_fila(f1);
    imprime_fila(f2);
    fila *f3 = intercala(f1, f2);
    imprime_fila(f3);
    
    libera_fila(f1);
    libera_fila(f2);
    libera_fila(f3);

    for(int l1 = 0; l1 < 3; l1++){
        libera_pilha(mat[l1]);
    }
    free(mat);
    
}
 