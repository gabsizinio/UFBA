#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

#define MAX 100 

struct no{
    int dado;
};
typedef struct no no;

struct arv{
    int qtd;
    int** dados;
};
typedef struct arv arv;

//ok
arv* cria_arv(){
    arv *a;
    a = (arv*) malloc(sizeof(arv));
    if(a != NULL){
        a->qtd = 0;
    }
    a->dados = (int **) malloc(50 * sizeof(int*));
    for(int i = 0; i < 50; i++){
        a->dados[i] = (int*) malloc(sizeof(int*));
    }
    return a;
}


//ok
void apaga(arv *a){
    for(int i = 0; i < 50; i++){
        free(a->dados[i]);
    }
    free(a->dados);
    free(a);
}

int arv_vazia(arv *a){
    if(a->qtd == 0){
        return 1;
    }
    return 0;
}

//ok
int insere(arv *a, int c){
    if(a->qtd < MAX){
        *(a->dados[a->qtd]) = c;
        a->qtd++;
        return 0;
    }else{
        return 1;
    }
}


//ok
void imprime(arv *a){
    int k = 0, l = 0;
    while(k < a->qtd){
        if(a->dados[l] == NULL){
            l++;
            continue;
        }else{
            printf("%d ", *(a->dados[l]));
            l++;
            k++;
        }
    }
    printf("\n");
}

int percorre_nivel(arv *a, int c){
    int k = 0, qtd = 1;
    int exp = 0;
    while(k < a->qtd){
        if(*(a->dados[k]) == c){
            break;
        }else{
            k++;
        }
        if(k == qtd){
            exp++;
            qtd += pow(2, exp);
        }
    }
    if(k == a->qtd){
        return -1;
    }
    return exp;
}

int percorre_altura(arv *a, int c){
    int k = 0, i = 0, con = 0;
    while((2 * k) + 1 < a->qtd){
        k++;
    }
    while(*(a->dados[i]) != c){
        i++;
    }
    while(i < k){
        i = (2 * i) + 1;
        con++;
    }
    return con;
}

int profundidade(arv *a){
    int i = 0, con = 0;
    while(i < a->qtd){
        i = (2 * i) + 1;
        con++;
    }
    return con - 1;
}

int resposta(arv *a, int i1, int i2){
    int res;
    int x, y;
    x = percorre_nivel(a, i1);
    y = percorre_nivel(a, i2);
    if(x == -1 && y != -1){
        res = percorre_altura(a, i2);
        return res;
    }else if(x != -1 && y == -1){
        res = percorre_altura(a, i1);
        return res;
    }else if(x == -1 && y == -1){
        res = profundidade(a);
        return res;
    }
    if(x >= y){
        res = x - y;
    }else{
        res = y - x;
    }
    return res;
}

int main(){
    arv *arvore = cria_arv();
    char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	int total_linhas = atoi(line);

	for(int j = 0; j < 1; j++){
	
		int *tamanho = (int *) malloc (1*sizeof(int));

		line = NULL;
		len = 0;
		getline(&line, &len, stdin);
		int* elementos = getElements(line, tamanho);

		for(int i = 0; i < *tamanho; i++){
			insere(arvore, elementos[i]);
		}
		free(elementos);
		free(tamanho);

	}
    int x, y, z;
    for(int i = 0; i < total_linhas - 1; i++){
        scanf("%d %d", &x, &y);
        z = resposta(arvore, x, y);
        printf("%d\n", z);
    }

    apaga(arvore);
    return 0;

}






