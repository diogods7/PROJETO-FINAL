/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
# define QTD 20

struct Node {
  int number;
  struct Node *next;
};

struct Queue {
  Node *head;
  Node *tail;
  int max_items;
  int qty;
};



void inicializacaoFila(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->max_items = 10;
    q->qty = 0;
}


void enfileirar(int dado, Queue *q) {
    
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (q->qty >= q->max_items) {
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
  if (q->qty == q->max_items)
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


void limpabuffer (void) {
    char c;
    while ((c = getchar()) != '\n' );
}

void display (void)
{

    printf("\33[H\33[2J");
    printf("Menu:\n");
    printf("1 - Inserir Nó na fila\n2 - Retirar Nó da fila\n");
    printf("3 - Imprimir Nós da fila\n4 - Buscar Nó na fila\n");
    printf("5 - Quantidade de Nós da fila\n6 - A fila está cheia?\n7 - A fila está vazia?\n");
    printf("8 - Sair\n\n");

}

int main(void) {

  
  setlocale(LC_ALL, "Portuguese");

  char menu;
  int num, opcao;
  
  Queue *q = (Queue*)malloc(sizeof(Queue));
  if(!q) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 

  inicializacaoFila(q);

  do {

    display();
    scanf("%c", &menu);
    limpabuffer();

    switch (menu) {

      case '1':
            printf("\33[H\33[2J");
            printf("\nDigite um número a ser inserido: ");
            scanf("%d",&num);
            limpabuffer();
            enfileirar (num, q);
            break;

        case '2':
            printf("\33[H\33[2J");
            num = desenfileirar(q);
            printf("\n\tValor retirado da pilha: %d", num);
            break;

        case '3':
            printf("\33[H\33[2J");
            imprimeFila(q);
            break;

        case '4':
            printf("\33[H\33[2J");
            printf("\nDigite um número a ser buscado: ");
            scanf("%d",&num);
            limpabuffer();
            buscaElementoNaFila(num, q);
            break;

        case '5':
            printf("\33[H\33[2J");
            num = size(q);
            printf("\n\tQuantidade de Nós: %d", num);
            break;

        case '6':
            printf("\33[H\33[2J");
            is_full(q);
            break;

        case '7':
            printf("\33[H\33[2J");
            is_empty(q);
            break;

        case '8':
            // sair do programa
            break;

        default:
            printf("\nOpção Inválida! Escolha um número entre 1 e 5\n");
        }

        printf("\nPressione 1 (um) para retornar ao menu ou 0 (zero) para sair\n");
        scanf("%d", &opcao);
        limpabuffer();

    } while (opcao != 0);

  free (q);
  return EXIT_SUCCESS;
}*/
