#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    int dados;
    struct elemento *prox;
};
typedef struct elemento elem;

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

void imprime(pilha *pi){
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

void imprime2(pilha *pi){
    elem *no = (elem*) malloc(sizeof(elem));
    no = *pi;
    while(no != NULL){
        printf("%d\n", no->dados);
        no = no->prox;
    }
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
    pilha *p3 = cria_pilha();
    p3 = jojo(mat[0], mat[1]);
    imprime2(p3);
}
 