/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
# define QTD 20

typedef struct Node {
  int number;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
  int max_itens;
  int qty;
} Stack;


void inicializacaoPilha(Stack *s) {
    s->top = NULL;
    s->max_itens = QTD;
    s->qty = 0;
}


void empilhar(int dado, Stack *s) {
  
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (s->qty >= s->max_itens) {
    printf("\n\tPilha cheia. Não é possível inserir mais nós\n");
    EXIT_FAILURE;
  } else {
    aux->number = dado;
    aux->next = s->top;
    s->top = aux;
    s->qty ++;
    }
}


int desempilhar(Stack *s) {

  Node* aux = s->top;
  int dado;
    
  if(aux == NULL) {
    printf("\n\tPilha Vazia\n");
    EXIT_FAILURE;
  } else {
    s->top = aux->next;
    aux->next = NULL;
    dado = aux->number;
    s->qty --;
    free(aux);
  }
  return dado;
}



void imprimePilha(Stack *s){

  Node *aux = s->top;
  if(aux == NULL) {
    printf("\n\tPilha Vazia\n");
    EXIT_FAILURE;
  } else {
    printf("\n\t\t\tPILHA\n");
    printf("  |-TOPO\n");
    printf("  v\n");
    printf("[ ");
    while(aux != NULL) {
      printf("%d ", aux->number);
      aux = aux->next;
    }
    printf("]\n\n\n");
    }
}


void buscaElementoNaPilha(int valor, Stack *s) {
  
  Node *aux = s->top;
  
  if(aux == NULL) {
    printf("\n\tPilha Vazia\n");
    EXIT_FAILURE;
  } else {
    while(aux != NULL) {
      if(aux->number == valor) {
        printf("\n\tValor %d encontrado!!\n", valor);
        return;
      }
      aux = aux->next;
    }
    printf("\n\tValor %d NÃO encontrado!!\n", valor);
  }
}


int size(Stack *s) {
    
  return s->qty;
}


void is_full(Stack *s) {
  if (s->qty == s->max_itens)
    printf("Is full!");
  else
    printf("Isn't full");
  }


void is_empty(Stack *s) {
  if (s->qty == 0)
    printf("Is empty!");
  else
    printf("Isn't empty");
  }

void geraValoresParaPilha(Stack *s) {
    
  int i;
  for(i = 0; i < s->max_itens/2; i++)
    empilhar(rand() % 101, s);
  ordenaPilha(s);
}

void ordenaPilha(Stack *s)
{
    int n[s->max_itens], i, qtd;
    qtd = s->qty;

    for(i = 0; i < qtd; i++) 
      n[i] = desempilhar(s);
    
    selectionsort(n, qtd);

    for(i = 0; i < qtd; i++)
      empilhar(n[i], s);
    
}

void selectionsort(int v[],int n) {
  int i, j, max, aux;

  for (i = 0; i < (n - 1); i++) {
    max = i;
    for (j = i+1; j < n; j++) {
      if (v[j] > v[max]) {
        max = j;
      }
    }
    if (i != max) {
      aux = v[i];
      v[i] = v[max];
      v[max] = aux;
    }
  }
}




int main() {

  setlocale(LC_ALL, "");

  Stack *s1 = (Stack*)malloc(sizeof(Stack));
  Stack *s2 = (Stack*)malloc(sizeof(Stack));
  Stack *s3 = (Stack*)malloc(sizeof(Stack));

  if(s1 == NULL || s2 == NULL || s3 == NULL){
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 
  
  inicializacaoPilha(s1);
  geraValoresParaPilha(s1);
  printf("1º Pilha: \n");
  imprimePilha(s1);

  inicializacaoPilha(s2);
  geraValoresParaPilha(s2);
  printf("2º Pilha: \n");
  imprimePilha(s2);

  inicializacaoPilha(s3);
  while(s1->top != NULL || s2->top != NULL) {
    if(s1->top == NULL && s2->top != NULL)
      empilhar(desempilhar(s2), s3);
    else if(s2->top == NULL && s1->top != NULL)
      empilhar(desempilhar(s1), s3);
    else if(s1->top->number < s2->top->number )
      empilhar(desempilhar(s1), s3);
    else empilhar(desempilhar(s2), s3);
  }
  printf("\n3º Pilha: \n");
  imprimePilha(s3);
  return 0;
}
*/
