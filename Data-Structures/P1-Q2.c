#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

struct elemento{
    struct elemento *ant;
    int dados;
    struct elemento *prox;
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
        elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
}

int tamanho_lista(lista* li){
    int cont = 0;
    elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(lista* li){
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insere_lista_inicio(lista* li, int al){
    elem* no = (elem*) malloc(sizeof(elem));
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL){
        (*li)->ant = no;
    }
    *li = no;
    return 1;
}

int insere_lista_final(lista* li, int al){
    elem* no = (elem*) malloc(sizeof(elem));
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        no->ant = NULL;
        *li = no;
    }else{
        elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int remove_lista_inicio(lista* li){
    if((*li) == NULL){
        return 0;
    }
    elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL){
        no->prox->ant = NULL;
    }
    free(no);
    return 1;
}

int remove_lista_final(lista* li){
    if((*li) == NULL){
        return 0;
    }
    elem *no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    if(no->ant == NULL){
        *li = no->prox;
    }else{
        no->ant->prox = NULL;
    }
    free(no);
    return 1;
}

int remove_lista(lista* li, int al){
    elem *no = *li;
    while(no != NULL && no->dados != al){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no->ant == NULL){
        *li = no->prox;
    }else{
        no->ant->prox = no->prox;
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}

void imprime(lista *li){
    elem *no = *li;
    while(no != NULL){
        printf("%d ", no->dados);
        no = no->prox;
    }
    printf("\n");
}

lista* busca(lista *l1, lista *l2){
    elem *n1 = *l1;
    elem *n2 = *l2;
    elem *n3;
    lista *l3 = cria_lista();
    while(n2 != NULL){
        if(n2->dados < n1->dados){
            for(;n1 != NULL; n1 = n1->ant){
                insere_lista_final(l3, n1->dados);
                if(n2->dados >= n1->dados){
                    break;
                }
            }
            if(n1 == NULL){
                n1 = *l1;
            }
        }
        else if(n2->dados > n1->dados){
            for(;n1 != NULL; n1 = n1->prox){
                n3 = n1;
                insere_lista_final(l3, n1->dados);
                if(n2->dados <= n1->dados){
                    break;
                }
            }
            if(n1 == NULL){
                n1 = n3;
            }
        }
        else if(n2->dados == n1->dados){
            insere_lista_final(l3, n1->dados);
        }
        n2 = n2->prox;
    }
    return l3;
}

/*
    se n2 < n1 -- n1 esquerda
    se n2 > n1 -- n1 direita
    se n2 = n1 -- para
    se n1 = null -- próximo


*/

int main(){
        lista **mat = (lista **) malloc(3 * sizeof(lista*));
    for(int ll = 0; ll < 3; ll++){
        mat[ll] = cria_lista();
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

		for(int i = 0; i < *tamanho; i++){
			insere_lista_final(mat[j], elementos[i]);
		}
		free(elementos);
		free(tamanho);

	}
    lista *l3 = cria_lista();
    l3 = busca(mat[0], mat[1]);
    imprime(l3);
    for(int l1 = 0; l1 < 3; l1++){
        libera_lista(mat[l1]);
    }
    free(mat);

	free(line);


    return 0;


}

