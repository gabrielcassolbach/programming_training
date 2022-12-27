#ifndef _queue_h_
#define _queue_h_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*Estrutura e interface para implementar um fila circular:*/

#define ERROR -INT_MAX

typedef struct {
  int frente;
  int fim;
  int tam;
  int* vetor;
} Queue;

/*Interface:*/
Queue *create (int tam);
void destroy (Queue *q);
void enqueue (Queue *q, int elem);
int dequeue (Queue *q);
int frente (Queue *q);
int vazia (Queue *q);
int full (Queue *q);
void print (Queue *q);
int getsize (Queue *q);
int procure (Queue *q, int e);
int maior(Queue* q);
#endif
