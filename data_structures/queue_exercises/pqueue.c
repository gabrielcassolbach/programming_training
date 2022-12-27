#include "pqueue.h"

/*Função que cria e inicializa uma fila de tamanho {size}.*/
Queue *create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->frente = 0;
  q->fim = 0;
  q->tam = size;
  q->vetor = (point *)malloc(size * sizeof(point));
  return q;
}

/*Função para enfileirar {elem} na fila {q}.*/
void enqueue (Queue *q, point elem) {
  if (full(q)) {
    printf ("error: queue overflow!\n");
    exit(1);
  }
  q->vetor[q->fim] = elem;
  q->fim = (q->fim + 1) % q->tam;
}

/*Função para desenfileirar o primeiro elemento da fila {q}.*/
point dequeue (Queue *q) {
  if (vazia(q)) {
    printf ("error: queue underflow!\n");
    exit(1);
  }
  point e = q->vetor[q->frente];
  q->frente = (q->frente + 1) % q->tam;
  return e;
}

/*Função que retorna mas não remove o primeiro elemento de {q}.*/
point frente (Queue *q) {
  if (!vazia(q))
    return q->vetor[q->frente];
}

/*Função que verifica se a fila {q} está vazia (true) ou não {false}.*/
int vazia (Queue *q) {
  return (q->frente == q->fim);
}

/*Função que verifica se a fila {q} está cheia (true) ou não {false}.*/
int full (Queue *q) {
  return (q->frente == ((q->fim + 1) % q->tam));
}

/*Função que desaloca as estruturas de uma fila {q}.*/
void destroy (Queue *q) {
  free (q->vetor);
  free (q);
}

/*Função que retorna o número de elementos alocados no array*/
int getsize (Queue *q) {
  return q->tam;
}
