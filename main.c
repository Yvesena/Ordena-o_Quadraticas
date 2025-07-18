#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 #define TAM_MAX 50

typedef struct Lista {
  char name[TAM_MAX];
  struct Lista *prox; 
}Lista;

// Função para criar um novo nó
Lista *criar_no(const char nome[]) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));//separa um local na memoria
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strncpy(novo->name, nome, TAM_MAX);//copia o nome passado
    novo->name[TAM_MAX - 1] = '\0'; // Garantir terminação nula
    novo->prox = NULL;
    return novo;
}

// Insere no início da lista
Lista *inserir_no_inicio(Lista *lista, const char nome[]) {
    Lista *novo = criar_no(nome);
    novo->prox = lista;
    return novo;
}
//Deletar
Lista *deletar_elemento(Lista *lista, const char nome[]) {
    Lista *atual = lista;
    Lista *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->name, nome) == 0) {
            // Achou o elemento a remover
            if (anterior == NULL) {
                // É o primeiro elemento
                Lista *temp = atual->prox;
                free(atual);
                return temp;
            } else {
                 //caso ele nao for o primeiro
                anterior->prox = atual->prox;
                free(atual);
                return lista;
            }
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Elemento '%s' não encontrado.\n", nome);
    return lista;
}
 //imprimir
void imprimir(Lista *lista) {
    Lista *aux = lista;
    printf("Lista:\n");
    while (aux != NULL) {
        printf("- %s\n", aux->name);
        aux = aux->prox;
    }
}
// Libera a memória da lista
void liberar(Lista *lista) {
    Lista *atual = lista;
    while (atual != NULL) {
        Lista *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    Lista *lista = NULL; // Ponteiro para a lista (inicialmente vazia)

    lista = inserir_no_inicio(lista, "Carlos");
    lista = inserir_no_inicio(lista, "Ana");
    lista = inserir_no_inicio(lista, "Beatriz");
    lista = inserir_no_inicio(lista, "Diego");

    imprimir(lista);

    liberar(lista); // Liberar memória no final
    return 0;
}



/*int main(){

  char string1[50] , string2[50];

    fgets(string1, sizeof(string1), stdin);
    printf("\n");
    fgets(string2, sizeof(string2), stdin);
    
    int i , j , cont = 0;
   int tam1 = strlen(string1)-1; 
   int tam2 = strlen(string2)-1;
      for(i = 0 ; i < tam1 ; i++){
           for(j = 0 ; j < tam2 ; j++){
            if(string1[i]==string2[j]){
                cont++;
                string2[j] = ' ';
            }
           }      
      }
      if(cont == 0){
        printf("Nao tem letras iguais");
      }else{
        printf(" %d",cont);
      }
}*/