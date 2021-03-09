#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct No{
  int valor;
  struct No *proximo;
};

typedef struct{
  struct No *topo;
  int tamanho;
}PilhaDinamica;

void iniciaPilha(PilhaDinamica *p){
  p->topo = NULL;
  p->tamanho = 0;
}

int tamanhoPilha(PilhaDinamica *p){
  return p->tamanho;
}

bool estaVazia(PilhaDinamica *p){
  return (p->tamanho == 0);
}

void empilha(PilhaDinamica *p, int valor){
  struct No* Aux = (struct No*) malloc(sizeof(struct No));
  Aux->valor = valor;
  Aux->proximo = p->topo;
  p->topo = Aux;
  p->tamanho++;
}

int desempilha(PilhaDinamica *p){
  int retorna= -1;
  if(!estaVazia(p)){
    struct No* Aux;
    Aux = p->topo;
    retorna = Aux->valor;
    p->topo = p->topo->proximo;
    p->tamanho--;
    free(Aux);
    return retorna;
  }else printf("\n A pilha esta vazia!");
}

void imprime(PilhaDinamica *p){
  printf("\n Pilha= {");
  for(struct No* temp = p->topo; temp != NULL; temp = temp->proximo)
    printf("  %d ", temp->valor );
  printf("}\n");
}


int main(){
  PilhaDinamica pilha;
  iniciaPilha(&pilha);
  printf("\n Tamanho da pilha: %d", pilha.tamanho);

  for(int i =0 ; i<100; i+= 8)
  empilha(&pilha, i);

  imprime(&pilha);
  int retorno = desempilha(&pilha);
  printf("\n Desempilhado: %d", retorno);

  imprime(&pilha);

  return 0;
}
