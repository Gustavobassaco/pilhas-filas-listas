#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct{
  int dados;
}Objeto;

typedef struct{
	Objeto *valor ;
	int inicio;
	int final;
	int tamanho;
}FilaEstatica;

void iniciaFila(FilaEstatica *fila){
  fila->valor = (Objeto*) malloc(N*sizeof(Objeto));
  fila->inicio = 0;
  fila->final = -1;
  fila->tamanho = 0;
}

void imprimeFila(FilaEstatica *fila){
  printf("\n Fila Estatica: {");
  for (int i = fila->inicio; i< fila->final+1; i++)
  printf("  %d  ", fila->valor[i].dados );
  printf("}\n");
}

void entraFila(FilaEstatica *fila, int valor){
  fila->final++;
  fila->valor[fila->final].dados = valor;
  fila->tamanho++;
}

bool estaVazia(FilaEstatica *fila){
  return (fila->tamanho == 0);
}

int saiFila(FilaEstatica *fila){
  int valor;
  if (!estaVazia(fila)){
    valor = fila->valor[fila->inicio].dados;
    fila->inicio++;
    fila->tamanho--;
    return valor;
  }else printf("\n Warning: Fila vazia \n");
}

int main(){
  FilaEstatica fila;

  iniciaFila(&fila);

  for (int i = 1; i<11; i++){
    entraFila(&fila, i);
    imprimeFila(&fila);
  }
  printf("\nTamanho fila: %d ", fila.tamanho);
  imprimeFila(&fila);

  int retorno;
  for(int i =0; i<11; i++){
    retorno = saiFila(&fila);
    printf("\nSaiu da Fila: %d \n", retorno );
  }

  return 0;
}
