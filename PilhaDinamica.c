#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilha *PtrNoPilha;

typedef struct NoPilha{
  int valor;
  PtrNoPilha proximo;
}NoPilha;

typedef struct{
 PtrNoPilha topo;
 int tamanho;
}PilhaDinamica;

void iniciaPilha(PilhaDinamica *pilha){
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

void inserirElemento(PilhaDinamica* pilha, int valor){
  PtrNoPilha aux;
  aux = (PtrNoPilha) malloc(sizeof(PtrNoPilha));
  aux->valor = valor;
  aux->proximo = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}
bool estaVazia(PilhaDinamica *pilha){
  return (pilha->tamanho == 0);
}



int removerElemento(PilhaDinamica* pilha){
    int v = -1;
    if(!estaVazia(pilha)){
    PtrNoPilha p;
    p = pilha->topo;
    v = p->valor;
    pilha->topo = p->proximo;
    pilha->tamanho--;
    free(p);
    return v;
  }else {
    printf("\n Esta vazia \n" );

  }
}

void imprimePilha(PilhaDinamica *pilha){
  printf("\n Pilha = {" );
  for(PtrNoPilha temp = pilha->topo; temp != NULL; temp = temp->proximo ){
    printf("  %d", temp->valor );
  }printf(" }\n");


}
int main(){
  PilhaDinamica pilha;
  int v;
/**
  iniciaPilha(&pilha);
  inserirElemento(&pilha, 5);
  inserirElemento(&pilha, 9);
  inserirElemento(&pilha, 76);
  inserirElemento(&pilha, 1);
  inserirElemento(&pilha, 7);
*/for (int i = 0; i<10; i++){
  printf("\nDigite um numero: \n");
  scanf("%d", &i );
  inserirElemento(&pilha, i);
}
  imprimePilha(&pilha);

  v = removerElemento(&pilha);
  printf("\nDesempilhado: %d \n", v );
  imprimePilha(&pilha);


  estaVazia(&pilha);
  return 0;
}
