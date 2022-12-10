#include<stdlib.h>
#include<stdio.h>
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


typedef struct elemento{
    int conteudo;
    struct elemento *prox;
}elemento;

typedef struct lista{
    struct elemento *head;
}lista;

elemento *cria_elemento(int c){
    elemento *e = (elemento *)malloc(sizeof(elemento)); 
    e->conteudo = c;
    e->prox = NULL;
    return e;
}

lista* criar_lista(){
    lista *l = (lista *)malloc(sizeof(lista));
    l->head = NULL;
    return l;
}

void imprime(lista* l){
    elemento *aux = l->head;
    if(aux == NULL){
        printf("Lista vazia\n");
    }else{
        while(aux != NULL){
            printf("%d ", aux->conteudo);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void insere_inicio(lista *l, elemento *e){
    e->prox = l->head;
    l->head = e;
}
void insere_fim(lista *l, elemento *e){
    if(l->head == NULL){
        l->head = e;
    }else{
        elemento *aux = l->head;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = e;
    }
}

void remove_inicio(lista *l){
    if(l->head != NULL){
        elemento *aux = l->head;
        l->head = aux->prox;
        free(aux);
    }
}

void insere_meio_pos(lista *l, elemento *e, int pos){
    int i = 1;
    elemento *ant, *aux = l->head;
    while(i != pos && aux != NULL){
        ant = aux;
        aux = aux->prox;
        i++;
    }
    if(aux == l->head){
        e->prox = l->head;
        l->head = e;      
    }else if(aux == NULL){
        ant->prox = e;
    }else{
        e->prox = aux;
        ant->prox = e;
    }
}

void insere_meio_con(lista *l, elemento *e, int con){
    elemento *aux = l->head;
    while(con != aux->conteudo && aux != NULL){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Elemento nao encontrado\n");
    }else{
        e->prox = aux->prox;
        aux->prox = e;
    }
}
  
void remove_fim(lista *l){
    elemento *ant, *aux = l->head;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = NULL;
    free(aux);
}

void remove_meio(lista* l, int pos){
    elemento *ant, *aux = l->head;
    int i = 0;
    while(i != pos && aux != NULL){
        ant = aux;
        aux = aux->prox;
        i++;
    }
    if(aux == l->head){
        l->head = aux->prox;
        free(aux);
    }else if(aux->prox == NULL){
        ant->prox = NULL;
        free(aux);
    }else{
        ant->prox = aux->prox;
        free(aux);
    }
}

void remove_meio2(lista* l, int al){
    elemento *ant, *aux, *aux2 = l->head;
    while(aux2->conteudo != al){
        aux2 = aux2->prox;
    }
    while(aux2 != NULL){
        aux = aux2->prox;
        while(aux != NULL && aux->conteudo != al){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            return;
        }else if(aux == aux2->prox){
            aux2->prox = aux->prox;

        }else{
            ant->prox = aux->prox;
        }
        free(aux);
        aux2 = aux2->prox;
    }

}

void libera_lista(lista* li){
    elemento *no;
    while(li->head != NULL){
        no = li->head;
        li->head = li->head->prox;
        free(no);
    }
    free(li);
}

int tamanho(lista* li){
    int i = 0;
    elemento *aux =li->head;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

void insere_lista_lista(lista *l, lista* l2, int pos){
    int i = pos + 1;
    elemento *aux2 = l2->head;
    while(aux2 != NULL){
        insere_meio_pos(l, cria_elemento(aux2->conteudo), i);
        aux2 = aux2->prox;
        i++;
    }
}

void elimina_repetidos(lista* l){    
    elemento *ant = l->head, *aux = l->head->prox, *aux2 = l->head, *aux3;
    while(ant != NULL){
        while(aux != NULL && aux->conteudo != ant->conteudo){
            aux2 = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            ant = ant->prox;
            if(ant != NULL){
                aux = ant->prox;
            }
        }else if(ant->conteudo == aux->conteudo){
            aux2->prox = aux->prox;
            aux3 = aux;
            aux = aux->prox;
            free(aux3);

        }
    }
}

void neymar(lista *n){
    elemento *no = n->head, *aux;
    for(;no != NULL; no = no->prox){
        aux = no->prox;
        while(aux != NULL){
            if(no->conteudo == aux->conteudo){
                remove_meio2(n, no->conteudo);
                break;
            }
            aux = aux->prox;
        }
    }
}

int main(){
    lista **mat = (lista **) malloc(3 * sizeof(lista*));
    for(int ll = 0; ll < 3; ll++){
        mat[ll] = criar_lista();
    }

	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	int total_linhas = atoi(line) - 1;

	for(int j = 0; j < total_linhas; j++){
	
		int *tamanho = (int *) malloc (1*sizeof(int));

		line = NULL;
		len = 0;
		getline(&line, &len, stdin);
		int* elementos = getElements(line, tamanho);

		for(int i = 0; i < *tamanho; i++){
			insere_fim(mat[j], cria_elemento(elementos[i]));
		}
		free(elementos);
		free(tamanho);

	}
    int x;
    scanf("%d", &x);
    insere_lista_lista(mat[0], mat[1], x);
    imprime(mat[0]);
    neymar(mat[0]);
    neymar(mat[0]);
    imprime(mat[0]);
    for(int l1 = 0; l1 < 3; l1++){
        libera_lista(mat[l1]);
    }
    free(mat);

	free(line);

	return 0;
 
}