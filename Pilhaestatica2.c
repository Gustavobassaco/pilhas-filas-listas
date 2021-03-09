#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct{
  int numero;
}objeto;

typedef struct{
  objeto vetor[N];
  int topo;
}pilhaEstatica;

void iniciaPilha(pilhaEstatica *pilha){
  pilha->topo = 0;
}

bool estaVazia(pilhaEstatica *pilha){
  return (pilha->topo == 0);
}

bool estaCheia(pilhaEstatica *pilha){
  return (pilha->topo == N);
}

void empilha(pilhaEstatica *pilha, int valor){
  if(!estaCheia(pilha)){
    pilha->vetor[pilha->topo].numero = valor;
    pilha->topo++;
  }else {
    printf("\n Alerta: A pilha esta cheia\n");
  }
}

void desempilha(pilhaEstatica *pilha){
  int valor = 0;
  if(!estaVazia(pilha)){
    valor = pilha->vetor[pilha->topo- 1].numero;
    pilha->topo--;
    printf("\n\n Desempilhado : %d\n", valor);

  }else printf("\n pilha vazia");
}

  void imprimePilha(pilhaEstatica *pilha){
    printf("  Pilha = { ");
    for(int i = pilha->topo - 1; i>-1; i--){
    printf("%d, ", pilha->vetor[i].numero);
  }
  printf("}\n");
}

  int tamanhoPilha(pilhaEstatica *pilha){
    int contador=0;
    for(int i = 0; i<pilha->topo; i++)
    contador++;
    return contador;
  }


int main(){
  pilhaEstatica pilha;

  iniciaPilha(&pilha);
  for(int i = 0; i<100; i = i + 10)
  empilha(&pilha, i);
  imprimePilha(&pilha);
  for(int i =0; i<11; i++)
  desempilha(&pilha);
  imprimePilha(&pilha);

  return 0;
}
