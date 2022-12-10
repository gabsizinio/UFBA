#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct elemento{
    int dados;
    struct elemento *prox;
};
typedef struct elemento elem;

typedef struct elemento* lista;

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



int insere_lista_inicio(lista* li, int al){
    elem *no = (elem*) malloc(sizeof(elem));
    no->dados = al;
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

int insere_lista_final(lista* li, int al){
    elem *no = (elem*) malloc(sizeof(elem));
    no->dados = al;
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

int remove_lista(lista* li, int al){
    if((*li) == NULL){
        return 0;
    }
    elem *no = *li;
    if(no->dados == al){
        if(no == no->prox){
            free(no);
            *li = NULL;
            return 1;
        }else{
            elem *ult = *li;
            while(ult->prox != (*li)){
                ult = ult->prox;
            }
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados != al){
        ant = no;
        no = no->prox;
    }
    if(no == *li){
        return 0;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int maior_lista(lista* li){
    elem *no = *li;
    int maior = 0;
    for(int i = 0; i < tamanho_lista(li); i++){
        if(no->dados > maior){
            maior = no->dados;
        }
        no = no->prox;
    }
    return maior;
}

void imprime(lista* li){
    elem *no = *li;
    for(int i = 0; i < tamanho_lista(li); i++){
        printf("%d ", no->dados);
        no = no->prox;
    }
    printf("\n");
}

typedef struct elemento* pilha;

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

int messi(lista *li, pilha *p){
    elem *no = *li, *aux = *li;
    int x, con = 0;
    while(aux->dados != maior_lista(li)){
        aux = aux->prox;
    }
    if(aux->prox == *li){
        insere_pilha(p, maior_lista(li));
        remove_lista(li, maior_lista(li));
    }
    while(lista_vazia(li) != 1){
        x = maior_lista(li);
        printf("%d ", no->dados);
        if(no == *li){
            con++;
        }
        if(no->dados == x){
            if(no->prox == *li){
                con++;
            }
            no = no->prox;
            insere_pilha(p, x);
            remove_lista(li, x);
            continue;
        }else{
        no = no->prox;
        }
    }
    return con;
}

int mbapp(lista *li, pilha *p){
    elem *no = *li;
    int con = 0;
    while(lista_vazia(li) != 1){
        if(tamanho_lista(li) == 1){
            insere_pilha(p, maior_lista(li));
            remove_lista(li, maior_lista(li));
            break;
        }
        if(no == *li){
            con++;
        }
        if(no->prox == *li){
            if(no->dados == maior_lista(li)){
                //printf("%d ", no->dados);
                no = no->prox;
                insere_pilha(p, maior_lista(li));
                remove_lista(li, maior_lista(li));
                continue;
            }else{
                no = no->prox;
                con++;
                while(no->dados != maior_lista(li)){
                    no = no->prox;
                }
                //if(no == *li){
                 //   con--;
                //}
                if(no->prox->prox == *li){
                    no = no->prox;
                }
                no = no->prox;
                insere_pilha(p, maior_lista(li));
                remove_lista(li, maior_lista(li));
                continue;
            }
        }
        no = no->prox;
    }
    return con;
}


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
    pilha *p = cria_pilha();
    int x = mbapp(mat[0], p);
    printf("%d\n", x);
    imprime_pilha(p);

    for(int l1 = 0; l1 < 3; l1++){
        libera_lista(mat[l1]);
    }
    free(mat);

	free(line);


    return 0;
    
}


