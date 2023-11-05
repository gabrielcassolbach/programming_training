#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void);
Arvore* constroi_arv (char c, Arvore *e, Arvore *d);
int verifica_arv_vazia (Arvore *a);
void arv_libera (Arvore* a);

#endif
