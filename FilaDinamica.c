#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nofila{
  int valor;
  struct Nofila* proximo;
};

typedef struct{
  struct Nofila* final;
  struct Nofila* inicio;
  int tamanho;
}FilaDinamica;

void iniciaFila(FilaDinamica *fila){
  fila->final = NULL;
  fila->inicio = NULL;
  fila->tamanho = 0;
}

void imprimeFila(FilaDinamica *fila){
   printf("\n Fila = (");
   for(struct Nofila* temp = fila->inicio; temp != NULL; temp = temp->proximo)
     printf("  %d ", temp->valor );
   printf(")\n");
}

void EntraFila(FilaDinamica *fila, int valor){
  struct Nofila* aux = (struct Nofila*) malloc(sizeof(struct Nofila));
  aux->valor = valor;
  if(fila->tamanho == 0){
    fila->inicio = aux;
    fila->final = aux;
  }else{
    aux->proximo = NULL;
    fila->final->proximo = aux;
    fila->final = fila->final->proximo;
  }
  fila->tamanho++;
}

bool estaVazia(FilaDinamica *fila){
  return (fila->tamanho == 0);

}
/*
int saiFila(FilaDinamica *fila){
    struct Nofila *temp = fila->final;
    int retorno;

  if(!estaVazia(fila)){
    while(temp != NULL){
        if(temp->proximo != NULL)
          temp= temp->proximo;
          else {
            retorno = temp->valor;
            free(temp);
        return retorno;
      }
    }
  }
}
*/
int saiFila(FilaDinamica *fila){
  struct Nofila *temp = fila->inicio;
  int retorno;
  if(!estaVazia(fila)){
  retorno = temp->valor;
  fila->inicio = fila->inicio->proximo;
  fila->tamanho--;
  free(temp);
}else printf("\nFila vazia\n");
  return retorno;
}


int main(){

  FilaDinamica fila;
  int saiu;

  iniciaFila(&fila);
  imprimeFila(&fila);
  for(int i = 0; i<10; i++){
    EntraFila(&fila, i);
  }
  imprimeFila(&fila);

  for(int i=0; i<10; i++){
  saiu = saiFila(&fila);
  printf("\nTamanho: %d",fila.tamanho );
  printf("\n Saiu da fila : %d \n", saiu );
  imprimeFila(&fila);

}

return 0;
}
