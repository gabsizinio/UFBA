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
    int cont = 0;
    elem* no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_vazia(fila* fi){
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;         
}

int insere_fila(fila* fi, int al){
    elem *no = (elem*) malloc(sizeof(elem));
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

void imprime(fila *f1){
    elem *no = f1->inicio;
    while(no != NULL){
        printf("%d ", no->dados);
        no = no->prox;
    }
    printf("\n");
}

int consulta(fila *f1, int al){
    elem *no = f1->inicio;
    while(no != NULL && no->dados != al){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    
    return 1;
}

fila* organiza_fila(fila *f1, fila *aux, fila *f2){
    elem *no = f1->inicio;
    fila* res = cria_fila();
    int i = 1;
    while(fila_vazia(f1) != 1){
        no = f1->inicio;
        if((no->dados < 60 && no->dados > 5) && consulta(aux, i) == 0){
            insere_fila(res, no->dados);
            //imprime(res);
            //printf("%d ", no->dados);
            remove_fila(f1);
        }else{
            insere_fila(f2, no->dados);
            //imprime(f2);
            //printf("%d ", no->dados);
            remove_fila(f1);
        }
        i++;
    }
    //printf("chegou aqui");
    return res;
}

/*
-- Usar uma fila para armazenar os índices

-- Remover todos elementos da fila, e inserie em outra
com excessão dos de índice passado, ou dos preferenciais;
a fila nova, será a original sem prioridades e a antiga,
a dos preferenciais

*/

int main(){
    fila **mat = (fila **) malloc(3 * sizeof(fila*));
    for(int ll = 0; ll < 3; ll++){
        mat[ll] = cria_fila();
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
			insere_fila(mat[j], elementos[i]);
		}
		free(elementos);
		free(tamanho);

	}
    fila *f3 = cria_fila();
    mat[0] = organiza_fila(mat[0], mat[1], f3);
    imprime(mat[0]);
    imprime(f3);
    
    
    
    
    /*
    fila *f1 = cria_fila();
    fila *f2 = cria_fila();
    fila *f3 = cria_fila();
    insere_fila(f1, 50);
    insere_fila(f1, 65);
    insere_fila(f1, 30);
    insere_fila(f1, 33);
    insere_fila(f1, 11);
    insere_fila(f1, 3);
    insere_fila(f1, 25);
    insere_fila(f1, 39);
    insere_fila(f1, 17);
    insere_fila(f1, 22);
    insere_fila(f1, 27);
    insere_fila(f1, 26);
    insere_fila(f1, 44);
    insere_fila(f1, 28);
    insere_fila(f1, 53);
    insere_fila(f1, 28);
    insere_fila(f1, 20);
    insere_fila(f1, 70);
    insere_fila(f1, 58);
    insere_fila(f1, 27);
    insere_fila(f1, 33);
    insere_fila(f1, 36);
    insere_fila(f1, 49);
    insere_fila(f1, 17);
    insere_fila(f2, 7);
    insere_fila(f2, 8);
    insere_fila(f2, 14);
    f1 = organiza_fila(f1, f2, f3);
    imprime(f1);
    imprime(f3);
    libera_fila(f1);
    libera_fila(f2);
    libera_fila(f3);
    */
    for(int l1 = 0; l1 < 3; l1++){
        libera_fila(mat[l1]);
    }
    free(f3);
    free(line);
    return 0;
}