#include "stack.h"

/*Fun��o que cria e inicializa uma pilha de tamanho {size}.*/
Stack *create (int tam) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->topo = 0;
  s->tam = tam;
  s->vetor = (char *)malloc(tam * sizeof(char));
  return s;
}

/*Fun��o para empilhar {elem} na pilha {s}.*/
void push (Stack *s, int elem) {
  if (full(s)) {
    printf ("error: stack overflow!\n");
    exit(1);
  }
  s->vetor[s->topo] = elem;
  s->topo++;
}

/*Fun��o para desempilhar o elemento no topo da pilha {s}.*/
int pop (Stack *s) {
  if (vazia(s)) {
    printf ("error: stack underflow!\n");
    exit(1);
  }
  s->topo--;
  return s->vetor[s->topo];
}

/*Fun��o que retorna mas n�o remove o primeiro elemento de {s}.*/
int get_peek (Stack *s) {
  if (!vazia(s))
    return s->vetor[s->topo-1];
  else
    return ERROR;
}

/*Fun��o que verifica se a pilha {q} est� vazia (true) ou n�o {false}.*/
int vazia (Stack *s) {
  return (s->topo == 0);
}

/*Fun��o que verifica se a pilha {q} est� cheia (true) ou n�o {false}.*/
int full (Stack *s) {
  return (s->topo == s->tam);
}

/*Fun��o que imprime uma pilha {s}.*/
void print (Stack *s) {
  int i;
  printf("Stack: ");
  for (i = s->topo-1; i >= 0; i--) {
    printf ("%c ", s->vetor[i]);
  }
  printf("\n");
}

void print2 (Stack *s){
    int i;
    printf("Stack: ");
    for (i = 0; i <= s->topo-1; i++) {
        printf ("%c ", s->vetor[i]);
    }
    printf("\n");
}

/*Fun��o que desaloca as estruturas de uma pilha {s}.*/
void destroy (Stack *s) {
  free (s->vetor);
  free (s);
}

/*Fun��o que retorna o n�mero de elementos alocados no array*/
int get_size (Stack *s) {
  return s->tam;
}
