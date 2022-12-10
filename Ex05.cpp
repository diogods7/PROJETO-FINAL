#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//--PILHA--//

#define QTDP 10
struct Node {
  int number;
  struct Node *next;
};

struct Stack {
  Node *top;
  int max_itens;
  int qty;
};


void inicializacaoPilha(Stack *s) {
    s->top = NULL;
    s->max_itens = QTDP;
    s->qty = 0;
}


void empilhar(int dado, Stack *s) {
  
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (s->qty >= s->max_itens) {
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
    printf("]\n");
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

    int n = rand() % 100;
    while(n != 0) {
      empilhar(n, s);
      n = rand() % 100;
    }
  }

//--PILHA--//

//--FILA--//


#define QTDPF 70

struct Nodeq {
  int number;
  struct Nodeq *next;
};

struct Queue {
  Nodeq *head;
  Nodeq *tail;
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
    
  Nodeq *aux = (Nodeq*) malloc(sizeof(Nodeq));
  
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
  
  Nodeq *aux = q->head;
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
    
  Nodeq *aux = q->head;

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
    
  Nodeq *aux = q->head;
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



int sizeq(Queue *q) {
  return q->qty;
}



void is_fullq(Queue *q) {
  if (q->qty == q->max_itens)
    printf("Is full!");
  else
    printf("Isn't full");
}


void is_emptyq(Queue *q) {
   if (q->qty == 0)
    printf("Is empty!");
  else
    printf("Isn't empty");
}

//--FILA--//



int main() {
    
  setlocale(LC_ALL, "Portuguese");

  Stack *s1 = (Stack*)malloc(sizeof(Stack));
  Queue *q1 = (Queue*)malloc(sizeof(Queue));
  Queue *q2 = (Queue*)malloc(sizeof(Queue));
    
  if(s1 == NULL || q1 == NULL || q2 == NULL) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  }

  int n;

  inicializacaoPilha(s1);
  geraValoresParaPilha(s1);
  printf("\t\tPILHA\n");
  imprimePilha(s1);

  inicializacaoFila(q1);
  inicializacaoFila(q2);
        
  while(s1->top != NULL) {

    n = desempilhar(s1);
    if(n % 2 == 0)
      enfileirar(n, q1);
    else enfileirar(n, q2);
  }
  
  printf("\n\t\t1º FILA - PARES\n");
  imprimeFila(q1);
  printf("\n\t\t2º FILA - IMPARES\n");
  imprimeFila(q2);
  
  return 0;
}
