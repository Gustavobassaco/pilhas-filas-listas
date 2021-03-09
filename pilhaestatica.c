#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXTAM 100



typedef struct {
  int array[MAXTAM];
  int topo;
} pilhaEstatica;

////////////////////////////////////////////////////
void iniciaPilha(pilhaEstatica *pilha) {
  pilha->topo = -1;
}

////////////////////////////////////////////////////
bool estaVazia(pilhaEstatica *pilha) {
  if(pilha->topo == -1)
  return true;
  else return false;
}

////////////////////////////////////////////////////
bool estaCheia(pilhaEstatica *pilha) {
  if(pilha->topo >= MAXTAM ){
  return true;
  }
  else {
  return false;
  }
}

/////////////////////////////////////////////////////
void empilha(int item, pilhaEstatica *pilha) {
  if (estaCheia(pilha) == 1){
    printf("a fila esta cheia no item %d \n", item);
  }
  else{
  pilha->topo++;
  pilha->array[pilha->topo] = item;
  }
}

////////////////////////////////////////////////////
void desempilha(int item, pilhaEstatica *pilha) {
 int aux[MAXTAM];
 int i = 0;
 int fecha = 0;

  while(fecha == 0){

     if(pilha->array[pilha->topo] == item){
       //pilha->array[pilha->topo] = NULL;
       fecha = 1;
       printf("o numero buscado foi %d\n", item);

     }
     else{
       aux[i] = pilha->array[pilha->topo] ;
       i++;

     }
     pilha->topo--;
     if(pilha->topo == -1){
       printf("O numero %d nao esta na pilha.\n", item);
       fecha = 1;
     }
     }

     i--;
     for( i ; i >= 0 ; i--){
       pilha->topo++;
       pilha->array[pilha->topo] = aux[i];
  }
}

////////////////////////////////////////////////////////////
  int tamanhoPilha(pilhaEstatica *pilha) {
    printf(" o tamanho do array é : %d\n", pilha->topo + 1);
  }
////////////////////////////////////////////////////////////
void topo(pilhaEstatica *pilha) {
  printf("\n %d \n", pilha->array[pilha->topo]);
}
///////////////////////////////////////////////////////////
void imprimePilha(pilhaEstatica *pilha) {

if(estaVazia(pilha) == true){
printf("\n{esta vazia}\n");
}
  else {
      for(int i = 0; i <= pilha->topo; i++){
      printf("{%d}\n",  pilha->array[i]);
    }
  }
}
///////////////////////////////////////////////////////////

int main(void){

  int x;
  int escolha = 0;

    pilhaEstatica* pilha = (pilhaEstatica*)malloc(sizeof(pilhaEstatica));
    iniciaPilha(pilha);

  do{
  printf("digite 1 para empilhar:\n");
  printf("digite 2 para desempilhar:\n" );
  printf("digite 3 para saber o tamanho da pilha:\n");
  printf("digite 4 para emprimir a pilha:\n");
  printf("digite 5 para sair do programa: \n");
  scanf("%d",  &escolha);

  switch(escolha){
    case 1:
    printf("digite o valor a ser empilhado : \n");
    scanf("%d", &x );
    empilha(x, pilha);
    break;

    case 2:
    printf("digite o valor para se desempilhar:\n");
    scanf("%d", &x );
    desempilha(x, pilha);
    break;

    case 3:
    tamanhoPilha(pilha);
    break;

    case 4:
    imprimePilha(pilha);
    break;

    default:
    printf("\nOpcao invalida \n");
    break;
  }
}while(escolha != 5);

    free(pilha);
  return 0;
}
