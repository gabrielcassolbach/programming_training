#include "queue.h"

/*Função que cria e inicializa uma fila de tamanho {size}.*/
Queue *create (int tam) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->frente = 0;
  q->fim = 0;
  q->tam = tam;
  q->vetor = (int *)malloc(tam * sizeof(int));
  return q;
}

/*Função para enfileirar {elem} na fila {q}.*/
void enqueue (Queue *q, int elem) {
  if (full(q)) {
    printf ("error: queue overflow!\n");
    exit(1);
  }
  q->vetor[q->fim] = elem;
  q->fim = (q->fim + 1) % q->tam;
}

/*Função para desenfileirar o primeiro elemento da fila {q}.*/
int dequeue (Queue *q) {
  if (vazia(q)) {
    printf ("error: queue underflow!\n");
    exit(1);
  }
  int e = q->vetor[q->frente];
  q->frente = (q->frente + 1) % q->tam;
  return e;
}

/*Função que retorna mas não remove o primeiro elemento de {q}.*/
int frente (Queue *q) {
  if (!vazia(q))
    return q->vetor[q->frente];
  else
    return ERROR;
}

/*Função que verifica se a fila {q} está vazia (true) ou não {false}.*/
int vazia (Queue *q) {
  return (q->frente == q->fim);
}

/*Função que verifica se a fila {q} está cheia (true) ou não {false}.*/
int full (Queue *q) {
  return (q->frente == ((q->fim + 1) % q->tam));
}

/*Função que imprime uma fila {q}.*/
void print (Queue *q) {
  int i;
  printf("Queue: ");
  for (i = q->frente; i != q->fim; i = (i+1) % q->tam) {
    printf ("%d ", q->vetor[i]);
  }
  printf("\n");
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

/*Função que retorna {true} se o elemento {e} existe em {q}*/
int procure (Queue *q, int e) {
  int i;
  for (i = q->frente; i != q->fim; i = (i+1) % q->tam)
    if (q->vetor[i] == e)
      return 1;
  return 0;
}

/*Funçao que retorna o maior valor da Fila*/
int maior(Queue* q){
    int maior = q -> frente;
    for (int i = q->frente; i != q->fim; i = (i+1) % q->tam){
        if (q -> vetor[i] > maior)
            maior = q -> vetor[i];
    }
    return maior;
}
