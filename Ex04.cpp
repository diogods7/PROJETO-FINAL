/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD 20

struct Node {
  int number;
  struct Node *next;
};

struct Queue {
  Node *head;
  Node *tail;
  int max_itens;
  int qty;
};


void inicializacaoFila(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->max_itens = 10;
    q->qty = 0;
}


void enfileirar(int dado, Queue *q) {
    
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (q->qty >= q->max_itens) {
    printf("\n\tFila cheia. Não é possível inserir mais nós\n");
    EXIT_FAILURE;
  } else {
    aux->number = dado;
    aux->next = NULL;
    if(q->head == NULL)
        q->head = aux;
    else
        q->tail->next = aux;
    q->tail = aux;
    q->qty++;
    }
}


int desenfileirar(Queue *q) {
  
  Node *aux = q->head;
  int dado;
    
  if(aux == NULL) {
      printf("\n\tFila vazia!\n");
      EXIT_FAILURE;
  } else {
    q->head = aux->next;
    aux->next = NULL;
    dado = aux->number;
    q->qty--;
    free(aux);
    if(q->head == NULL)
      q->tail = NULL;
    return dado;
    }
}

void imprimeFila(Queue *q) {
    
  Node *aux = q->head;

  if(aux == NULL) {
      printf("\n\tFila vazia!\n");
      EXIT_FAILURE;
  } else {
    printf("\n\t\t\tFILA\n");
    printf("  |-INÍCIO\n");
    printf("  v\n");
    printf("[ ");
    while(aux != NULL) {
      printf("%d ", aux->number);
      aux = aux->next;
    }
    printf("]\n");
  }
}


void buscaElementoNaFila(int valor, Queue *q) {
    
  Node *aux = q->head;
  if(aux == NULL) {
      printf("\n\tFila vazia!\n");
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

int size(Queue *q) {
  return q->qty;
}



void is_full(Queue *q) {
  if (q->qty == q->max_itens)
    printf("Is full!");
  else
    printf("Isn't full");
}


void is_empty(Queue *q) {
   if (q->qty == 0)
    printf("Is empty!");
  else
    printf("Isn't empty");
}

void geraValoresParaFila(Queue *q)
{
    int i;
    for(i = 0; i < q->max_itens/2; i++)
    {
        enfileirar(rand() % 101, q);
    }
    ordenaFila(q);
}

void ordenaFila(Queue *q)
{
    int n[q->max_itens], i, qtd;
    qtd = q->qty;

    for(i = 0; i < qtd; i++)
    {
        n[i] = desenfileirar(q);
    }

    selectionsort(n, qtd);

    for(i = 0; i < qtd; i++)
    {
        enfileirar(n[i], q);
    }
}

void selectionsort(int v[],int n) {
  int i, j, max, aux;

  for (i = 0; i < (n - 1); i++) {
    max = i;
    for (j = i+1; j < n; j++) {
      if (v[j] < v[max]) {
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

  Queue *q1 = (Queue*)malloc(sizeof(Queue));
  Queue *q2 = (Queue*)malloc(sizeof(Queue));
  Queue *q3 = (Queue*)malloc(sizeof(Queue));
    
  if(q1 == NULL || q2 == NULL || q3 == NULL)  {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 

  inicializacaoFila(q1);
  geraValoresParaFila(q1);
  printf("1º Fila: \n");
  imprimeFila(q1);

  inicializacaoFila(q2);
  geraValoresParaFila(q2);
  printf("2º Fila: \n");
  imprimeFila(q2);

  inicializacaoFila(q3);
  
  while(q1->head != NULL || q2->head != NULL) {
    if(q1->head == NULL && q2->head != NULL)
      enfileirar(desenfileirar(q2), q3);
    else if(q2->head == NULL && q1->head != NULL)
      enfileirar(desenfileirar(q1), q3);
    else if(q1->head->number < q2->head->number )
      enfileirar(desenfileirar(q1), q3);
    else enfileirar(desenfileirar(q2), q3);
  }
  printf("\n3º Fila: \n");
  imprimeFila(q3);
    return 0;
}*/

