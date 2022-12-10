/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
# define qtd 20

struct Node {
  int number;
  struct Node *next;
};

struct Stack {
  Node *top;
  int max_items;
  int qty;
};


void inicializacaoPilha(Stack *s) {
    s->top = NULL;
    s->max_items = qtd;
    s->qty = 0;
}


void empilhar(int dado, Stack *s) {
  
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (s->qty >= s->max_items) {
    printf("\n\tPilha cheia. Não é possível inserir mais nós\n");
    EXIT_FAILURE;
  } else {
    aux->number = dado;
    aux->next = s->top;
    s->top = aux;
    s->qty ++;
    printf("\n\tInserção feito com sucesso.\n");
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
,

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
  if (s->qty == s->max_items)
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

void limpabuffer (void) {
    char c;
    while ((c = getchar()) != '\n' );
}

void display (void)
{

    printf("\33[H\33[2J");
    printf("Menu:\n");
    printf("1 - Inserir Nó na pilha\n2 - Retirar Nó da Pilha\n");
    printf("3 - Imprimir Nós da pilha\n4 - Buscar Nó na pilha\n");
    printf("5 - Quantidade de Nós da Pilha\n6 - A pilha está cheia?\n7 - A pilha está vazia?\n");
    printf("8 - Sair\n\n");

}

int main(void) {

  
  setlocale(LC_ALL, "Portuguese");

  char menu;
  int num, opcao;
  
  Stack *s = (Stack*)malloc(sizeof(Stack));
  if(!s) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 

  inicializacaoPilha(s);

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
            empilhar (num, s);
            break;

        case '2':
            printf("\33[H\33[2J");
            num = desempilhar(s);
            printf("\n\tValor retirado da pilha: %d", num);
            break;

        case '3':
            printf("\33[H\33[2J");
            imprimePilha(s);
            break;

        case '4':
            printf("\33[H\33[2J");
            printf("\nDigite um número a ser buscado: ");
            scanf("%d",&num);
            limpabuffer();
            buscaElementoNaPilha(num, s);
            break;

        case '5':
            printf("\33[H\33[2J");
            num = size(s);
            printf("\n\tQuantidade de Nós: %d", num);
            break;

        case '6':
            printf("\33[H\33[2J");
            is_full(s);
            break;

        case '7':
            printf("\33[H\33[2J");
            is_empty(s);
            break;

        case '8':
            break;

        default:
            printf("\nOpção Inválida! Escolha um número entre 1 e 5\n");
        }

        printf("\nPressione 1 (um) para retornar ao menu ou 0 (zero) para sair\n");
        scanf("%d", &opcao);
        limpabuffer();

    } while (opcao != 0);

  free (s);
  return EXIT_SUCCESS;
}
*/