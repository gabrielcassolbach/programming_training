#ifndef _stack_h_
#define _stack_h_
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*Estrutura e interface para implementar
  uma pilha com array (ou vetor):*/

#define ERROR -INT_MAX

typedef struct {
  int topo;
  int tam;
  char* vetor;
} Stack;

/*Interface:*/
Stack *create (int tam);
void destroy (Stack *s);
void push (Stack *s, int elem);
int pop (Stack *s);
int get_peek (Stack *s);
int vazia (Stack *s);
int full (Stack *s);
void print (Stack *s);
void print2 (Stack *s);
int get_size (Stack *s);
#endif

