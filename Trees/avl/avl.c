#include "avl.h"
 
/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore* a) {
   if(a != NULL)
      return a -> altura;
   return -1;	
}

int atualizar_altura (Arvore *a) {
   return((maior(altura(a->dir), altura(a->esq)) + 1));	
}

/*----------------------*/
int balanceamento (Arvore *a) {
   if(a != NULL)
      return (altura(a -> dir) - altura(a -> esq));
   return 0;
}

/*----------------------*/
Arvore* rotacao_simples_esq (Arvore* a) {
   Arvore* t = a -> dir;
   a -> dir = t -> esq;
   t -> dir = a;
   a -> altura = atualizar_altura(a);
   t -> altura = atualizar_altura(t);
   return t;
}

/*----------------------*/
Arvore* rotacao_simples_dir (Arvore* a) {
   Arvore* t = a -> esq; // ok!
   a -> esq = t -> dir; // oK!
   t -> dir = a; // ok!
   a -> altura = atualizar_altura(a); // ok!
   t -> altura = atualizar_altura(t); // ok!
   return t; // ok!
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a) {  
   a -> dir = rotacao_simples_dir (a -> dir); // ok!
   return rotacao_simples_esq (a); // ok!
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a) {
   a -> esq = rotacao_dupla_esq(a -> esq); // ok! 
   return rotacao_simples_dir(a); // ok!  
}

/*----------------------*/
Arvore* atualizar_fb_dir (Arvore *a) {
   a -> altura = atualizar_altura(a);
   if(balanceamento(a) == 2){
      if(balanceamento(a -> dir) >= 0)
         a = rotacao_simples_esq(a);
      else
         a = rotacao_dupla_esq(a);
   }
   return a;
}

/*----------------------*/
Arvore* atualizar_fb_esq (Arvore *a) {
   a -> altura = atualizar_altura(a);
   if(balanceamento(a) == -2){
      if(balanceamento(a -> esq) <= 0)
         a = rotacao_simples_dir(a);
      else 
         a = rotacao_dupla_dir(a);
   }
   return a;
}

/*----------------------*/
Arvore* inserir (Arvore *a, char chave) {
   if(a == NULL){
      a = (Arvore*) malloc (sizeof(Arvore));
      a -> chave = chave;
      a -> altura = 0;
      a -> esq = a -> dir = NULL;
   }else if(chave < a -> chave){
      a -> esq = inserir(a -> esq, chave);
      a = atualizar_fb_esq(a);
   }else{
      a -> dir = inserir(a -> dir, chave);
      a = atualizar_fb_dir(a);
   }
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore* remover (Arvore *a, char chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      if (chave < a->chave) {
         a->esq = remover (a->esq, chave);
         a = atualizar_fb_dir (a);
      }
      else if (chave > a->chave) {
         a->dir = remover (a->dir, chave);
         a = atualizar_fb_esq (a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free (a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No *tmp = a;
            a = a->dir;
            free (tmp);
         }
         else if (a->dir == NULL) {
            No *tmp = a;
            a = a->esq;
            free (tmp);
         }
         else {
            No *tmp = a->esq;
            while (tmp->dir != NULL) {
               tmp = tmp->dir;
            }
            a->chave = tmp->chave; 
            tmp->chave = chave;
            a->esq = remover (a->esq, chave); 
            a = atualizar_fb_dir (a);
         }
      }
      return a; 
   }   
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}

