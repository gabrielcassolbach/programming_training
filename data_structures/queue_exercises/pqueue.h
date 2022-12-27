#ifndef _queue_h_
#define _queue_h_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*Estrutura e interface para implementar um fila circular:*/

#define ERROR -INT_MAX

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  int frente;
  int fim;
  int tam;
  point* vetor;
} Queue;

/*Interface:*/
Queue *create (int tam);
void destroy (Queue *q);
void enqueue (Queue *q, point elem);
point dequeue (Queue *q);
point frente (Queue *q);
int vazia (Queue *q);
int full (Queue *q);
void print (Queue *q);
int getsize (Queue *q);
#endif
