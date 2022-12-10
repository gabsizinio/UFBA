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
    if((*pi) == NULL){
         return 0;
    }
    *al = (*pi)->dados;
    return (*pi)->dados;
}


void A_para_B(pilha *p1, pilha* p2){
    if((*p1) == NULL){
        insere_pilha(p1, (*p2)->dados);
        remove_pilha(p2);
    }else if((*p2) == NULL){
        insere_pilha(p2, (*p1)->dados);
        remove_pilha(p1);
    }else if((*p1)->dados < (*p2)->dados){
        insere_pilha(p2, (*p1)->dados);
        remove_pilha(p1);
    }else if((*p2)->dados < (*p1)->dados){
        insere_pilha(p1, (*p2)->dados);
        remove_pilha(p2);
    }
}

void A_para_C(pilha *p1, pilha *p3){
    if((*p1) == NULL){
        insere_pilha(p1, (*p3)->dados);
        remove_pilha(p3);
    }else if((*p3) == NULL){
        insere_pilha(p3, (*p1)->dados);
        remove_pilha(p1);
    }else if((*p1)->dados < (*p3)->dados){
        insere_pilha(p3, (*p1)->dados);
        remove_pilha(p1);
    }else if((*p3)->dados < (*p1)->dados){
        insere_pilha(p1, (*p3)->dados);
        remove_pilha(p3);
    }
}

void B_para_C(pilha *p2, pilha *p3){
    if((*p3) == NULL){
        insere_pilha(p3, (*p2)->dados);
        remove_pilha(p2);
    }else if((*p2) == NULL){
        insere_pilha(p2, (*p3)->dados);
        remove_pilha(p3);
    }else if((*p3)->dados < (*p2)->dados){
        insere_pilha(p2, (*p3)->dados);
        remove_pilha(p3);
    }else if((*p2)->dados < (*p3)->dados){
        insere_pilha(p3, (*p2)->dados);
        remove_pilha(p2);
    }
}

int funcao(pilha *p1){
    pilha *p2 = cria_pilha();
    pilha *p3 = cria_pilha();
    int x = tamanho_pilha(p1), con = 0;
    if(x % 2 == 0){ 
        while(tamanho_pilha(p3) < x){
            A_para_B(p1, p2);
            con++;
            if(tamanho_pilha(p3) == x){
                break;
            }
            A_para_C(p1, p3);
            con++;
            if(tamanho_pilha(p3) == x){
                break;
            }
            B_para_C(p2, p3);
            con++;
        }
    }else{
        while(tamanho_pilha(p3) < x){
            A_para_C(p1, p3);
            con++;
            if(tamanho_pilha(p3) == x){
                break;
            }
            A_para_B(p1, p2);
            con++;
            if(tamanho_pilha(p3) == x){
                break;
            }
            B_para_C(p2, p3);
            con++;
        }
    }
    return con;
}


