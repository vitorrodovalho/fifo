#include <stdio.h>
#include <stdlib.h>

//Estrutura base da lista.
struct lista{ 
    int dado; // Valor inserido na lista
    struct lista *ponteiro; // Ponteiro que faz a ligacao do no da lista
};
 
 
//Função pra exibir a lista na tela
void exibeLista(struct lista *lista){
    printf("Lista: |"); 
    if(lista){
        do {
            printf(" %d |", lista->dado);
            lista=lista->ponteiro;
        }
        while(lista);
        printf("\n");
	}
    else {
        printf("Lista vazia.");
    }
}

//Função pra exibir a lista na tela
int contagemItens(struct lista *lista){
    int cont = 0;

    if(lista){
        do {
            lista=lista->ponteiro;
            cont++;
        }
        while(lista);
	}
	return cont;
    
}

int main(void){

	int valor[5], op = 0, tamanhoLista = 0;

	struct lista *N1 = NULL;
    struct lista *N2 = NULL;
    struct lista *N3 = NULL;

	printf("Programa que simula o funcionamento de uma lista (FIFO) de 3 elementos \n");
	
	while(op!=4) {
	printf("1 - Inserir Elementos da Lista\n");
	printf("2 - Remover Elemento da Lista\n");
	printf("3 - Exibir Lista\n");
	printf("4 - Sair\n");
	scanf("%d",&op);

		switch (op){
			case 1: {

				//Lendo o valor de elemento e armazenando na lista
				printf("Digite o valor do 1 elmento\n");
				scanf("%d",&valor[0]);
			    N1 = (struct lista*) malloc(sizeof(struct lista*));
			    N1->dado = valor[0];
			    
			    printf("Digite o valor do 2 elmento\n");
				scanf("%d",&valor[1]);	
			    N2 = (struct lista*) malloc(sizeof(struct lista*));
			    N2->dado = valor[1];

			    printf("Digite o valor do 3 elmento\n");
				scanf("%d",&valor[2]);				     
			    N3 = (struct lista*) malloc(sizeof(struct lista*));
			    N3->dado = valor[2];
			  			     
			    //Conectando os nós
			    N1->ponteiro = N2;
			    N2->ponteiro = N3;
			   	N3->ponteiro = NULL;

			    break;
			}
			case 2: {
				tamanhoLista = contagemItens(N1);
				if(tamanhoLista==1){
	 				N1->ponteiro = NULL;
				}
				if(tamanhoLista==2){
				    N1->ponteiro = NULL;
				}
				if(tamanhoLista==3){
					N2->ponteiro = NULL;
				}
				break;
			}
			case 3: {
				exibeLista(N1);
				break;
			}
		}
	}
  
  return 0;
}